#include "vm.h"
#include <assert.h>
#include <math.h>

#ifdef __cplusplus
extern "C" {
#endif

  #define ONE_ARG_OP(func, type) \
    assert(valueCount == 1); \
    return vm->DoOp(resultTypeId, [](Value val) {return func(*(type*)val.Memory); }, values[0]); \

  #define TWO_ARG_OP(func, type) \
    assert(valueCount == 2); \
    return vm->DoOp(resultTypeId, [](Value op1, Value op2) {return func(*(type*)op1.Memory, *(type*)op2.Memory); }, values[0], values[1]); \

  #define THREE_ARG_OP(func, type) \
    assert(valueCount == 3); \
    return vm->DoOp(resultTypeId, [](Value op1, Value op2, Value op3) {return func(*(type*)op1.Memory, *(type*)op2.Memory, *(type*)op3.Memory); }, values[0], values[1], values[2]); \


  #define ONE_ARG_OP_F(func) ONE_ARG_OP(func, float)
  #define TWO_ARG_OP_F(func) TWO_ARG_OP(func, float)
  #define THREE_ARG_OP_F(func) TWO_ARG_OP(func, float)
  
  #define ONE_ARG_OP_S(func) ONE_ARG_OP(func, int)
  #define TWO_ARG_OP_S(func) TWO_ARG_OP(func, int)
  #define THREE_ARG_OP_S(func) TWO_ARG_OP(func, int)
  
  #define THREE_ARG_OP_D(func) \
    assert(valueCount == 3); \
    return vm->DoOp(resultTypeId, func, values[0], values[1], values[2]); \

  EXT_INST_FUNC(round_ext) {
    ONE_ARG_OP_F(roundf);
  };

  EXT_INST_FUNC(roundEven_ext) {
    return values[0];
  };

  EXT_INST_FUNC(trunc_ext) {
    ONE_ARG_OP_F(trunc);
  };

  EXT_INST_FUNC(fabs_ext) {
    ONE_ARG_OP_F(fabsf);
  };

  EXT_INST_FUNC(sabs_ext) {
    ONE_ARG_OP_S([](int s) { return s < 0 ? -s : s; });
  };

  EXT_INST_FUNC(fsign_ext) {
    ONE_ARG_OP_F([](float f) { return signbit(f) ? 0 : 1;})
  };

  EXT_INST_FUNC(ssign_ext) {
    ONE_ARG_OP_S([](int s) { return s < 0 ? 0 : 1;})
  };

  EXT_INST_FUNC(floor_ext) {
    ONE_ARG_OP_F(floorf);
  };

  EXT_INST_FUNC(ceil_ext) {
    ONE_ARG_OP_F(ceilf);
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
    ONE_ARG_OP_F(sinf);
  };

  EXT_INST_FUNC(cos_ext) {
    ONE_ARG_OP_F(cosf);
  };

  EXT_INST_FUNC(tan_ext) {
    ONE_ARG_OP_F(tanf);
  };

  EXT_INST_FUNC(asin_ext) {
    ONE_ARG_OP_F(asinf);
  };

  EXT_INST_FUNC(acos_ext) {
    ONE_ARG_OP_F(acosf);
  };

  EXT_INST_FUNC(atan_ext) {
    ONE_ARG_OP_F(atanf);
  };

  EXT_INST_FUNC(sinh_ext) {
    ONE_ARG_OP_F(sinhf);
  }

  EXT_INST_FUNC(cosh_ext) {
    ONE_ARG_OP_F(coshf);
  }

  EXT_INST_FUNC(tanh_ext) {
    ONE_ARG_OP_F(tanhf);
  }
  
  EXT_INST_FUNC(asinh_ext) {
    ONE_ARG_OP_F(asinhf);
  }
  
  EXT_INST_FUNC(acosh_ext) {
    ONE_ARG_OP_F(acoshf);
  }

  EXT_INST_FUNC(atanh_ext) {
    ONE_ARG_OP_F(atanhf);
  }

  EXT_INST_FUNC(atan2_ext) { 
    TWO_ARG_OP_F(atan2f); 
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

  EXT_INST_FUNC(exp_ext) { ONE_ARG_OP_F(expf); }
  EXT_INST_FUNC(log_ext) { ONE_ARG_OP_F(logf); }
  EXT_INST_FUNC(exp2_ext) { ONE_ARG_OP_F(exp2f); }
  EXT_INST_FUNC(log2_ext) { ONE_ARG_OP_F(log2f); }
  EXT_INST_FUNC(sqrt_ext) { ONE_ARG_OP_F(sqrtf); }
  EXT_INST_FUNC(inverseSqrt_ext) { ONE_ARG_OP_F([](float f) {return 1.0f / sqrtf(f);}) }

  EXT_INST_FUNC(determinant_ext) { return values [0]; }
  EXT_INST_FUNC(matrixInverse_ext) { return values [0]; }

  EXT_INST_FUNC(modf_ext) { TWO_ARG_OP_F(fmodf); }

  EXT_INST_FUNC(modf_struct_ext) { TWO_ARG_OP_F(fmodf); }

  EXT_INST_FUNC(fmin_ext) { return values [0]; }
  EXT_INST_FUNC(umin_ext) { return values [0]; }
  EXT_INST_FUNC(smin_ext) { return values [0]; }

  EXT_INST_FUNC(fmax_ext) { return values [0]; }
  EXT_INST_FUNC(umax_ext) { return values [0]; }
  EXT_INST_FUNC(smax_ext) { return values [0]; }

  EXT_INST_FUNC(fclamp_ext) { THREE_ARG_OP_D(Clamp<float>); }
  EXT_INST_FUNC(uclamp_ext) { THREE_ARG_OP_D(Clamp<unsigned int>); }
  EXT_INST_FUNC(sclamp_ext) { THREE_ARG_OP_D(Clamp<int>); }

  EXT_INST_FUNC(mix_ext) { return values [0]; }
  EXT_INST_FUNC(step_ext) { return values [0]; }
  EXT_INST_FUNC(smoothStep_ext) { return values [0]; }

  EXT_INST_FUNC(floatBitsToInt_ext) { return values [0]; }
  EXT_INST_FUNC(floatBitsToUint_ext) { return values [0]; }
  EXT_INST_FUNC(intBitsToFloat_ext) { return values [0]; }
  EXT_INST_FUNC(uintBitsToFloat_ext) { return values [0]; }

  EXT_INST_FUNC(fma_ext) { return values [0]; }
  EXT_INST_FUNC(frexp_ext) { return values [0]; }
  EXT_INST_FUNC(frexp_struct_ext) { return values [0]; }
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
  EXT_INST_FUNC(faceForward_ext) { return values [0]; }
  EXT_INST_FUNC(reflect_ext) { return values [0]; }
  EXT_INST_FUNC(refract_ext) { return values [0]; }

  EXT_INST_FUNC(findILSB_ext) { return values [0]; }
  EXT_INST_FUNC(findSMSB_ext) { return values [0]; }
  EXT_INST_FUNC(findUMSB_ext) { return values [0]; }

  EXT_INST_FUNC(interpolateAtCentroid_ext) { return values [0]; }
  EXT_INST_FUNC(interpolateAtSample_ext) { return values [0]; }
  EXT_INST_FUNC(interpolateAtOffset_ext) { return values [0]; }

  EXT_INST_FUNC(addCarry_ext) { return values [0]; }
  EXT_INST_FUNC(subBorrow_ext) { return values [0]; }
  EXT_INST_FUNC(mulExtended_ext) { return values [0]; }


  ExtInstFunc* exports[]{
    nullptr,
    
    round_ext,
    roundEven_ext,
    trunc_ext,
    fabs_ext,
    sabs_ext,
    fsign_ext,
    ssign_ext,
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
    modf_struct_ext,
    fmin_ext,
    umin_ext,
    smin_ext,
    fmax_ext,
    umax_ext,
    smax_ext,
    fclamp_ext,
    uclamp_ext,
    sclamp_ext,
    mix_ext,
    step_ext,
    smoothStep_ext,

    fma_ext,
    frexp_ext,
    frexp_struct_ext,
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
    faceForward_ext,
    reflect_ext,
    refract_ext,

    findILSB_ext,
    findSMSB_ext,
    findUMSB_ext,

    interpolateAtCentroid_ext,
    interpolateAtSample_ext,
    interpolateAtOffset_ext,

    addCarry_ext,
    subBorrow_ext,
    mulExtended_ext,
  };

  EXT_EXPORT_TABLE_FUNC(exports)

#ifdef __cplusplus
}
#endif
