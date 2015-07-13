#pragma once
#include "vm.h"
#include <memory>
#include <vector>

struct Function;

class InterpretedVM : public VM {
private:
  Program& prog;
  Environment& env;
  std::map<uint32, uint32> TypeByteSizes;
  std::vector<std::unique_ptr<byte>> VmMemory;
  byte* VmAlloc(uint32 typeId);
  Value IndexMemberValue(uint32 typeId, byte * val, uint32 index);
  byte * GetPointerInComposite(uint32 typeId, byte * composite, uint32 indexCount, uint32 * indices, uint32 currLevel);
  bool Execute(const Function& func);
  void * ReadVariable(uint32 id);
  bool SetVariable(uint32 id, void * value);
  uint32 GetTypeByteSize(uint32 typeId);
  bool InitializeConstants();
public:
  InterpretedVM(Program& prog, Environment& env) : prog(prog), env(env) { }
  virtual bool Run() override;
  bool SetVariable(std::string name, void * value);
  void * ReadVariable(std::string name);
};