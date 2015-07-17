/*
Version: 99
Generator Magic: 85590203
ID Bound: 31
Instruction Schema: 0
=================================================
*/

#include <stdint.h>
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

typedef void void_2;
typedef float32 float_7;
struct v_float_7_4_8 {
  float_7 v[4];
};
typedef v_float_7_4_8* p_v_float_7_4_8_9;
typedef * p__12;
struct v_float_7_2_15 {
  float_7 v[2];
};
typedef v_float_7_2_15* p_v_float_7_2_15_16;
struct v_float_7_3_21 {
  float_7 v[3];
};
typedef v_float_7_4_8* p_v_float_7_4_8_25;

static p__12 testTex;
static p_v_float_7_2_15_16 uv;
static p_v_float_7_4_8_25 gl_FragColor;

float_7 c_28 = 1;

static void_2 main() {
//Label [5]
//Variable [9] [10] Function [0]
//Load [11] [14] [13] []
//Load [15] [18] [17] []
//TextureSample [8] [19] [14] [18] [0]
//Store [10] [19] []
//Load [8] [20] [10] []
//VectorShuffle [21] [22] [20] [20] [, 0, 20]
//Load [8] [23] [10] []
//VectorShuffle [8] [24] [23] [22] [, 4, 5, 63]
//Store [10] [24] []
//Load [8] [27] [10] []
//Store [26] [27] []
//Load [8] [29] [26] []
//CompositeInsert [8] [30] [28] [29] [3]
//Store [26] [30] []
//Branch [6]
//Label [6]
//Return
}

