#include "vm.h"

#ifdef __cplusplus
extern "C" {
#endif
  EXT_INST_FUNC(round_ext) {
    return values[0];
  };

  EXT_INST_FUNC(roundEven_ext) {
    return values[0];
  };

  ExtInstFunc* exports[]{
    round_ext,
    roundEven_ext
  };

  EXT_EXPORT_TABLE_FUNC(exports)

#ifdef __cplusplus
}
#endif