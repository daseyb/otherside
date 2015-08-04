#pragma once
#include <map>
#include "types.h"
#include <cstring>

struct Program;
struct SOp;

struct Value {
  uint32 TypeId;
  byte* Memory;
};

enum FilterMode {
  FMPoint,
  FMBilinear
};

enum WrapMode {
  WMClamp,
  WMRepeat
};

struct Sampler {
  uint32 DimCount;
  uint32* Dims;
  void* Data;
  FilterMode Filter;
  WrapMode Wrap;
};


class VM {
private:
  virtual byte* VmAlloc(uint32 typeId) abstract;

public:
  virtual bool Run() abstract;
  virtual bool SetVariable(std::string name, void * value) abstract;
  virtual void * ReadVariable(std::string name) const abstract;
  virtual Value VmInit(uint32 typeId, void * val) abstract;

  template<typename Func, typename Arg, typename ...Args>
  Value DoOp(uint32 resultTypeId, Func op, Arg op1, Args && ...args);

  virtual Value Dereference(Value val) const abstract;
  virtual Value IndexMemberValue(Value val, uint32 index) const abstract;
  virtual Value IndexMemberValue(uint32 typeId, byte * val, uint32 index) const abstract;

  virtual uint32 GetTypeByteSize(uint32 typeId) const abstract;
  virtual byte * GetPointerInComposite(uint32 typeId, byte * composite, uint32 indexCount, uint32 * indices, uint32 currLevel) const abstract;
  virtual SOp GetType(uint32 typeId) const abstract;
  virtual bool IsVectorType(uint32 typeId) const abstract;
  virtual uint32 ElementCount(uint32 typeId) const abstract;
};

#define EXT_INST_FUNC(x) Value x(VM* vm, uint32 resultTypeId, int valueCount, Value* values)
typedef EXT_INST_FUNC(ExtInstFunc);
typedef ExtInstFunc** GetExtTableFunc(void);

#define xstr(s) str(s)
#define str(s) #s
#define EXT_EXPORT_TABLE_FUNC_NAME GetExtTable
#define EXT_EXPORT_TABLE_FUNC(x) __declspec(dllexport) ExtInstFunc** EXT_EXPORT_TABLE_FUNC_NAME(void) { return x; }

struct Environment {
  std::map<int, Value> Values;
  std::map<int, ExtInstFunc**> Extensions;
};

template <typename Func, typename Arg, typename ...Args>
inline Value VM::DoOp(uint32 resultTypeId, Func op, Arg op1, Args && ...args) {
  Value val = VmInit(resultTypeId, 0);

  if (IsVectorType(op1.TypeId)) {
    int elCount = ElementCount(op1.TypeId);
    for (int i = 0; i < elCount; i++) {
      auto result = op(IndexMemberValue(op1, i), IndexMemberValue(args, i)...);
      std::memcpy(IndexMemberValue(val, i).Memory, &result, GetTypeByteSize(resultTypeId) / elCount);
    }
  } else {
    auto result = op(op1, std::forward<Args>(args)...);
    std::memcpy(val.Memory, &result, GetTypeByteSize(resultTypeId));
  }

  return val;
}

#include "common_ops.h"
