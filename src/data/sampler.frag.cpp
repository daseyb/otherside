/*
Version: 99
Generator Magic: 85590203
ID Bound: 26
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

static p_v_float_7_4_8_9 gl_FragColor;
static p__12 testTex;
static p_v_float_7_2_15_16 uv;

float_7 c_23 = 1;

static void_2 main() {
//Label [5]
//Load [11] [14] [13] []
//Load [15] [18] [17] []
//TextureSample [8] [19] [14] [18] [0]
//Store [10] [19] []
//Load [8] [20] [10] []
//Load [8] [21] [10] []
//FMul [8] [22] [21] [20]
//Store [10] [22] []
//Load [8] [24] [10] []
//CompositeInsert [8] [25] [23] [24] [3]
//Store [10] [25] []
//Branch [6]
//Label [6]
//Return
}

