#pragma once
#include "vm.h"
#include <memory>
#include <vector>
#include "parser_definitions.h"

struct Function;

class InterpretedVM : public VM {
private:
  Program& prog;
  Environment& env;
  std::map<uint32, uint32> TypeByteSizes;
  std::vector<std::unique_ptr<byte>> VmMemory;

  byte* VmAlloc(uint32 typeId) override;
  
  Value TextureSample(Value sampler, Value coord, Value bias, uint32 resultTypeId);
  
  uint32 Execute(Function* func);
  
  void * ReadVariable(uint32 id) const;
  bool SetVariable(uint32 id, void * value);
  

  bool InitializeConstants();

  void ImportExt(SExtInstImport import);

public:
  InterpretedVM(Program& prog, Environment& env) : prog(prog), env(env) { 
    for (auto& ext : prog.ExtensionImports) {
      ImportExt(ext.second);
    }
  }

  virtual bool Run() override;
  bool SetVariable(std::string name, void * value) override;
  void * ReadVariable(std::string name) const override;
  Value VmInit(uint32 typeId, void * val) override;

  Value Dereference(Value val) const override;
  Value IndexMemberValue(Value val, uint32 index) const override;
  Value IndexMemberValue(uint32 typeId, byte * val, uint32 index) const override;

  uint32 GetTypeByteSize(uint32 typeId) const override;
  byte * GetPointerInComposite(uint32 typeId, byte * composite, uint32 indexCount, uint32 * indices, uint32 currLevel) const override;
  SOp GetType(uint32 typeId) const override;
  bool IsVectorType(uint32 typeId) const override;
  uint32 ElementCount(uint32 typeId) const override;
};