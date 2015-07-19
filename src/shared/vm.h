#pragma once
#include <map>
#include "types.h"

struct Program;

struct Value {
  uint32 TypeId;
  byte* Memory;
};

#define EXT_INST_FUNC(x) Value x(uint32 resultTypeId, int valueCount, Value* values)
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

class VM {
public:
  virtual bool Run() abstract;
};