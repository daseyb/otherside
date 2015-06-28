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
  std::vector<SOp> Ops;
};

struct Function {
  SFunction Info;
  std::vector<SFunctionParameter> Parameters;
  std::vector<Block> Blocks;
  Block CurrentBlock;
  bool InBlock;
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

  std::map<uint32, Function> FunctionDeclarations;
  std::map<uint32, Function> FunctionDefinitions;

  Function CurrentFunction;
  bool InFunction;
};

static void startNewBlock(Function* func) {
  func->CurrentBlock.Ops.clear();
  func->InBlock = true;
}

static void endBlock(Function* func) {
  func->Blocks.push_back(func->CurrentBlock);
  func->InBlock = false;
}

static void startFunction(Program* prog, SFunction func) {
  prog->CurrentFunction.Info = func;
  prog->CurrentFunction.Blocks.clear();
  prog->CurrentFunction.Parameters.clear();
  prog->InFunction = true;
}

static void endFunction(Program* prog) {

  if (prog->CurrentFunction.InBlock) {
    endBlock(&prog->CurrentFunction);
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