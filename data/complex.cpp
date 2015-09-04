/*
Version: 99
Generator Magic: 85590203
ID Bound: 91
Instruction Schema: 0
=================================================
*/

#include <stdint.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include "GLSL.std.450.h"

// Predefined types: 
// =================================================
typedef double float64;
typedef float float32;
typedef uint8_t uint8;
typedef uint16_t uint16;
typedef uint32_t uint32;
typedef uint64_t uint64;
typedef int8_t int8;
typedef int16_t int16;
typedef int32_t int32;
typedef int64_t int64;
// =================================================

struct v_float32_3 {
  float32 v[3];

  friend v_float32_3 operator+(v_float32_3 a, const v_float32_3& b) {
    a.v[0] += b.v[0];
    a.v[1] += b.v[1];
    a.v[2] += b.v[2];
    return a;
  }


  friend v_float32_3 operator-(v_float32_3 a, const v_float32_3& b) {
    a.v[0] -= b.v[0];
    a.v[1] -= b.v[1];
    a.v[2] -= b.v[2];
    return a;
  }


  friend v_float32_3 operator*(v_float32_3 a, const v_float32_3& b) {
    a.v[0] *= b.v[0];
    a.v[1] *= b.v[1];
    a.v[2] *= b.v[2];
    return a;
  }


  friend v_float32_3 operator/(v_float32_3 a, const v_float32_3& b) {
    a.v[0] /= b.v[0];
    a.v[1] /= b.v[1];
    a.v[2] /= b.v[2];
    return a;
  }

};
typedef v_float32_3* p_v_float32_3;
typedef float32* p_float32;
struct lerp_res {
  v_float32_3 val1;
  v_float32_3 val1;
};
typedef lerp_res* p_lerp_res;
typedef v_float32_3* p_v_float32_3;
typedef bool* p_bool;
typedef int32* p_int32;
typedef int32* p_int32;
struct v_float32_4 {
  float32 v[4];

  friend v_float32_4 operator+(v_float32_4 a, const v_float32_4& b) {
    a.v[0] += b.v[0];
    a.v[1] += b.v[1];
    a.v[2] += b.v[2];
    a.v[3] += b.v[3];
    return a;
  }


  friend v_float32_4 operator-(v_float32_4 a, const v_float32_4& b) {
    a.v[0] -= b.v[0];
    a.v[1] -= b.v[1];
    a.v[2] -= b.v[2];
    a.v[3] -= b.v[3];
    return a;
  }


  friend v_float32_4 operator*(v_float32_4 a, const v_float32_4& b) {
    a.v[0] *= b.v[0];
    a.v[1] *= b.v[1];
    a.v[2] *= b.v[2];
    a.v[3] *= b.v[3];
    return a;
  }


  friend v_float32_4 operator/(v_float32_4 a, const v_float32_4& b) {
    a.v[0] /= b.v[0];
    a.v[1] /= b.v[1];
    a.v[2] /= b.v[2];
    a.v[3] /= b.v[3];
    return a;
  }

};
typedef v_float32_4* p_v_float32_4;

static p_v_float32_3 color;
static p_bool loopFlag;
static p_int32 iterations;
static p_v_float32_4 gl_FragColor;

const float32 c_22 = 0.000000f;
const int32 c_47 = 0;
const int32 c_68 = 1;
const float32 c_81 = 1.000000f;

void spv_main() {
  label_5:
}

lerp_res spv_mlerp()vf3;vf3;f1;(p_v_float32_3 a, p_v_float32_3 b, p_float32 t) {
 = (p_lerp_res)malloc(sizeof(lerp_res));v_float32_3 var_24;v_float32_3 var_25;v_float32_3 var_26;float32 var_28;v_float32_3 var_30;lerp_res var_31;lerp_res var_32;  label_17:
  p_lerp_res Result
  var_24 = *;
  var_25 = *;
  var_26 = *;
  // FSub [8] [27] [25] [26]

  var_28 = *;
  // VectorTimesScalar [8] [29] [27] [28]

  var_30 = var_24 + ;
  var_31 = {, var_30};
  *Result = var_31;
  var_32 = *Result;
  // ReturnValue [32]

}

void spv_main()() {
 = (p_v_float32_3)malloc(sizeof(v_float32_3)); = (p_int32)malloc(sizeof(int32)); = (p_lerp_res)malloc(sizeof(lerp_res)); = (p_v_float32_3)malloc(sizeof(v_float32_3)); = (p_v_float32_3)malloc(sizeof(v_float32_3)); = (p_float32)malloc(sizeof(float32));v_float32_3 var_37;bool var_41;int32 var_51;int32 var_54;bool var_55;int32 var_57;int32 var_59;v_float32_3 var_63;v_float32_3 var_65;v_float32_3 var_70;v_float32_3 var_71;v_float32_3 var_72;int32 var_73;int32 var_74;int32 var_76;bool var_77;v_float32_3 var_86;float32 var_87;float32 var_88;float32 var_89;v_float32_4 var_90;  label_19:
  p_v_float32_3 currColor
  p_int32 i
  p_lerp_res res
  p_v_float32_3 mlerp()vf3;vf3;f1;param0
  p_v_float32_3 mlerp()vf3;vf3;f1;param1
  p_float32 mlerp()vf3;vf3;f1;param2
  var_37 = *color;
  *currColor = var_37;
  var_41 = *loopFlag;
  // SelectionMerge [43] Flatten

  if(var_41) { goto label_42; }
  else { goto label_75; }
    label_42:
    *i = c_47;
    goto label_48;
    label_48:
    var_51 = *i;
    var_54 = *iterations;
    var_55 = var_51 < var_54;
    // LoopMerge [49] Unroll

    if(var_55) { goto label_50; }
    else { goto label_49; }
      label_50:
      var_57 = *i;
      // ConvertSToF [7] [58] [57]

      var_59 = *iterations;
      // ConvertSToF [7] [60] [59]

      // FDiv [7] [61] [58] [60]

      var_63 = *currColor;
      *mlerp()vf3;vf3;f1;param0 = var_63;
      var_65 = *color;
      *mlerp()vf3;vf3;f1;param1 = var_65;
      *mlerp()vf3;vf3;f1;param2 = ;
      // FunctionCall [11(lerp_res)] [67] [16(mlerp()vf3;vf3;f1;)] [[62(mlerp()vf3;vf3;f1;param0)], [64(mlerp()vf3;vf3;f1;param1)], [66(mlerp()vf3;vf3;f1;param2)]]

      *res = ;
      // AccessChain [9] [69] [56(res)] [[68]]

      var_70 = *;
      var_71 = *currColor;
      var_72 = var_71 + var_70;
      *currColor = var_72;
      var_73 = *i;
      var_74 = var_73 + c_68;
      *i = var_74;
      goto label_48;
    label_49:
    goto label_43;
    label_75:
    var_76 = *iterations;
    var_77 = var_76 > c_47;
    // SelectionMerge [79] Flatten

    if(var_77) { goto label_78; }
    else { goto label_80; }
      label_78:
      *currColor = ;
      goto label_79;
      label_80:
      *currColor = ;
      goto label_79;
    label_79:
    goto label_43;
  label_43:
  var_86 = *currColor;
  var_87 = var_86.v[0];
  var_88 = var_86.v[1];
  var_89 = var_86.v[2];
  var_90 = {var_87, var_88, var_89, c_81};
  *gl_FragColor = var_90;
  return;
}

