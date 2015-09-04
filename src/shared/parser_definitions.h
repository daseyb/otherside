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
  spv::Op Op;
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
  std::map<uint32, uint32> Labels;
};

struct ParseFunction : public Function {
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

  std::map<uint32, Function> FunctionDeclarations;
  std::map<uint32, Function> FunctionDefinitions;
  std::vector<SOp> Ops;
};

struct ParseProgram : public Program {
  SOp NextOp;
  ParseFunction* CurrentFunction;
  bool InFunction = false;
};

static void addVariable(ParseProgram* prog, SVariable var) {
  if (prog->InFunction) {
    prog->CurrentFunction->Variables.insert({var.ResultId, var });
  }
  else {
    prog->Variables.insert({var.ResultId, var});
  }
}

static Block* getBlock(ParseProgram* prog, uint32 id) {
  return &prog->CurrentFunction->Blocks.find(id)->second;
}

static void startNewBlock(ParseProgram* prog, SLabel label) {
  assert(prog->InFunction && !prog->CurrentFunction->InBlock);
  prog->CurrentFunction->Blocks.insert({label.ResultId, Block()});
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

static void startLoop(ParseProgram* prog, SLoopMerge* loop) {
  assert(prog->InFunction && prog->CurrentFunction->InBlock);
  prog->CurrentFunction->NextMergeInfo = SOp{ Op::OpLoopMerge, loop };
}

static void startSelection(ParseProgram* prog, SSelectionMerge* selection) {
  assert(prog->InFunction && prog->CurrentFunction->InBlock);
  prog->CurrentFunction->NextMergeInfo = SOp{ Op::OpSelectionMerge, selection};
}

static void endBlock(ParseProgram* prog, SOp branchInfo) {
  assert(prog->InFunction && prog->CurrentFunction->InBlock);

  prog->CurrentFunction->InBlock = false;

  prog->CurrentFunction->NextBranchInfo = branchInfo;

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

static void startFunction(ParseProgram* prog, const SFunction& func) {
  assert(!prog->InFunction);

  prog->CurrentFunction = new ParseFunction();
  prog->CurrentFunction->Info = func;
  prog->InFunction = true;
  prog->CurrentFunction->Blocks.insert(std::pair<uint32, Block>(0, Block()));
  prog->CurrentFunction->CurrentBlock = getBlock(prog, 0);
  prog->CurrentFunction->BlockStack.push(0);
}

static void endFunction(ParseProgram* prog) {
  assert(prog->InFunction);
  if (prog->CurrentFunction->InBlock) {
    endBlock(prog, SOp{ Op::OpNop, nullptr });
  }
  assert(prog->CurrentFunction->BlockStack.top() == 0);
  
  prog->CurrentFunction->BlockStack.pop();
  assert(prog->CurrentFunction->BlockStack.size() == 0);

  if (prog->CurrentFunction->Blocks.size() == 1) {
    prog->FunctionDeclarations.insert({prog->CurrentFunction->Info.ResultId, (Function)*prog->CurrentFunction});
  } else {
    prog->FunctionDefinitions.insert({prog->CurrentFunction->Info.ResultId, (Function)*prog->CurrentFunction});
  }
  prog->InFunction = false;
}

static void addLabel(ParseProgram* prog, SLabel* label) {
  assert(prog->InFunction);
  prog->CurrentFunction->Labels[label->ResultId] = (uint32)prog->CurrentFunction->Ops.size();
}

static void addOp(ParseProgram* prog, SOp op) {
  prog->CurrentFunction->Ops.push_back(op);
  prog->CurrentFunction->CurrentBlock->Ops.push_back(op);
}
