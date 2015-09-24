/*
Version: 99
Generator Magic: 85590203
ID Bound: 68
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

struct v_float32_4 {
    float32 v[4];

    friend v_float32_4 operator+(v_float32_4 a, const v_float32_4 &b) {
      a.v[0] += b.v[0];
      a.v[1] += b.v[1];
      a.v[2] += b.v[2];
      a.v[3] += b.v[3];
      return a;
    }


    friend v_float32_4 operator-(v_float32_4 a, const v_float32_4 &b) {
      a.v[0] -= b.v[0];
      a.v[1] -= b.v[1];
      a.v[2] -= b.v[2];
      a.v[3] -= b.v[3];
      return a;
    }


    friend v_float32_4 operator*(v_float32_4 a, const v_float32_4 &b) {
      a.v[0] *= b.v[0];
      a.v[1] *= b.v[1];
      a.v[2] *= b.v[2];
      a.v[3] *= b.v[3];
      return a;
    }


    friend v_float32_4 operator/(v_float32_4 a, const v_float32_4 &b) {
      a.v[0] /= b.v[0];
      a.v[1] /= b.v[1];
      a.v[2] /= b.v[2];
      a.v[3] /= b.v[3];
      return a;
    }

};

typedef v_float32_4 *p_v_float32_4;
typedef *
p_;

struct v_float32_2 {
    float32 v[2];

    friend v_float32_2 operator+(v_float32_2 a, const v_float32_2 &b) {
      a.v[0] += b.v[0];
      a.v[1] += b.v[1];
      return a;
    }


    friend v_float32_2 operator-(v_float32_2 a, const v_float32_2 &b) {
      a.v[0] -= b.v[0];
      a.v[1] -= b.v[1];
      return a;
    }


    friend v_float32_2 operator*(v_float32_2 a, const v_float32_2 &b) {
      a.v[0] *= b.v[0];
      a.v[1] *= b.v[1];
      return a;
    }


    friend v_float32_2 operator/(v_float32_2 a, const v_float32_2 &b) {
      a.v[0] /= b.v[0];
      a.v[1] /= b.v[1];
      return a;
    }

};

typedef v_float32_2 *p_v_float32_2;

struct v_float32_3 {
    float32 v[3];

    friend v_float32_3 operator+(v_float32_3 a, const v_float32_3 &b) {
      a.v[0] += b.v[0];
      a.v[1] += b.v[1];
      a.v[2] += b.v[2];
      return a;
    }


    friend v_float32_3 operator-(v_float32_3 a, const v_float32_3 &b) {
      a.v[0] -= b.v[0];
      a.v[1] -= b.v[1];
      a.v[2] -= b.v[2];
      return a;
    }


    friend v_float32_3 operator*(v_float32_3 a, const v_float32_3 &b) {
      a.v[0] *= b.v[0];
      a.v[1] *= b.v[1];
      a.v[2] *= b.v[2];
      return a;
    }


    friend v_float32_3 operator/(v_float32_3 a, const v_float32_3 &b) {
      a.v[0] /= b.v[0];
      a.v[1] /= b.v[1];
      a.v[2] /= b.v[2];
      return a;
    }

};

typedef float32 *p_float32;
struct Light {
    v_float32_4 color;
    v_float32_2 color;
};
typedef Light *p_Light;
typedef v_float32_2 *p_v_float32_2;
typedef v_float32_4 *p_v_float32_4;
typedef v_float32_4 *p_v_float32_4;

static p_ testTex;
static p_v_float32_2 uv;
static p_Light light;
static p_v_float32_4 gl_FragColor;
static p_v_float32_2 texSize;

const int32 c_33 = 1;
const float32 c_39 = 1f;
const int32 c_41 = 0;
const float32 c_48 = 0f;
const float32 c_59 = 2f;

void spv_main() {
  p_v_float32_4 col = (p_v_float32_4) malloc(sizeof(v_float32_4));
  p_float32 lightDist = (p_float32) malloc(sizeof(float32));
  p_float32 intensity = (p_float32) malloc(sizeof(float32));
  var_15;
  v_float32_2 var_19;
  v_float32_4 var_21;
  v_float32_4 var_24;
  v_float32_2 var_28;
  v_float32_2 var_36;
  float32 var_40;
  v_float32_4 var_44;
  float32 var_45;
  v_float32_4 var_52;
  v_float32_4 var_55;
  float32 var_57;
  v_float32_3 var_62;
  v_float32_4 var_63;
  v_float32_4 var_65;
  label_5:
  var_15 = *testTex;
  var_19 = *uv;
  // ImageSampleImplicitLod [8] [20] [15] [19] []

  *col =;
  var_21 = *col;
  // VectorShuffle [22] [23] [21] [21] [0, 2, 0]

  var_24 = *col;
  // VectorShuffle [8] [25] [24] [23] [4, 5, 6, 3]

  *col =;
  var_28 = *uv;
  // AccessChain [34] [35] [31(light)] [[33]]

  var_36 = *;
  // ExtInst [7] [37] [1] 66 [[28], [36]]

  *lightDist =;
  var_40 = *lightDist;
  // AccessChain [42] [43] [31(light)] [[41]]

  var_44 = *;
  var_45 = var_44.v[3];
  // FDiv [7] [46] [40] [45]

  // FSub [7] [47] [39] [46]

  // ExtInst [7] [49] [1] 43 [[47], [48], [39]]

  *intensity =;
  var_52 = *col;
  // VectorShuffle [22] [53] [52] [52] [0, 1, 2]

  // AccessChain [42] [54] [31(light)] [[41]]

  var_55 = *;
  // VectorShuffle [22] [56] [55] [55] [0, 1, 2]

  var_57 = *intensity;
  // VectorTimesScalar [22] [58] [56] [57]

  // ExtInst [22] [61] [1] 26 [[58], [60]]

  var_62 = +;
  var_63 = *gl_FragColor;
  // VectorShuffle [8] [64] [63] [62] [4, 5, 6, 3]

  *gl_FragColor =;
  var_65 = *gl_FragColor;
  // CompositeInsert [8] [66] [39] [65] [3]

  *gl_FragColor =;
  goto label_6;
  label_6:
  return;
}

