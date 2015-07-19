#include "vm.h"

Value round_exp(Value op1, const Program& prog) {
  return op1;
};


__declspec(dllexport) void* EXT_EXPORT_TABLE[] {
  round_exp,
};