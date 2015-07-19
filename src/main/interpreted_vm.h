#pragma once
#include "vm.h"
#include <memory>
#include <vector>
#include "parser_definitions.h"

struct Function;

enum FilterMode {
  Point,
  Bilinear
};

enum WrapMode {
  Clamp,
  Repeat
};

struct Sampler {
  uint32 DimCount;
  uint32* Dims;
  void* Data;
  FilterMode FilterMode;
  WrapMode WrapMode;
};

class InterpretedVM : public VM {
private:
  Program& prog;
  Environment& env;
  std::map<uint32, uint32> TypeByteSizes;
  std::vector<std::unique_ptr<byte>> VmMemory;

  byte* VmAlloc(uint32 typeId);
  Value VmInit(uint32 typeId, void * val);
  
  byte * GetPointerInComposite(uint32 typeId, byte * composite, uint32 indexCount, uint32 * indices, uint32 currLevel) const;
  SOp GetType(uint32 typeId) const;
  bool IsVectorType(uint32 typeId) const;
  uint32 ElementCount(uint32 typeId) const;
  
  Value TextureSample(Value sampler, Value coord, Value bias, uint32 resultTypeId);
  
  uint32 Execute(Function* func);
  
  void * ReadVariable(uint32 id) const;
  bool SetVariable(uint32 id, void * value);
  
  uint32 GetTypeByteSize(uint32 typeId) const;

  bool InitializeConstants();

  void ImportExt(SExtInstImport import);

public:
  InterpretedVM(Program& prog, Environment& env) : prog(prog), env(env) { 
    for (auto& ext : prog.ExtensionImports) {
      ImportExt(ext.second);
    }
  }

  virtual bool Run() override;
  bool SetVariable(std::string name, void * value);
  void * ReadVariable(std::string name) const;

  template<typename Func, typename Arg, typename ...Args>
  Value DoOp(uint32 resultTypeId, Func op, Arg op1, Args && ...args);

  Value Dereference(Value val) const;
  Value IndexMemberValue(Value val, uint32 index) const;
  Value IndexMemberValue(uint32 typeId, byte * val, uint32 index) const;
};