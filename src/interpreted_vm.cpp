#include "interpreted_vm.h"
#include "parser_definitions.h"
#include "parser.h"
#include <iostream>

byte* InterpretedVM::VmAlloc(uint32 typeId) {
  uint32 compositeSize = GetTypeByteSize(typeId);
  byte* mem = (byte*)malloc(compositeSize);
  VmMemory.push_back(std::unique_ptr<byte>(mem));
  return (byte*)mem;
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

bool InterpretedVM::Execute(const Function & func) {

  int pc = 0;

  for (;;) {
    auto op = func.Ops[pc];
    switch (op.Op) {
    case Op::OpBranch: {
      auto branch = (SBranch*)op.Memory;
      pc = func.Labels.at(branch->TargetLabelId);
      break;
    }
    case Op::OpBranchConditional: {
      auto branch = (SBranchConditional*)op.Memory;
      uint32 labelID;
      Value val = env.Values[branch->ConditionId];
      if (*(bool*)val.Memory) {
        labelID = branch->TrueLabelId;
      } else {
        labelID = branch->FalseLabelId;
      }
      pc = func.Labels.at(labelID);
      break;
    }
    case Op::OpSLessThan: {
      auto lessThan = (SSLessThan*)op.Memory;
      
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
      SetVariable(store->PointerId, &env.Values[store->ObjectId].Memory);
      break;
    }
    case Op::OpLabel:
    case Op::OpSelectionMerge:
      break;
    case Op::OpCompositeExtract: {
      auto extract = (SCompositeExtract*)op.Memory;
      auto composite = env.Values[extract->CompositeId];
      byte* mem = GetPointerInComposite(composite.TypeId, composite.Memory, extract->IndexesCount, extract->Indexes);
      Value val = { extract->ResultTypeId, VmAlloc(extract->ResultTypeId) };
      memcpy(val.Memory, mem, GetTypeByteSize(val.TypeId));
      env.Values[extract->ResultId] = val;
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
    case Op::OpReturn:
      return true;
    default:
      std::cout << "Unimplemented operation: " << writeOp(op);
      return false;
    }

    pc++;
  }
  return true;
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
    prog.CurrentFunction = &func;
    if (!Execute(func)) {
      return false;
    }
  }

  return true;
}
