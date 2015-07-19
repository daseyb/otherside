#pragma once
#include <vector>
#include <map>
#include <stack>
#include <string>
#include <assert.h>

#include "types.h"
#include "lookups.h"
#include "lookups_gen.h"

struct SOp {
  Op Op;
  void* Memory;
};

struct Block {
  SOp MergeInfo;
  SOp BranchInfo;
  uint32 Id;
  std::vector<SOp> Ops;
  std::vector<uint32> Children;
};

struct Function {
  SFunction Info;
  std::vector<SFunctionParameter> Parameters;
  std::vector<SOp> Ops;
  std::map<uint32, Block> Blocks;
  std::map<uint32, SVariable> Variables;
  std::map<uint32, SVariableArray> Arrays;
  std::map<uint32, uint32> Labels;

  std::stack<uint32> BlockStack;
  Block* CurrentBlock;
  bool InBlock = false;
  SOp NextBranchInfo = SOp{ Op::OpNop, nullptr };
  SOp NextMergeInfo = SOp{ Op::OpNop, nullptr };
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

  SOp NextOp;
  Function* CurrentFunction;
  bool InFunction = false;
};

static void addVariable(Program* prog, SVariable var) {
  if (prog->InFunction) {
    prog->CurrentFunction->Variables.insert(std::pair<uint32, SVariable>(var.ResultId, var));
  }
  else {
    prog->Variables.insert(std::pair<uint32, SVariable>(var.ResultId, var));
  }
}

static void addArray(Program* prog, SVariableArray var) {
  if (prog->InFunction) {
    prog->CurrentFunction->Arrays.insert(std::pair<uint32, SVariableArray>(var.ResultId, var));
  }
  else {
    prog->Arrays.insert(std::pair<uint32, SVariableArray>(var.ResultId, var));
  }
}

static Block* getBlock(Program* prog, uint32 id) {
  return &prog->CurrentFunction->Blocks.find(id)->second;
}

static void startNewBlock(Program* prog, SLabel label) {
  assert(prog->InFunction && !prog->CurrentFunction->InBlock);
  prog->CurrentFunction->Blocks.insert(std::pair<uint32, Block>(label.ResultId, Block()));
  Block* newBlockPtr = getBlock(prog, label.ResultId);

  getBlock(prog, prog->CurrentFunction->BlockStack.top())->Children.push_back(label.ResultId);

  newBlockPtr->Ops.clear();
  newBlockPtr->Id = label.ResultId;
  newBlockPtr->BranchInfo = prog->CurrentFunction->NextBranchInfo;
  prog->CurrentFunction->NextBranchInfo = SOp{ Op::OpNop, nullptr };
  newBlockPtr->MergeInfo = prog->CurrentFunction->NextMergeInfo;
  prog->CurrentFunction->NextMergeInfo = SOp{ Op::OpNop, nullptr };
  prog->CurrentFunction->InBlock = true;

  if (newBlockPtr->MergeInfo.Memory != nullptr) {
    prog->CurrentFunction->BlockStack.push(label.ResultId);
  }

  prog->CurrentFunction->CurrentBlock = newBlockPtr;
}

static void startLoop(Program* prog, SLoopMerge* loop) {
  assert(prog->InFunction && prog->CurrentFunction->InBlock);
  prog->CurrentFunction->NextMergeInfo = SOp{ Op::OpLoopMerge, loop };
}

static void startSelection(Program* prog, SSelectionMerge* selection) {
  assert(prog->InFunction && prog->CurrentFunction->InBlock);
  prog->CurrentFunction->NextMergeInfo = SOp{ Op::OpSelectionMerge, selection};
}

static void buildCFG(Program* prog, Function* func) {
  assert(!prog->InFunction);
}

static void endBlock(Program* prog, SOp branchInfo) {
  assert(prog->InFunction && prog->CurrentFunction->InBlock);

  prog->CurrentFunction->NextBranchInfo = branchInfo;
  prog->CurrentFunction->InBlock = false;

  prog->CurrentFunction->CurrentBlock = getBlock(prog, prog->CurrentFunction->BlockStack.top());

  if (prog->CurrentFunction->CurrentBlock->MergeInfo.Memory == nullptr) {
    return;
  }

  int mergeId = *((uint32*)prog->CurrentFunction->CurrentBlock->MergeInfo.Memory);
  assert(prog->NextOp.Op == Op::OpLabel);
  int labelId = *((uint32*)prog->NextOp.Memory);

  if (labelId == mergeId) {
    prog->CurrentFunction->CurrentBlock = getBlock(prog, prog->CurrentFunction->BlockStack.top());
    prog->CurrentFunction->BlockStack.pop();
  }
}

static void startFunction(Program* prog, SFunction func) {
  assert(!prog->InFunction);

  prog->CurrentFunction = new Function();
  prog->CurrentFunction->Info = func;
  prog->InFunction = true;
  prog->CurrentFunction->Blocks.insert(std::pair<uint32, Block>(0, Block()));
  prog->CurrentFunction->CurrentBlock = getBlock(prog, 0);
  prog->CurrentFunction->BlockStack.push(0);
}

static void endFunction(Program* prog) {
  assert(prog->InFunction && !prog->CurrentFunction->InBlock);
  assert(prog->CurrentFunction->BlockStack.top() == 0);
  
  prog->CurrentFunction->BlockStack.pop();
  assert(prog->CurrentFunction->BlockStack.size() == 0);

  if (prog->CurrentFunction->Blocks.size() == 0) {
    prog->FunctionDeclarations.insert(std::pair<uint32, Function>(prog->CurrentFunction->Info.ResultId, *prog->CurrentFunction));
  } else {
    prog->FunctionDefinitions.insert(std::pair<uint32, Function>(prog->CurrentFunction->Info.ResultId, *prog->CurrentFunction));
  }
  prog->InFunction = false;
}

static void addLabel(Program* prog, SLabel* label) {
  assert(prog->InFunction);
  prog->CurrentFunction->Labels[label->ResultId] = prog->CurrentFunction->Ops.size();
}

static void addOp(Program* prog, SOp op) {
  prog->CurrentFunction->Ops.push_back(op);
  prog->CurrentFunction->CurrentBlock->Ops.push_back(op);
}