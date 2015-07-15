#include "interpreted_vm.h"
#include "parser.h"
#include <iostream>

byte* InterpretedVM::VmAlloc(uint32 typeId) {
  uint32 compositeSize = GetTypeByteSize(typeId);
  byte* mem = (byte*)malloc(compositeSize);
  VmMemory.push_back(std::unique_ptr<byte>(mem));
  return (byte*)mem;
}

Value InterpretedVM::IndexMemberValue(Value val, uint32 index) {
  return IndexMemberValue(val.TypeId, val.Memory, index);
}

Value InterpretedVM::IndexMemberValue(uint32 typeId, byte* val, uint32 index) {
  Value result;

  SOp compDef = prog.DefinedTypes.at(typeId);
  switch (compDef.Op) {
  case Op::OpTypeVector: {
    auto vec = (STypeVector*)compDef.Memory;
    uint32 offset = GetTypeByteSize(vec->ComponenttypeId) * index;
    result.TypeId = vec->ComponenttypeId;
    result.Memory = val + offset;
    break;
  }
  case Op::OpTypeStruct: {
    auto s = (STypeStruct*)compDef.Memory;
    result.TypeId = s->MembertypeIds[index];
    result.Memory = val;
    for (int i = 0; i < index; i++) {
      result.Memory += GetTypeByteSize(s->MembertypeIds[i]);
    }
    break;
  }
  case Op::OpTypePointer: {
    auto p = (STypePointer*)compDef.Memory;
    result = IndexMemberValue(p->TypeId, (byte*)*(void**)val, index);
    break;
  }
  default:
    result.Memory = nullptr;
    result.TypeId = 0;
    std::cout << "Not a composite type def: " << writeOp(compDef);
  }

  return result;
}

byte* InterpretedVM::GetPointerInComposite(uint32 typeId, byte* composite, uint32 indexCount, uint32* indices, uint32 currLevel = 0) {
  if (currLevel == indexCount) {
    return composite;
  }

  uint32 index = indices[currLevel];
  Value member = IndexMemberValue(typeId, composite, index);
  return GetPointerInComposite(member.TypeId, member.Memory, indexCount, indices, currLevel + 1);
}

SOp InterpretedVM::GetType(uint32 typeId) {
  return prog.DefinedTypes.at(typeId);
}

bool InterpretedVM::IsVectorType(uint32 typeId) {
  return GetType(typeId).Op == Op::OpTypeVector;
}

uint32 InterpretedVM::ElementCount(uint32 typeId) {
  auto def = GetType(typeId);
  switch (def.Op)
  {
  case Op::OpTypeArray: {
    uint32 lengthId = ((STypeArray*)def.Memory)->LengthId;
    return *(uint32*)env.Values.at(lengthId).Memory;
  }
  case Op::OpTypeVector: {
    auto vec = (STypeVector*)def.Memory;
    return vec->Componentcount;
  }
  default:
    return 0;
  }
}

Value InterpretedVM::VmInit(uint32 typeId, void* value) {
  Value val = { typeId, VmAlloc(typeId) };
  if (value) {
    memcpy(val.Memory, value, GetTypeByteSize(val.TypeId));
  } else {
    memset(val.Memory, 0, GetTypeByteSize(val.TypeId));
  }
  return val;
}

Value InterpretedVM::Dereference(Value val) {
  auto def = GetType(val.TypeId);
  if (def.Op != Op::OpTypePointer) {
    return val;
  }

  Value res { ((STypePointer*)def.Memory)->TypeId, (byte*)*(void**)val.Memory };
  return res;
}

template<typename T>
int Cmp(Value op1, Value op2) {
  T a = *(T*)op1.Memory;
  T b = *(T*)op2.Memory;
  return a < b ? -1 : a == b ? 0 : 1;
}

template<typename T>
T Add(Value op1, Value op2) {
  T a = *(T*)op1.Memory;
  T b = *(T*)op2.Memory;
  return a + b;
}

template<typename T>
T Sub(Value op1, Value op2) {
  T a = *(T*)op1.Memory;
  T b = *(T*)op2.Memory;
  return a - b;
}

template<typename T>
T Div(Value op1, Value op2) {
  T a = *(T*)op1.Memory;
  T b = *(T*)op2.Memory;
  return a / b;
}

template<typename T>
T Mul(Value op1, Value op2) {
  T a = *(T*)op1.Memory;
  T b = *(T*)op2.Memory;
  return a * b;
}

template<typename S, typename D>
D Convert(Value op) {
  return (D)*(S*)op.Memory;
}

Value InterpretedVM::TextureSample(Value sampler, Value coord, Value bias, uint32 resultTypeId) {
  STypeSampler* samplerType =(STypeSampler*)GetType(sampler.TypeId).Memory;
  assert(samplerType->Content == 2);
  assert(ElementCount(coord.TypeId) >= samplerType->Dim + samplerType->Arrayed);
  Sampler* s = ((Sampler*)sampler.Memory);
  uint32 index = 0;
  uint32 acc = 1;
  for (int d = 0; d < s->DimCount; d++) {
    uint32 dd = s->Dims[d];
    uint32 add = (uint32)(*(float*)IndexMemberValue(coord, d).Memory * (dd - 1) + 0.5f);
    switch (s->WrapMode) {
    case WrapMode::Clamp: add = add < 0 ? 0 : add > dd - 1 ? dd - 1 : add; break;
    case WrapMode::Repeat: add = add % dd; break;
    }
    index += add * acc;
    acc *= dd;
  }
  return VmInit(resultTypeId, ((float*)s->Data) + index * 4);
}

template<typename Func>
void InterpretedVM::DoOp(uint32 resultTypeId, uint32 resultId, Value op1, Func op) {
  Value val;
  if (IsVectorType(op1.TypeId)) {
    val = VmInit(resultTypeId, 0);
    int elCount = ElementCount(op1.TypeId);
    for (int i = 0; i < elCount; i++) {
      auto result = op(IndexMemberValue(op1, i));
      memcpy(IndexMemberValue(val, i).Memory, &result, GetTypeByteSize(resultTypeId) / elCount);
    }
  } else {
    auto result = op(op1);
    val = VmInit(resultTypeId, &result);
  }
  env.Values[resultId] = val;
}

template<typename Func>
void InterpretedVM::DoOp(uint32 resultTypeId, uint32 resultId, Value op1, Value op2, Func op) {
  Value val;
  if (IsVectorType(op1.TypeId)) {
    val = VmInit(resultTypeId, 0);
    int elCount = ElementCount(op1.TypeId);
    for (int i = 0; i < elCount; i++) {
      auto result = op(IndexMemberValue(op1, i), IndexMemberValue(op2, i));
      memcpy(IndexMemberValue(val, i).Memory, &result, GetTypeByteSize(resultTypeId) / elCount);
    }
  } else {
    auto result = op(op1, op2);
    val = VmInit(resultTypeId, &result);
  }
  env.Values[resultId] = val;
}

uint32 InterpretedVM::Execute(Function* func) {
  prog.CurrentFunction = func;

  int pc = 0;

  for (;;) {
    auto op = func->Ops[pc];
    switch (op.Op) {
    case Op::OpBranch: {
      auto branch = (SBranch*)op.Memory;
      pc = func->Labels.at(branch->TargetLabelId);
      break;
    }
    case Op::OpBranchConditional: {
      auto branch = (SBranchConditional*)op.Memory;
      uint32 labelID;
      Value val = Dereference(env.Values[branch->ConditionId]);
      if (*(bool*)val.Memory) {
        labelID = branch->TrueLabelId;
      } else {
        labelID = branch->FalseLabelId;
      }
      pc = func->Labels.at(labelID);
      break;
    }
    case Op::OpFunctionCall: {
      auto call = (SFunctionCall*)op.Memory;
      Function toCall = prog.FunctionDefinitions.at(call->FunctionId);
      for (int i = 0; i < call->ArgumentIdsCount; i++) {
        env.Values[toCall.Parameters[i].ResultId] = Dereference(env.Values.at(call->ArgumentIds[i]));
      }
      uint32 resultId = Execute(&toCall);
      if (resultId == -1) {
        return -1;
      }
      prog.CurrentFunction = func;
      env.Values[call->ResultId] = env.Values[resultId];
      break;
    }
    case Op::OpConvertSToF: {
      auto convert = (SConvertSToF*)op.Memory;
      Value op1 = Dereference(env.Values[convert->SignedValueId]);
      DoOp(convert->ResultTypeId, convert->ResultId, op1, Convert<int32, float>);
      break;
    }
    case Op::OpFAdd: {
      auto add = (SFAdd*)op.Memory;
      Value op1 = Dereference(env.Values[add->Operand1Id]);
      Value op2 = Dereference(env.Values[add->Operand2Id]);
      DoOp(add->ResultTypeId, add->ResultId, op1, op2, Add<float>);
      break;
    }
    case Op::OpIAdd: {
      auto add = (SIAdd*)op.Memory;
      Value op1 = Dereference(env.Values[add->Operand1Id]);
      Value op2 = Dereference(env.Values[add->Operand2Id]);
      DoOp(add->ResultTypeId, add->ResultId, op1, op2, Add<int32>);
      break;
    }
    case Op::OpFSub: {
      auto sub = (SFSub*)op.Memory;
      Value op1 = Dereference(env.Values[sub->Operand1Id]);
      Value op2 = Dereference(env.Values[sub->Operand2Id]);
      DoOp(sub->ResultTypeId, sub->ResultId, op1, op2, Sub<float>);
      break;
    }
    case Op::OpFDiv: {
      auto div = (SFDiv*)op.Memory;
      Value op1 = Dereference(env.Values[div->Operand1Id]);
      Value op2 = Dereference(env.Values[div->Operand2Id]);
      DoOp(div->ResultTypeId, div->ResultId, op1, op2, Div<float>);
      break;
    }
    case Op::OpFMul: {
      auto mul = (SFMul*)op.Memory;
      Value op1 = Dereference(env.Values[mul->Operand1Id]);
      Value op2 = Dereference(env.Values[mul->Operand2Id]);
      DoOp(mul->ResultTypeId, mul->ResultId, op1, op2, Mul<float>);
      break;
    }
    case Op::OpVectorTimesScalar: {
      auto vts = (SVectorTimesScalar*)op.Memory;
      Value scalar = Dereference(env.Values[vts->ScalarId]);
      Value vector = Dereference(env.Values[vts->VectorId]);
      DoOp(vts->ResultTypeId, vts->ResultId, vector, [scalar](Value comp) {return Mul<float>(scalar, comp);});
      break;
    }
    case Op::OpSLessThan: {
      auto lessThan = (SSLessThan*)op.Memory;
      Value op1 = Dereference(env.Values[lessThan->Operand1Id]);
      Value op2 = Dereference(env.Values[lessThan->Operand2Id]);
      DoOp(lessThan->ResultTypeId, lessThan->ResultId, op1, op2, [](Value a, Value b) { return Cmp<int32>(a, b) == -1; });
      break;
    }
    case Op::OpSGreaterThan: {
      auto greaterThan = (SSLessThan*)op.Memory;
      Value op1 = Dereference(env.Values[greaterThan->Operand1Id]);
      Value op2 = Dereference(env.Values[greaterThan->Operand2Id]);
      DoOp(greaterThan->ResultTypeId, greaterThan->ResultId, op1, op2, [](Value a, Value b) { return Cmp<int32>(a, b) == 1; });
      break;
    }
    case Op::OpLoad: {
      auto load = (SLoad*)op.Memory;
      auto valueToLoad = env.Values.at(load->PointerId);
      env.Values[load->ResultId] = valueToLoad;
      break;
    }
    case Op::OpStore: {
      auto store = (SStore*)op.Memory;
      auto val = env.Values[store->ObjectId];
      auto var = GetType(val.TypeId);
      if (var.Op == Op::OpTypePointer) {
        SetVariable(store->PointerId, val.Memory);
      } else {
        SetVariable(store->PointerId, &val.Memory);
      }
      break;
    }
    case Op::OpTextureSample: {
      auto sample = (STextureSample*)op.Memory;
      auto sampler = Dereference(env.Values.at(sample->SamplerId));
      auto coord = Dereference(env.Values.at(sample->CoordinateId));
      Value bias = { 0, 0 };
      if (sample->BiasId != 0) {
        bias = Dereference(env.Values.at(sample->BiasId));
      }

      env.Values[sample->ResultId] = TextureSample(sampler, coord, bias, sample->ResultTypeId);
      break;
    }
    case Op::OpLabel:
    case Op::OpSelectionMerge:
    case Op::OpLoopMerge:
      break;
    case Op::OpAccessChain: {
      auto access = (SAccessChain*)op.Memory;
      auto val = Dereference(env.Values.at(access->BaseId));

      uint32* indices = new uint32[access->IndexesIdsCount];
      for (int i = 0; i < access->IndexesIdsCount; i++) {
        indices[i] = *(uint32*)Dereference(env.Values[access->IndexesIds[i]]).Memory;
      }

      byte* mem = GetPointerInComposite(val.TypeId, val.Memory, access->IndexesIdsCount, indices);
      delete indices;

      Value res = VmInit(access->ResultTypeId, &mem);
      env.Values[access->ResultId] = res;
      break;
    }
    //TODO: FIX INDICES (NOT HIERARCHY!)
    case Op::OpCompositeExtract: {
      auto extract = (SCompositeExtract*)op.Memory;
      auto composite = env.Values[extract->CompositeId];
      byte* mem = GetPointerInComposite(composite.TypeId, composite.Memory, extract->IndexesCount, extract->Indexes);
      Value val = { extract->ResultTypeId, VmAlloc(extract->ResultTypeId) };
      memcpy(val.Memory, mem, GetTypeByteSize(val.TypeId));
      env.Values[extract->ResultId] = val;
      break;
    }
    case Op::OpCompositeInsert: {
      auto insert = (SCompositeInsert*)op.Memory;
      auto composite = Dereference(env.Values[insert->CompositeId]);
      Value val = Dereference(env.Values.at(insert->ObjectId));
      byte* mem = GetPointerInComposite(composite.TypeId, composite.Memory, insert->IndexesCount, insert->Indexes);
      memcpy(mem, val.Memory, GetTypeByteSize(val.TypeId));
      env.Values[insert->ResultId] = VmInit(composite.TypeId, composite.Memory);
      break;
    }
    case Op::OpCompositeConstruct: {
      auto construct = (SCompositeConstruct*)op.Memory;
      Value val = { construct->ResultTypeId, VmAlloc(construct->ResultTypeId) };
      env.Values[construct->ResultId] = val;
      byte* memPtr = val.Memory;
      for (int i = 0; i < construct->ConstituentsIdsCount; i++) {
        auto memVal = env.Values[construct->ConstituentsIds[i]];
        uint32 memSize = GetTypeByteSize(memVal.TypeId);
        memcpy(memPtr, memVal.Memory, memSize);
        memPtr += memSize;
      }
      assert(memPtr - val.Memory == GetTypeByteSize(construct->ResultTypeId));
      break;
    }
    case Op::OpVariable: {
      auto var = (SVariable*)op.Memory;
      Value val = { var->ResultTypeId, VmAlloc(var->ResultTypeId) };
      if (var->InitializerId) {
        memcpy(val.Memory, env.Values[var->InitializerId].Memory, GetTypeByteSize(val.TypeId));
      }
      else {
        memset(val.Memory, 0, GetTypeByteSize(val.TypeId));
      }
      env.Values[var->ResultId] = val;
      break;
    }
    case Op::OpReturnValue: {
      auto ret = (SReturnValue*)op.Memory;
      return ret->ValueId;
    }
    case Op::OpReturn:
      return 0;
    default:
      std::cout << "Unimplemented operation: " << writeOp(op);
      return -1;
    }

    pc++;
  }
  return 0;
}

void* InterpretedVM::ReadVariable(uint32 id) {
  auto var = prog.Variables.at(id);
  if (env.Values.find(var.ResultId) == env.Values.end()) {
    return nullptr;
  }
  return env.Values[var.ResultId].Memory;
}

void* InterpretedVM::ReadVariable(std::string name) {
  for (auto& nameOp : prog.Names) {
    if (nameOp.second.Name == name) {
      return ReadVariable(nameOp.second.TargetId);
    }
  }
  return nullptr;
}

bool InterpretedVM::SetVariable(uint32 id, void* value) {
  SVariable var;
  
  if (prog.CurrentFunction->Variables.find(id) != prog.CurrentFunction->Variables.end()) {
    var = prog.CurrentFunction->Variables.at(id);
  } else {
    var = prog.Variables.at(id);
  }

  if (env.Values.find(var.ResultId) == env.Values.end()) {
    Value val = { var.ResultTypeId, VmAlloc(var.ResultTypeId) };
    if (value) {
      memcpy(val.Memory, value, GetTypeByteSize(val.TypeId));
    } else {
      memset(val.Memory, 0, GetTypeByteSize(val.TypeId));
    }
    env.Values[var.ResultId] = val;
  } else {
    Value val = env.Values[var.ResultId];
    memcpy(val.Memory, value, GetTypeByteSize(val.TypeId));
  }
  return true;
}

bool InterpretedVM::SetVariable(std::string name, void* value) {
  for (auto& nameOp : prog.Names) {
    if (nameOp.second.Name == name) {
      return SetVariable(nameOp.second.TargetId, value);
    }
  }
  return false;
}

uint32 InterpretedVM::GetTypeByteSize(uint32 typeId) {
  if (TypeByteSizes.find(typeId) != TypeByteSizes.end()) {
    return TypeByteSizes.at(typeId);
  }

  auto definedType = prog.DefinedTypes.at(typeId);
  uint32 size = 0;

  switch (definedType.Op)
  {
  case Op::OpTypeArray: {
    auto arr = (STypeArray*)definedType.Memory;
    size = GetTypeByteSize(size) * *(uint32*)env.Values[arr->LengthId].Memory;
    break;
  }
  case Op::OpTypeInt: {
    auto i = (STypeInt*)definedType.Memory;
    assert(i->Width % 8 == 0);
    size = i->Width / 8;
    break;
  }
  case Op::OpTypeFloat: {
    auto f = (STypeFloat*)definedType.Memory;
    assert(f->Width % 8 == 0);
    size = f->Width / 8;
    break;
  }
  case Op::OpTypeBool: {
    size = sizeof(bool);
    break;
  }
  case Op::OpTypePointer: {
    size = sizeof(void*);
    break;
  }
  case Op::OpTypeStruct: {
    auto s = (STypeStruct*)definedType.Memory;
    for (int i = 0; i < s->MembertypeIdsCount; i++) {
      uint32 id = s->MembertypeIds[i];
      size += GetTypeByteSize(id);
    }
    break;
  }
  case Op::OpTypeVector: {
    auto v = (STypeVector*)definedType.Memory;
    size = GetTypeByteSize(v->ComponenttypeId) * v->Componentcount;
    break;
  }
  default:
    std::cout << "Not a type definition: " << writeOp(definedType);
  }

  TypeByteSizes[typeId] = size;
  return size;
}

bool InterpretedVM::InitializeConstants() {
  for (auto& constant : prog.Constants) {
    auto op = constant.second;
    switch (op.Op) {
    case Op::OpConstant: {
      auto constant = (SConstant*)op.Memory;
      Value val = { constant->ResultTypeId, (byte*)constant->Values };
      env.Values[constant->ResultId] = val;
      break;
    }
    case Op::OpConstantComposite: {
      auto constant = (SConstantComposite*)op.Memory;
      Value val = { constant->ResultTypeId, VmAlloc(constant->ResultTypeId) };
      env.Values[constant->ResultId] = val;
      byte* memPtr = val.Memory;
      for (int i = 0; i < constant->ConstituentsIdsCount; i++) {
        auto memVal = env.Values[constant->ConstituentsIds[i]];
        uint32 memSize = GetTypeByteSize(memVal.TypeId);
        memcpy(memPtr, memVal.Memory, memSize);
        memPtr += memSize;
      }
      assert( memPtr - val.Memory == GetTypeByteSize(constant->ResultTypeId));
      break;
    }
    case Op::OpConstantFalse: {
      auto constant = (SConstantFalse*)op.Memory;
      Value val = { constant->ResultTypeId, VmAlloc(constant->ResultTypeId) };
      *(bool*)val.Memory = false;
      break;
    }
    case Op::OpConstantTrue: {
      auto constant = (SConstantTrue*)op.Memory;
      Value val = { constant->ResultTypeId, VmAlloc(constant->ResultTypeId) };
      *(bool*)val.Memory = true;
      break;
    }
    default:
      std::cout << "Operation does not define a constant: " << writeOp(op);
      return false;
    }
  }

  return true;
}

bool InterpretedVM::Run() {
  if (!InitializeConstants()) {
    std::cout << "Could not define constants!" << std::endl;
    return false;
  }

  for (auto& ep : prog.EntryPoints) {
    auto func = prog.FunctionDefinitions.at(ep.second.EntryPointId);
    if (Execute(&func) != 0) {
      return false;
    }
  }

  return true;
}
