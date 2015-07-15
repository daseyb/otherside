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
  Value Dereference(Value val);
  Value IndexMemberValue(Value val, uint32 index);
  Value IndexMemberValue(uint32 typeId, byte * val, uint32 index);
  byte * GetPointerInComposite(uint32 typeId, byte * composite, uint32 indexCount, uint32 * indices, uint32 currLevel);
  SOp GetType(uint32 typeId);
  bool IsVectorType(uint32 typeId);
  uint32 ElementCount(uint32 typeId);
  Value TextureSample(Value sampler, Value coord, Value bias, uint32 resultTypeId);
  uint32 Execute(Function* func);
  void * ReadVariable(uint32 id);
  bool SetVariable(uint32 id, void * value);
  uint32 GetTypeByteSize(uint32 typeId);
  bool InitializeConstants();
public:
  InterpretedVM(Program& prog, Environment& env) : prog(prog), env(env) { }
  virtual bool Run() override;
  bool SetVariable(std::string name, void * value);
  void * ReadVariable(std::string name);

  template <typename Func>
  void DoOp(uint32 resultTypeId, uint32 resultId, Value op1, Func op);

  template <typename Func>
  void DoOp(uint32 resultTypeId, uint32 resultId, Value op1, Value op2, Func op);
};