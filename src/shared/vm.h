#pragma once
#include <map>
#include "types.h"

#define EXT_EXPORT_TABLE ext_exports

struct Program;

struct Value {
  uint32 TypeId;
  byte* Memory;
};

struct Environment {
  std::map<int, Value> Values;
};

class VM {
public:
  virtual bool Run() abstract;
};