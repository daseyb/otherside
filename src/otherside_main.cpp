#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <assert.h>
#include <vector>
#include <sstream>
#include "parser_definitions.h"
#include "lookups_gen.cpp"

std::string USAGE = "-i <input file> -o <outputFile>";

static uint32* buffer;
static int length;
static int index;

uint32 p_get() {
  return *buffer;
}

bool p_End() {
  return index >= length;
}

void p_eat() {
  index++;
  buffer++;
}

uint32 p_getAndEat() {
  uint32 result = p_get();
  p_eat();
  return result;
}

bool p_expectAndEat(uint32 e) {
  assert(e == p_get());
  p_eat();
  return true;
}

bool p_expect(uint32 e) {
  assert(e == p_get());
  return true;
}

std::string writeOp(SOp op) {
  std::stringstream opline;

  opline << OpStrings[op.Op];

  WordType wordTypes[255];

  uint32 opWordCount = 0;

  if (sizeof(LUTOpWordTypes) / sizeof(void*) <= op.Op) {
    return "";
  }
  else {
    WordType* opWordTypes = (WordType*)LUTOpWordTypes[op.Op];
    opWordCount = LUTOpWordTypesCount[op.Op];

    for (int i = 0; i < opWordCount; i++) {
      wordTypes[i] = opWordTypes[i];
    }
  }

  for (int i = 1; i < opWordCount; i++) {
    uint32 word = *((uint32*)op.Memory + i - 1);

    if (wordTypes[i] == WordType::TLiteralNumber) {
      opline << " " << word;
    }
    else if (wordTypes[i] == WordType::TId) {
      opline << " [" << word << "]";
    }
    else if (wordTypes[i] == WordType::TIdList) {
      uint32 count = word;

      for (int j = 0; j < count; j++) {
        word = *((uint32*)op.Memory + i + j);
        opline << " [" << word << "]";
      }

      break;
    }
    else if (wordTypes[i] == WordType::TLiteralNumberList) {
      uint32 count = word;

      for (int j = 0; j < count; j++) {
        word = *((uint32*)op.Memory + i + j);
        opline << " " << word;
      }

      break;
    }
    else if (wordTypes[i] == WordType::TLiteralString) {
      if (wordTypes[i - 1] != WordType::TLiteralString) {
        opline << " " << (char*)word;
      }
    }
    else {
      std::string* lutPointer = *((std::string**)LUTPointers + (uint32)wordTypes[i]);
      std::string name = lutPointer[word];
      opline << " " << name;
    }
  }

  opline << std::endl;
  return opline.str();
}

SOp p_readInstruction() {
  uint32* opData = buffer;
  uint32 word = p_getAndEat();
  spv::Op op = (spv::Op)(word & spv::OpCodeMask);
  uint16 wordCount = (uint16)(word >> spv::WordCountShift);

  std::cout << OpStrings[(uint32)op];

  WordType wordTypes[255];

  uint16 opWordCount = wordCount;

  if (sizeof(LUTOpWordTypes) / sizeof(void*) <= op) {
    wordTypes[0] = WordType::TOp;
    for (int i = 1; i < wordCount; i++) {
      wordTypes[i] = WordType::TLiteralNumber;
    }
  }
  else {
    WordType* opWordTypes = (WordType*)LUTOpWordTypes[op];
    opWordCount = LUTOpWordTypesCount[op];

    for (int i = 0; i < wordCount; i++) {
      wordTypes[i] = opWordTypes[i > opWordCount - 1 ? opWordCount - 1 : i];
    }
  }

  uint32* opMem = new uint32[opWordCount + 1];
  memset(opMem, 0, sizeof(uint32) * (opWordCount + 1));
  SOp Result = { op, opMem};

  for (int i = 1; i < wordCount; i++) {
    word = p_getAndEat();
    uint32* currMem = opMem + i - 1;

    if (wordTypes[i] == WordType::TLiteralNumber) {
      std::cout << " " << word;
      *currMem = word;
    } else if (wordTypes[i] == WordType::TId) {
      std::cout << " [" << word << "]";
      *currMem = word;
    } else if (wordTypes[i] == WordType::TIdList) {
      if (i + 1 == opWordCount) {
        *(currMem++) = (uint32)(wordCount - opWordCount + 1);
        *(uint32**)currMem = (uint32*)(buffer - 1);
      }
      else if (i < opWordCount) {
        *currMem = word;
      }

      std::cout << " [" << word << "]";
    } else if (wordTypes[i] == WordType::TLiteralNumberList) {
      if (i + 1 == opWordCount) {
        *(currMem++) = (uint32)(wordCount - opWordCount + 1);
        *(uint32**)currMem = (uint32*)(buffer - 1);
      }
      else if (i < opWordCount) {
        *currMem = word;
      }

      std::cout << " " << word;

    } else if (wordTypes[i] == WordType::TLiteralString) {
      if (wordTypes[i - 1] != WordType::TLiteralString) {
        std::cout << " ";
        *(char**)currMem = (char*)(buffer - 1);
      }

      char* cbuff = (char*)&word;
      for (int j = 0; j < 4; j++) {
        std::cout << *cbuff;
        cbuff++;
      }
    }
    else {
      std::string* lutPointer = *((std::string**)LUTPointers + (uint32)wordTypes[i]);
      std::string name = lutPointer[word];
      std::cout << " " << name;
      *currMem = word;
    }
  }

  std::cout << std::endl;

  return Result;
}

bool p_parseProgram(Program* prog) {
  if (!p_expectAndEat(spv::MagicNumber)) {
    return false;
  }

  prog->Version = p_getAndEat();
  std::cout << "Version: " << prog->Version << std::endl;

  prog->GeneratorMagic = p_getAndEat();
  std::cout << "Generator Magic: " << prog->GeneratorMagic << std::endl;

  prog->IDBound = p_getAndEat();
  std::cout << "ID Bound: " << prog->IDBound << std::endl;

  prog->InstructionSchema = p_getAndEat();
  std::cout << "Instruction Schema: " << prog->InstructionSchema << std::endl;
  std::cout << "=================================================" << std::endl;

  int instructionIndex = 0;

  while (!p_End()) {
    std::cout << std::setw(3) << instructionIndex << ": ";
    SOp op = p_readInstruction();
    LUTHandlerMethods[op.Op]((void*)op.Memory, prog);

    if (prog->InFunction && prog->CurrentFunction.InBlock) {
      addOp(prog, op);
    }

    instructionIndex++;
  }

  return true;
}

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

std::map<uint32, std::string> ids;

bool g_imports(std::stringstream* ss, const Program& prog) {
  *ss << std::endl;
  *ss << "#include <stdint.h>" << std::endl;
  *ss << "#include <vector>" << std::endl;
  *ss << "#include <string>" << std::endl;

  for (auto inc : prog.ExtensionImports) {
    *ss << "#include \"" << inc.second.Name << ".h\"" << std::endl;
  }

  return true;
}

bool g_compileflags(std::stringstream* ss, const Program& prog) {
  *ss << std::endl;

  for (auto flag : prog.CompileFlags) {
    *ss << "#define " << flag << std::endl;
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
      idName << "float_" << opFloat->ResultId;
      *ss << "typedef float" << opFloat->Width << " " << idName.str() << ";" << std::endl;
      break;
    }
    case Op::OpTypeBool:
    {
      STypeBool* opBool = (STypeBool*)type.second.Memory;
      idName << "bool_" << opBool->ResultId;
      *ss << "typedef bool " << idName.str() << ";" << std::endl;
      break;
    }
    case Op::OpTypeInt:
    {
      STypeInt* opInt = (STypeInt*)type.second.Memory;
      idName << "int_" << opInt->ResultId;
      std::stringstream baseType;
      if (opInt->Signedness == 0) baseType << "u";
      baseType << "int" << opInt->Width;
      *ss << "typedef " << baseType.str() << " " << idName.str() << ";" << std::endl;
      break;
    }
    case Op::OpTypeVoid:
    {
      STypeVoid* opBool = (STypeVoid*)type.second.Memory;
      idName << "void_" << opBool->ResultId;
      *ss << "typedef void " << idName.str() << ";" << std::endl;
      break;
    }
    case Op::OpTypePointer:
    {
      STypePointer* opPointer = (STypePointer*)type.second.Memory;
      idName << "p_" << ids[opPointer->TypeId] << "_" << opPointer->ResultId;
      *ss << "typedef " << ids[opPointer->TypeId] << "* " << idName.str() << ";" << std::endl;
      break;
    }
    case Op::OpTypeVector:
    {
      STypeVector* opVector = (STypeVector*)type.second.Memory;
      idName << "v_" << ids[opVector->ComponenttypeId] << "_" << opVector->Componentcount << "_" << opVector->ResultId;
      *ss << "struct " << idName.str() << " {" << std::endl;
      *ss << "  " << ids[opVector->ComponenttypeId] << " " << "v[" << opVector->Componentcount << "];" << std::endl;
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
      for (int i = 0; i < opStruct->MembertypeIdsCount; i++) {
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

bool g_constants(std::stringstream* ss, const Program& prog) {
  *ss << std::endl;
  for (auto constant : prog.Constants) {
    switch (constant.second.Op)
    {
    case Op::OpConstant:
    {
      auto opConst = (SConstant*)constant.second.Memory;
      break;
    }
    }
  }

  return true;
}

bool g_variables(std::stringstream* ss, const Program& prog) {
  *ss << std::endl;

  for (auto var : prog.Variables) {
    std::stringstream idName;
    if (prog.Names.find(var.first) != prog.Names.end())
    {
      idName << prog.Names.at(var.first).Name;
    }
    else
    {
      idName << "var" << var.first;
    }
  
    *ss << "static " << ids[var.second.ResultTypeId] << " " << idName.str() << ";" << std::endl;

    ids.insert(std::pair<uint32, std::string>(var.first, idName.str()));
  }

  return true;
}

bool g_block(std::stringstream* ss, const Program& prog, const Function& func, const Block& block) {
  for (auto op : block.Ops) {
    *ss << "// " << writeOp(op);
  }
  
  return true;
}

bool g_function(std::stringstream* ss, const Program& prog, const Function& func) {
  std::stringstream idName;
  if (prog.Names.find(func.Info.ResultId) != prog.Names.end())
  {
    idName << prog.Names.at(func.Info.ResultId).Name;
  }
  else
  {
    idName << "fun" << func.Info.ResultId;
  }

  *ss << "static " << ids[func.Info.ResultTypeId] << " " << idName.str() << "(";

  int paramIndex = 0;
  for (auto param : func.Parameters) {
    std::stringstream paramName;
    if (prog.Names.find(param.ResultId) != prog.Names.end())
    {
      paramName << prog.Names.at(param.ResultId).Name;
    }
    else
    {
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
    for (auto block : func.Blocks) {
      g_block(ss, prog, func, block.second);
    }

    *ss << "}" << std::endl;
  }

  *ss << std::endl;


  ids.insert(std::pair<uint32, std::string>(func.Info.ResultId, idName.str()));
  return true;
}

bool g_functions(std::stringstream* ss, const Program& prog) {
  *ss << std::endl;

  for (auto var : prog.FunctionDeclarations) {
    g_function(ss, prog, var.second);
  }

  for (auto var : prog.FunctionDefinitions) {
    g_function(ss, prog, var.second);
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

  if (!g_compileflags(ss, prog)) {
    return false;
  }

  if (!g_types(ss, prog)) {
    return false;
  }

  if (!g_variables(ss, prog)) {
    return false;
  }

  if (!g_functions(ss, prog)) {
    return false;
  }


  return true;
}

struct CmdArgs {
  const char* InputFile;
  const char* OutputFile;
};

bool ParseArgs(int argc, const char** argv, CmdArgs* args) {
  for (int i = 1; i < argc; i++) {
    const char* arg = argv[i];

    if (strcmp(arg, "-i") == 0) {
      i++;
      if (i == argc) {
        return false;
      }
      args->InputFile = argv[i];
    } else if (strcmp(arg, "-o") == 0) {
      i++;
      if (i == argc) {
        return false;
      }
      args->OutputFile = argv[i];
    }
  }
  return true;
}


int main(int argc, const char** argv) {
  CmdArgs args;
  if (!ParseArgs(argc, argv, &args)) {
    std::cout << "Could not parse arguments. Usage: " << USAGE << std::endl;
    return -1;
  }

  std::ifstream inputFile;
  inputFile.open(args.InputFile, std::ifstream::in | std::ifstream::binary);
  inputFile.seekg(0, std::ios::end);
  std::streamsize size = inputFile.tellg();
  inputFile.seekg(0, std::ios::beg);

  assert(size % 4 == 0);
  std::streamsize wordCount = size / 4;

  buffer = new uint32[wordCount];
  length = wordCount;
  index = 0;

  if (!inputFile.read((char*)buffer, size)) {
    std::cout << "Could not read file." << std::endl;
    return -1;
  }
  
  inputFile.close();

  Program prog;

  if (!p_parseProgram(&prog)) {
    std::cout << "Could not parse program." << std::endl;
  }

  std::stringstream out;
  if (!genCode(&out, prog)) {
    std::cout << "Could not generate code for program." << std::endl;
  }

  std::ofstream outFile;
  outFile.open(args.OutputFile, std::ofstream::out);
  outFile << out.str();
  outFile.close();

  getchar();
  
  return 0;
}