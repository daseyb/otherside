#include "codegen.h"
#include <string>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "parser_definitions.h"
#include "lookups_gen.h"
#include "parser.h"

std::map<uint32, std::string> ids;

void startComment(std::stringstream* ss) {
  *ss << "/*" << std::endl;
}

void endComment(std::stringstream* ss) {
  *ss << "*/" << std::endl;
}

bool g_header(std::stringstream* ss, const Program& prog) {
  startComment(ss);
  *ss << "Version: " << prog.Version << std::endl;
  *ss << "Generator Magic: " << prog.GeneratorMagic << std::endl;
  *ss << "ID Bound: " << prog.IDBound << std::endl;
  *ss << "Instruction Schema: " << prog.InstructionSchema << std::endl;
  *ss << "=================================================" << std::endl;
  endComment(ss);
  return true;
}

bool g_imports(std::stringstream* ss, const Program& prog) {
  *ss << std::endl;
  *ss << "#include <stdint.h>" << std::endl;
  *ss << "#include <stdlib.h>" << std::endl;
  *ss << "#include <vector>" << std::endl;
  *ss << "#include <string>" << std::endl;

  for (auto inc : prog.ExtensionImports) {
    *ss << "#include \"" << inc.second.Name << ".h\"" << std::endl;
  }

  return true;
}

bool g_types(std::stringstream* ss, const Program& prog) {
  *ss << std::endl;
  *ss << "// Predefined types: " << std::endl;
  *ss << "// =================================================" << std::endl;
  *ss << "typedef double float64;" << std::endl;
  *ss << "typedef float float32;" << std::endl;
  *ss << "typedef uint8_t uint8;" << std::endl;
  *ss << "typedef uint16_t uint16;" << std::endl;
  *ss << "typedef uint32_t uint32;" << std::endl;
  *ss << "typedef uint64_t uint64;" << std::endl;
  *ss << "typedef int8_t int8;" << std::endl;
  *ss << "typedef int16_t int16;" << std::endl;
  *ss << "typedef int32_t int32;" << std::endl;
  *ss << "typedef int64_t int64;" << std::endl;
  *ss << "// =================================================" << std::endl;
  *ss << std::endl;

  for (auto type : prog.DefinedTypes) {
    std::stringstream idName;

    switch (type.second.Op)
    {
    case Op::OpTypeFloat:
    {
      STypeFloat* opFloat = (STypeFloat*)type.second.Memory;
      idName << "float" << opFloat->Width;
      break;
    }
    case Op::OpTypeBool:
    {
      STypeBool* opBool = (STypeBool*)type.second.Memory;
      idName << "bool";
      break;
    }
    case Op::OpTypeInt:
    {
      STypeInt* opInt = (STypeInt*)type.second.Memory;
      std::stringstream baseType;
      if (opInt->Signedness == 0) idName << "u";
      idName << "int" << opInt->Width;
      break;
    }
    case Op::OpTypeVoid:
    {
      STypeVoid* opBool = (STypeVoid*)type.second.Memory;
      idName << "void";
      break;
    }
    case Op::OpTypePointer:
    {
      STypePointer* opPointer = (STypePointer*)type.second.Memory;
      idName << "p_" << ids[opPointer->TypeId];
      *ss << "typedef " << ids[opPointer->TypeId] << "* " << idName.str() << ";" << std::endl;
      break;
    }
    case Op::OpTypeVector:
    {
      STypeVector* opVector = (STypeVector*)type.second.Memory;
      idName << "v_" << ids[opVector->ComponentTypeId] << "_" << opVector->ComponentCount;
      auto idNameStr = idName.str();
      auto makeElementWiseOp = [opVector, idNameStr, ss](std::string op) {
        *ss << std::endl;
        *ss << "  friend " << idNameStr << " operator"<< op << "(" << idNameStr << " a, const " << idNameStr << "& b) {" << std::endl;
        for (int i = 0; i < opVector->ComponentCount; i++) {
          *ss << "    a.v[" << i << "] " << op << "= b.v[" << i << "];" << std::endl;
        }
        *ss << "    return a;" << std::endl;
        *ss << "  }" << std::endl;
        *ss << std::endl;
      };

      *ss << "struct " << idName.str() << " {" << std::endl;
      *ss << "  " << ids[opVector->ComponentTypeId] << " " << "v[" << opVector->ComponentCount << "];" << std::endl;
      makeElementWiseOp("+");
      makeElementWiseOp("-");
      makeElementWiseOp("*");
      makeElementWiseOp("/");
      *ss << "};" << std::endl;
      break;
    }
    case Op::OpTypeStruct:
    {
      STypeStruct* opStruct = (STypeStruct*)type.second.Memory;
      if (prog.Names.find(opStruct->ResultId) != prog.Names.end()) {
        idName << prog.Names.at(opStruct->ResultId).Name;
      } else {
        idName << "s_" << opStruct->ResultId;
      }

      *ss << "struct " << idName.str() << " {" << std::endl;
      for (uint32 i = 0; i < opStruct->MembertypeIdsCount; i++) {
        std::stringstream memberName;
        uint32 key = (opStruct->ResultId << 16) & i;
        if (prog.MemberNames.find(key) != prog.MemberNames.end()) {
          memberName << prog.MemberNames.at(key).Name;
        }
        else {
          memberName << "m_" << i;
        }

        *ss << "  " << ids[opStruct->MembertypeIds[i]] << " " << memberName.str() << ";" << std::endl;
      }
      *ss << "};" << std::endl;
      break;
    }
    default:
      break;
    }

    ids.insert(std::pair<uint32, std::string>(type.first, idName.str()));
  }

  return true;
}

void writeName(std::stringstream* name, const Program& prog, int id, const std::string& prefix) {
  if (prog.Names.find(id) != prog.Names.end()) {
    *name << prog.Names.at(id).Name;
  }
  else {
    *name << prefix << id;
  }
}

bool g_literal(std::stringstream* ss, const Program& prog, int typeId, int valuesCount, uint32* values) {
  assert(values);
  auto type = prog.DefinedTypes.at(typeId);

  switch (type.Op)
  {
  case Op::OpTypeFloat: {
    assert(valuesCount == 1 || valuesCount == 2);
    std::string fstring = "";
    if (valuesCount == 1) {
      fstring = std::to_string(*(float*)values);
    }
    else if (valuesCount == 2) {
      fstring = std::to_string(*(double*)values);
    }

    *ss << fstring << "f";

    break;
  }
  case Op::OpTypeInt:
    assert(valuesCount == 1 || valuesCount == 2);
    if (valuesCount == 1) {
      *ss << *(uint32*)values;
    }
    else if (valuesCount == 2) {
      *ss << *(uint64*)values;
    }
    break;
  case Op::OpTypeStruct:
  case Op::OpTypeVector:
    break;
  }

  return true;
}

bool g_constants(std::stringstream* ss, const Program& prog) {
  *ss << std::endl;
  for (auto constant : prog.Constants) {
    std::stringstream idName;

    switch (constant.second.Op) {
      case Op::OpConstant: {
        auto opConst = (SConstant*)constant.second.Memory;
        writeName(&idName, prog, opConst->ResultId, "c_");
        *ss << "const " << ids[opConst->ResultTypeId] << " " << idName.str() << " = ";
        if (!g_literal(ss, prog, opConst->ResultTypeId, opConst->ValuesCount, opConst->Values)) {
          return false;
        }

        *ss << ";" << std::endl;
        break;
      }
    }

    ids.insert(std::pair<uint32, std::string>(constant.first, idName.str()));
  }

  return true;
}

bool g_variable(std::stringstream* ss, SVariable* var, const Program& prog) {
  std::stringstream idName;
  if (prog.Names.find(var->ResultId) != prog.Names.end()) {
    idName << prog.Names.at(var->ResultId).Name;
  } else {
    idName << "var" << var->ResultId;
  }

  *ss << (var->StorageClass != StorageClass::Function ? "static " : "") << ids[var->ResultTypeId] << " " << idName.str();

  ids.insert(std::pair<uint32, std::string>(var->ResultId, idName.str()));
  return true;
}

bool g_variables(std::stringstream* ss, const Program& prog) {
  *ss << std::endl;

  for (auto var : prog.Variables) {
    g_variable(ss, &var.second, prog);
    *ss << ";" << std::endl;
  }

  return true;
}

void indent(char* indentStr) {
  int len = strlen(indentStr);
  indentStr[len] = ' ';
  indentStr[len + 1] = ' ';
}


void unindent(char* indentStr) {
  int len = strlen(indentStr);
  indentStr[len - 2] = 0;
}

bool g_block(std::stringstream* ss, const Program& prog, const Function& func, const Block& block, char* indentStr) {

  bool doIndent = block.MergeInfo.Memory != nullptr;
  if (doIndent) {
    indent(indentStr);
  }

  for (auto op : block.Ops) {
    *ss << indentStr;
    switch (op.Op) {
    case Op::OpLabel: {
      SLabel* label = (SLabel*)op.Memory;
      ids[label->ResultId] = "label_" + std::to_string(label->ResultId);
      *ss << ids[label->ResultId] << ":";
      break;
    }
    case Op::OpBranch: {
      SBranch* branch = (SBranch*)op.Memory;
      *ss << "goto label_" << branch->TargetLabelId << ";";
      break;
    }
    case Op::OpBranchConditional: {
      SBranchConditional* branch = (SBranchConditional*)op.Memory;
      *ss << "if(" << ids[branch->ConditionId] << ") { " << "goto label_" << branch->TrueLabelId << "; }" << std::endl;
      *ss << indentStr << "else { goto label_" << branch->FalseLabelId << "; }";
      break;
    }
    case Op::OpVariable: {
      SVariable* variable = (SVariable*)op.Memory;
      g_variable(ss, variable, prog);
      auto resultTypeName = ids[variable->ResultTypeId];
      *ss << " = (" << resultTypeName << ")malloc(sizeof(" << resultTypeName.substr(2, resultTypeName.length() - 2) << "));";
      break;
    }
    case Op::OpReturn: {
      *ss << "return;";
      break;
    }
    case Op::OpLoad: {
      SLoad* load = (SLoad*)op.Memory;
      ids[load->ResultId] = "var_" + std::to_string(load->ResultId);
      *ss << ids[load->ResultTypeId] << " " << ids[load->ResultId] << " = *" << ids[load->PointerId] << ";";
      break;
    }
    case Op::OpStore: {
      SStore* store = (SStore*)op.Memory;
      *ss << "*" << ids[store->PointerId] << " = " << ids[store->ObjectId] << ";";
      break;
    }
    case Op::OpSLessThan: {
      SSLessThan* lessThan = (SSLessThan*)op.Memory;
      ids[lessThan->ResultId] = "var_" + std::to_string(lessThan->ResultId);
      *ss << "bool " << ids[lessThan->ResultId] << " = " << ids[lessThan->Operand1Id] << " < " << ids[lessThan->Operand2Id] << ";";

      break;
    }
    case Op::OpFAdd: 
    case Op::OpIAdd: {
      SFAdd* fadd = (SFAdd*)op.Memory;
      ids[fadd->ResultId] = "var_" + std::to_string(fadd->ResultId);
      *ss << ids[fadd->ResultTypeId] << " " << ids[fadd->ResultId] << " = " << ids[fadd->Operand1Id] << " + " << ids[fadd->Operand2Id] << ";";
      break;
    }
    case Op::OpCompositeExtract: {
      SCompositeExtract* ce = (SCompositeExtract*)op.Memory;
      ids[ce->ResultId] = "var_" + std::to_string(ce->ResultId);
      *ss << ids[ce->ResultTypeId] << " " << ids[ce->ResultId] << " = " << ids[ce->CompositeId] << ".v[" << ce->Indexes[0] << "];";
      break;
    }
    case Op::OpCompositeConstruct: {
      SCompositeConstruct* cc = (SCompositeConstruct*)op.Memory;
      ids[cc->ResultId] = "var_" + std::to_string(cc->ResultId);
      *ss << ids[cc->ResultTypeId] << " " << ids[cc->ResultId] << " = {";
      for (int i = 0; i < cc->ConstituentsIdsCount; i++) {
        *ss << ids[cc->ConstituentsIds[i]];
        if (i < cc->ConstituentsIdsCount - 1) {
          *ss << ", ";
        }
      }
      *ss << "};";
      break;
    }
    default: {
      *ss << "// " << writeOp(op, &prog);
      break;
    }
    }
    *ss << std::endl;
  }

  for (auto child : block.Children) {
    if (!g_block(ss, prog, func, func.Blocks.at(child), indentStr)) {
      return false;
    }
  }

  if (doIndent) {
    unindent(indentStr);
  }

  return true;
}

bool g_function(std::stringstream* ss, const Program& prog, const Function& func) {
  std::stringstream idName;
  if (prog.Names.find(func.Info.ResultId) != prog.Names.end()) {
    idName << "spv_" << prog.Names.at(func.Info.ResultId).Name;
  } else {
    idName << "spv_fun" << func.Info.ResultId;
  }

  *ss << ids[func.Info.ResultTypeId] << " " << idName.str() << "(";

  uint32 paramIndex = 0;
  for (auto param : func.Parameters) {
    std::stringstream paramName;
    if (prog.Names.find(param.ResultId) != prog.Names.end()) {
      paramName << prog.Names.at(param.ResultId).Name;
    } else {
      paramName << "param" << param.ResultId;
    }

    *ss << ids[param.ResultTypeId] << " " << paramName.str();
    if (paramIndex + 1 < func.Parameters.size()) {
      *ss << ", ";
    }

    paramIndex++;
  }

  *ss << ")" << (func.Blocks.size() == 0 ? ";" : " {") << std::endl;

  if (func.Blocks.size() > 0) {
    char indentBuff[255];
    memset(indentBuff, 0, 255);
    indent(indentBuff);
    if (!g_block(ss, prog, func, func.Blocks.at(0), indentBuff)) {
      return false;
    }
    unindent(indentBuff);

    *ss << "}" << std::endl;
  }

  *ss << std::endl;


  ids.insert(std::pair<uint32, std::string>(func.Info.ResultId, idName.str()));
  return true;
}

bool g_functions(std::stringstream* ss, const Program& prog) {
  *ss << std::endl;

  for (auto var : prog.FunctionDeclarations) {
    if (!g_function(ss, prog, var.second)) {
      return false;
    }
  }

  for (auto var : prog.FunctionDefinitions) {
    if (!g_function(ss, prog, var.second)) {
      return false;
    }
  }

  return true;
}

bool genCode(std::stringstream* ss, const Program& prog) {
  if (!g_header(ss, prog)) {
    return false;
  }

  if (!g_imports(ss, prog)) {
    return false;
  }

  if (!g_types(ss, prog)) {
    return false;
  }

  if (!g_variables(ss, prog)) {
    return false;
  }

  if (!g_constants(ss, prog)) {
    return false;
  }

  if (!g_functions(ss, prog)) {
    return false;
  }


  return true;
}


bool genCode(const char* outFileName, const Program& prog) {
  std::stringstream out;
  if (!genCode(&out, prog)) {
    return false;
  }
  std::ofstream outFile;
  outFile.open(outFileName, std::ofstream::out);
  outFile << out.str();
  outFile.close();
  return true;
}
