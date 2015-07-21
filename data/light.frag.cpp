/*
Version: 99
Generator Magic: 85590203
ID Bound: 67
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
typedef float_7* p_float_7_25;
struct Light {
  v_float_7_4_8 color;
  v_float_7_2_15 color;
};
typedef Light* p_Light_29;
typedef int32 int_31;
typedef v_float_7_2_15* p_v_float_7_2_15_33;
typedef v_float_7_4_8* p_v_float_7_4_8_41;
typedef v_float_7_4_8* p_v_float_7_4_8_49;

static p__12 testTex;
static p_v_float_7_2_15_16 uv;
static p_Light_29 light;
static p_v_float_7_4_8_49 gl_FragColor;
static p_v_float_7_2_15_33 texSize;

int_31 c_32 = 1;
float_7 c_38 = 1;
int_31 c_40 = 0;
float_7 c_47 = 0;
float_7 c_58 = 2;

static void_2 main() {
//Label [5]
//Variable [9] [10] Function [0]
//Variable [25] [26] Function [0]
//Variable [25] [37] Function [0]
//Load [11] [14] [13] []
//Load [15] [18] [17] []
//TextureSample [8] [19] [14] [18] [0]
//Store [10] [19] []
//Load [8] [20] [10] []
//VectorShuffle [21] [22] [20] [20] [, 0, 20]
//Load [8] [23] [10] []
//VectorShuffle [8] [24] [23] [22] [, 4, 5, 63]
//Store [10] [24] []
//Load [15] [27] [17] []
//AccessChain [33] [34] [30] [[32]]
//Load [15] [35] [34] []
//ExtInst [7] [36] [1] 59 [[27], [35]]
//Store [26] [36] []
//Load [7] [39] [26] []
//AccessChain [41] [42] [30] [[40]]
//Load [8] [43] [42] []
//CompositeExtract [7] [44] [43] [3]
//FDiv [7] [45] [39] [44]
//FSub [7] [46] [38] [45]
//ExtInst [7] [48] [1] 35 [[46], [47], [38]]
//Store [37] [48] []
//Load [8] [51] [10] []
//VectorShuffle [21] [52] [51] [51] [, 0, 12]
//AccessChain [41] [53] [30] [[40]]
//Load [8] [54] [53] []
//VectorShuffle [21] [55] [54] [54] [, 0, 12]
//Load [7] [56] [37] []
//VectorTimesScalar [21] [57] [55] [56]
//ExtInst [21] [60] [1] 23 [[57], [59]]
//FAdd [21] [61] [52] [60]
//Load [8] [62] [50] []
//VectorShuffle [8] [63] [62] [61] [, 4, 5, 63]
//Store [50] [63] []
//Load [8] [64] [50] []
//CompositeInsert [8] [65] [38] [64] [3]
//Store [50] [65] []
//Branch [6]
//Label [6]
//Return
}

