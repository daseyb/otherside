#pragma once
#include <vector>
#include <map>
#include "Khronos\spirv.h"


using namespace spv;

typedef uint8_t byte;
typedef uint16_t uint16;
typedef uint32_t uint32;
typedef uint64_t uint64;

#include "lookups.h"
#include "lookups_gen.h"

struct SOp {
  Op Op;
  void* Memory;
};

struct Block {
  uint32 Id;
  std::vector<SOp> Ops;
};

struct Function {
  SFunction Info;
  std::vector<SFunctionParameter> Parameters;
  std::map<uint32, Block> Blocks;
  std::map<uint32, SVariable> Variables;
  std::map<uint32, SVariableArray> Arrays;

  Block CurrentBlock;
  bool InBlock = false;
};

struct Program {
  uint32 Version;
  uint32 GeneratorMagic;
  uint32 IDBound;
  uint32 InstructionSchema;
  SSource SourceLanguage;
  SMemoryModel MemoryModel;
  std::vector<std::string> SourceExtensions;
  std::vector<std::string> SPIRVExtensions;
  std::vector<std::string> CompileFlags;

  std::map<uint32, SString> Strings;
  std::map<uint32, SName> Names;
  std::map<uint32, SMemberName> MemberNames;
  std::map<uint32, SLine> Lines;

  std::map<uint32, SEntryPoint> EntryPoints;
  std::map<uint32, SExecutionMode> ExecutionModes;
  std::map<uint32, SExtInstImport> ExtensionImports;
  std::map<uint32, SOp> DefinedTypes;
  std::map<uint32, SOp> Constants;
  std::map<uint32, SVariable> Variables;
  std::map<uint32, SVariableArray> Arrays;

  std::map<uint32, Function> FunctionDeclarations;
  std::map<uint32, Function> FunctionDefinitions;

  Function CurrentFunction;
  bool InFunction = false;
};

static void addVariable(Program* prog, SVariable var) {
  if (prog->InFunction) {
    prog->CurrentFunction.Variables.insert(std::pair<uint32, SVariable>(var.ResultId, var));
  }
  else {
    prog->Variables.insert(std::pair<uint32, SVariable>(var.ResultId, var));
  }
}

static void addArray(Program* prog, SVariableArray var) {
  if (prog->InFunction) {
    prog->CurrentFunction.Arrays.insert(std::pair<uint32, SVariableArray>(var.ResultId, var));
  }
  else {
    prog->Arrays.insert(std::pair<uint32, SVariableArray>(var.ResultId, var));
  }
}

static void startNewBlock(Program* prog, SLabel label) {
  assert(prog->InFunction && !prog->CurrentFunction.InBlock);

  prog->CurrentFunction.CurrentBlock.Ops.clear();
  prog->CurrentFunction.CurrentBlock.Id = label.ResultId;
  prog->CurrentFunction.InBlock = true;
}

static void endBlock(Program* prog) {
  assert(prog->InFunction && prog->CurrentFunction.InBlock);

  prog->CurrentFunction.Blocks.insert(std::pair<uint32, Block>(prog->CurrentFunction.CurrentBlock.Id, prog->CurrentFunction.CurrentBlock));
  prog->CurrentFunction.InBlock = false;
}

static void startFunction(Program* prog, SFunction func) {
  assert(!prog->InFunction);

  prog->CurrentFunction.Info = func;
  prog->CurrentFunction.Blocks.clear();
  prog->CurrentFunction.Parameters.clear();
  prog->InFunction = true;
}

static void endFunction(Program* prog) {
  assert(prog->InFunction);

  if (prog->CurrentFunction.InBlock) {
    endBlock(prog);
  }

  if (prog->CurrentFunction.Blocks.size() == 0) {
    prog->FunctionDeclarations.insert(std::pair<uint32, Function>(prog->CurrentFunction.Info.ResultId, prog->CurrentFunction));
  } else {
    prog->FunctionDefinitions.insert(std::pair<uint32, Function>(prog->CurrentFunction.Info.ResultId, prog->CurrentFunction));
  }
  prog->InFunction = false;
}


static void addOp(Program* prog, SOp op) {
  prog->CurrentFunction.CurrentBlock.Ops.push_back(op);
}