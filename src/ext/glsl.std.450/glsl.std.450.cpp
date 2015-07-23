#include "vm.h"
#include <assert.h>

#ifdef __cplusplus
extern "C" {
#endif

  #define ONE_ARG_OP(func) \
    assert(valueCount == 1); \
    return vm->DoOp(resultTypeId, [](Value val) {return func(*(float*)val.Memory); }, values[0]); \

  #define TWO_ARG_OP(func) \
    assert(valueCount == 2); \
    return vm->DoOp(resultTypeId, [](Value op1, Value op2) {return func(*(float*)op1.Memory, *(float*)op2.Memory); }, values[0], values[1]); \

  #define THREE_ARG_OP(func) \
    assert(valueCount == 3); \
    return vm->DoOp(resultTypeId, [](Value op1, Value op2, Value op3) {return func(*(float*)op1.Memory, *(float*)op2.Memory, *(float*)op3.Memory); }, values[0], values[1], values[2]); \

  #define THREE_ARG_OP_D(func) \
    assert(valueCount == 3); \
    return vm->DoOp(resultTypeId, func, values[0], values[1], values[2]); \

  EXT_INST_FUNC(round_ext) {
    ONE_ARG_OP(roundf);
  };

  EXT_INST_FUNC(roundEven_ext) {
    return values[0];
  };

  EXT_INST_FUNC(trunc_ext) {
    ONE_ARG_OP(trunc);
  };

  EXT_INST_FUNC(abs_ext) {
    ONE_ARG_OP(fabsf);
  };

  EXT_INST_FUNC(sign_ext) {
    ONE_ARG_OP([](float f) { return signbit(f) ? 0 : 1;})
  };

  EXT_INST_FUNC(floor_ext) {
    ONE_ARG_OP(floorf);
  };

  EXT_INST_FUNC(ceil_ext) {
    ONE_ARG_OP(ceilf);
  };

  EXT_INST_FUNC(fract_ext) {
    return values[0];
  };

  EXT_INST_FUNC(radians_ext) {
    return values[0];
  };

  EXT_INST_FUNC(degrees_ext) {
    return values[0];
  };

  EXT_INST_FUNC(sin_ext) {
    ONE_ARG_OP(sinf);
  };

  EXT_INST_FUNC(cos_ext) {
    ONE_ARG_OP(cosf);
  };

  EXT_INST_FUNC(tan_ext) {
    ONE_ARG_OP(tanf);
  };

  EXT_INST_FUNC(asin_ext) {
    ONE_ARG_OP(asinf);
  };

  EXT_INST_FUNC(acos_ext) {
    ONE_ARG_OP(acosf);
  };

  EXT_INST_FUNC(atan_ext) {
    ONE_ARG_OP(atanf);
  };

  EXT_INST_FUNC(sinh_ext) {
    ONE_ARG_OP(sinhf);
  }

  EXT_INST_FUNC(cosh_ext) {
    ONE_ARG_OP(coshf);
  }

  EXT_INST_FUNC(tanh_ext) {
    ONE_ARG_OP(tanhf);
  }
  
  EXT_INST_FUNC(asinh_ext) {
    ONE_ARG_OP(asinhf);
  }
  
  EXT_INST_FUNC(acosh_ext) {
    ONE_ARG_OP(acoshf);
  }

  EXT_INST_FUNC(atanh_ext) {
    ONE_ARG_OP(atanhf);
  }

  EXT_INST_FUNC(atan2_ext) { 
    TWO_ARG_OP(atan2f); 
  }

  EXT_INST_FUNC(pow_ext) { 
    assert(valueCount == 2);
    Value toPow = values[0];
    Value power = values[1];

    if (vm->IsVectorType(power.TypeId)) {
      return vm->DoOp(resultTypeId,
        [](Value op1, Value op2) { return powf(*(float*)op1.Memory, *(float*)op2.Memory); },
        toPow, power);
    } else {
      return vm->DoOp(resultTypeId,
        [power](Value op1) { return powf(*(float*)op1.Memory, *(float*)power.Memory); },
        toPow);
    }
  }

  EXT_INST_FUNC(exp_ext) { ONE_ARG_OP(expf); }
  EXT_INST_FUNC(log_ext) { ONE_ARG_OP(logf); }
  EXT_INST_FUNC(exp2_ext) { ONE_ARG_OP(exp2f); }
  EXT_INST_FUNC(log2_ext) { ONE_ARG_OP(log2f); }
  EXT_INST_FUNC(sqrt_ext) { ONE_ARG_OP(sqrtf); }
  EXT_INST_FUNC(inverseSqrt_ext) { ONE_ARG_OP([](float f) {return 1.0f / sqrtf(f);}) }

  EXT_INST_FUNC(determinant_ext) { return values [0]; }
  EXT_INST_FUNC(matrixInverse_ext) { return values [0]; }

  EXT_INST_FUNC(modf_ext) { TWO_ARG_OP(fmodf); }
  EXT_INST_FUNC(min_ext) { return values [0]; }
  EXT_INST_FUNC(max_ext) { return values [0]; }

  EXT_INST_FUNC(clamp_ext) { THREE_ARG_OP_D(Clamp<float>); }
  EXT_INST_FUNC(mix_ext) { return values [0]; }
  EXT_INST_FUNC(step_ext) { return values [0]; }
  EXT_INST_FUNC(smoothStep_ext) { return values [0]; }

  EXT_INST_FUNC(floatBitsToInt_ext) { return values [0]; }
  EXT_INST_FUNC(floatBitsToUint_ext) { return values [0]; }
  EXT_INST_FUNC(intBitsToFloat_ext) { return values [0]; }
  EXT_INST_FUNC(uintBitsToFloat_ext) { return values [0]; }

  EXT_INST_FUNC(fma_ext) { return values [0]; }
  EXT_INST_FUNC(frexp_ext) { return values [0]; }
  EXT_INST_FUNC(ldexp_ext) { return values [0]; }

  EXT_INST_FUNC(packSnorm4x8_ext) { return values [0]; }
  EXT_INST_FUNC(packUnorm4x8_ext) { return values [0]; }
  EXT_INST_FUNC(packSnorm2x16_ext) { return values [0]; }
  EXT_INST_FUNC(packUnorm2x16_ext) { return values [0]; }
  EXT_INST_FUNC(packHalf2x16_ext) { return values [0]; }
  EXT_INST_FUNC(packDouble2x32_ext) { return values [0]; }
  EXT_INST_FUNC(unpackSnorm2x16_ext) { return values [0]; }
  EXT_INST_FUNC(unpackUnorm2x16_ext) { return values [0]; }
  EXT_INST_FUNC(unpackHalf2x16_ext) { return values [0]; }
  EXT_INST_FUNC(unpackSnorm4x8_ext) { return values [0]; }
  EXT_INST_FUNC(unpackUnorm4x8_ext) { return values [0]; }
  EXT_INST_FUNC(unpackDouble2x32_ext) { return values [0]; }

  EXT_INST_FUNC(length_ext) { 
    assert(valueCount == 1);
    Value a = values[0];
    if (!vm->IsVectorType(a.TypeId)) {
      return vm->VmInit(resultTypeId, a.Memory);
    }

    uint32 elCount = vm->ElementCount(a.TypeId);
    float sum = 0;
    for (int i = 0; i < elCount; i++) {
      float val = *(float*)vm->IndexMemberValue(a, i).Memory;
      sum += val * val;
    }
    float res = sqrtf(sum);
    return vm->VmInit(resultTypeId, &res);
  }

  EXT_INST_FUNC(distance_ext) { 
    assert(valueCount == 2);
    Value start = values[0];
    Value end = values[1];
    Value diff = vm->DoOp(start.TypeId, Sub<float>, start, end);
    return length_ext(vm, resultTypeId, 1, &diff);
  }

  EXT_INST_FUNC(cross_ext) { return values [0]; }
  EXT_INST_FUNC(normalize_ext) { return values [0]; }
  EXT_INST_FUNC(ftransform_ext) { return values [0]; }
  EXT_INST_FUNC(faceForward_ext) { return values [0]; }
  EXT_INST_FUNC(reflect_ext) { return values [0]; }
  EXT_INST_FUNC(refract_ext) { return values [0]; }

  EXT_INST_FUNC(uaddCarry_ext) { return values [0]; }
  EXT_INST_FUNC(usubBorrow_ext) { return values [0]; }
  EXT_INST_FUNC(umulExtended_ext) { return values [0]; }
  EXT_INST_FUNC(imulExtended_ext) { return values [0]; }
  EXT_INST_FUNC(bitfieldExtract_ext) { return values [0]; }
  EXT_INST_FUNC(bitfieldInsert_ext) { return values [0]; }
  EXT_INST_FUNC(bitfieldReverse_ext) { return values [0]; }
  EXT_INST_FUNC(bitCount_ext) { return values [0]; }
  EXT_INST_FUNC(findLSB_ext) { return values [0]; }
  EXT_INST_FUNC(findMSB_ext) { return values [0]; }

  EXT_INST_FUNC(interpolateAtCentroid_ext) { return values [0]; }
  EXT_INST_FUNC(interpolateAtSample_ext) { return values [0]; }
  EXT_INST_FUNC(interpolateAtOffset_ext) { return values [0]; }

  ExtInstFunc* exports[]{
    round_ext,
    roundEven_ext,
    trunc_ext,
    abs_ext,
    sign_ext,
    floor_ext,
    ceil_ext,
    fract_ext,

    radians_ext,
    degrees_ext,
    sin_ext,
    cos_ext,
    tan_ext,
    asin_ext,
    acos_ext,
    atan_ext,
    sinh_ext,
    cosh_ext,
    tanh_ext,
    asinh_ext,
    acosh_ext,
    atanh_ext,
    atan2_ext,

    pow_ext,
    exp_ext,
    log_ext,
    exp2_ext,
    log2_ext,
    sqrt_ext,
    inverseSqrt_ext,

    determinant_ext,
    matrixInverse_ext,

    modf_ext,            // second argument needs the OpVariable_ext, not an OpLoad
    min_ext,
    max_ext,
    clamp_ext,
    mix_ext,
    step_ext,
    smoothStep_ext,

    floatBitsToInt_ext,
    floatBitsToUint_ext,
    intBitsToFloat_ext,
    uintBitsToFloat_ext,

    fma_ext,
    frexp_ext,
    ldexp_ext,

    packSnorm4x8_ext,
    packUnorm4x8_ext,
    packSnorm2x16_ext,
    packUnorm2x16_ext,
    packHalf2x16_ext,
    packDouble2x32_ext,
    unpackSnorm2x16_ext,
    unpackUnorm2x16_ext,
    unpackHalf2x16_ext,
    unpackSnorm4x8_ext,
    unpackUnorm4x8_ext,
    unpackDouble2x32_ext,

    length_ext,
    distance_ext,
    cross_ext,
    normalize_ext,
    ftransform_ext,
    faceForward_ext,
    reflect_ext,
    refract_ext,

    uaddCarry_ext,
    usubBorrow_ext,
    umulExtended_ext,
    imulExtended_ext,
    bitfieldExtract_ext,
    bitfieldInsert_ext,
    bitfieldReverse_ext,
    bitCount_ext,
    findLSB_ext,
    findMSB_ext,

    interpolateAtCentroid_ext,
    interpolateAtSample_ext,
    interpolateAtOffset_ext,
  };

  EXT_EXPORT_TABLE_FUNC(exports)

#ifdef __cplusplus
}
#endif