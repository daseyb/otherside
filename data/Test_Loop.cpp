/*
Version: 99
Generator Magic: 85590203
ID Bound: 42
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
typedef v_float32_3* p_v_float32_3;
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
static p_int32 iterations;
static p_v_float32_4 gl_FragColor;

const int32 c_17 = 0;
const int32 c_31 = 1;
const float32 c_37 = 1.000000f;

void main() {
  label_5:
  p_v_float32_3 currColor = (p_v_float32_3)malloc(sizeof(v_float32_3));
  p_int32 i = (p_int32)malloc(sizeof(int32));
  v_float32_3 var_13 = *color;
  *currColor = var_13;
  *i = c_17;
  goto label_18;
  label_18:
  int32 var_21 = *i;
  int32 var_24 = *iterations;
  bool var_26 = var_21 < var_24;
  // LoopMerge [19] Unroll

  if(var_26) { goto label_20; }
  else { goto label_19; }
    label_20:
    v_float32_3 var_27 = *color;
    v_float32_3 var_28 = *currColor;
    v_float32_3 var_29 = var_28 + var_27;
    *currColor = var_29;
    int32 var_30 = *i;
    int32 var_32 = var_30 + c_31;
    *i = var_32;
    goto label_18;
  label_19:
  v_float32_3 var_36 = *currColor;
  float32 var_38 = var_36.v[0];
  float32 var_39 = var_36.v[1];
  float32 var_40 = var_36.v[2];
  v_float32_4 var_41 = {var_38, var_39, var_40, c_37};
  *gl_FragColor = var_41;
  goto label_6;
  label_6:
  return;
}

