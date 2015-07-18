/*
Version: 99
Generator Magic: 85590203
ID Bound: 65
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
typedef v_float_7_2_15* p_v_float_7_2_15_28;
struct Light {
  v_float_7_4_8 color;
  v_float_7_2_15 color;
};
typedef Light* p_Light_33;
typedef int32 int_35;
typedef v_float_7_4_8* p_v_float_7_4_8_42;
typedef v_float_7_4_8* p_v_float_7_4_8_50;

static p__12 testTex;
static p_v_float_7_2_15_16 uv;
static p_v_float_7_2_15_28 texSize;
static p_Light_33 light;
static p_v_float_7_4_8_50 gl_FragColor;

int_35 c_36 = 1;
int_35 c_41 = 0;
float_7 c_47 = 2;
float_7 c_62 = 1;

static void_2 main() {
//Label [5]
//Variable [9] [10] Function [0]
//Variable [25] [26] Function [0]
//Variable [25] [40] Function [0]
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
//Load [15] [30] [29] []
//FMul [15] [31] [27] [30]
//AccessChain [28] [37] [34] [[36]]
//Load [15] [38] [37] []
//ExtInst [7] [39] [1] 59 [[31], [38]]
//Store [26] [39] []
//AccessChain [42] [43] [34] [[41]]
//Load [8] [44] [43] []
//CompositeExtract [7] [45] [44] [3]
//Load [7] [46] [26] []
//ExtInst [7] [48] [1] 23 [[46], [47]]
//FDiv [7] [49] [45] [48]
//Store [40] [49] []
//Load [8] [52] [10] []
//VectorShuffle [21] [53] [52] [52] [, 0, 12]
//AccessChain [42] [54] [34] [[41]]
//Load [8] [55] [54] []
//VectorShuffle [21] [56] [55] [55] [, 0, 12]
//Load [7] [57] [40] []
//VectorTimesScalar [21] [58] [56] [57]
//FAdd [21] [59] [53] [58]
//Load [8] [60] [51] []
//VectorShuffle [8] [61] [60] [59] [, 4, 5, 63]
//Store [51] [61] []
//Load [8] [63] [51] []
//CompositeInsert [8] [64] [62] [63] [3]
//Store [51] [64] []
//Branch [6]
//Label [6]
//Return
}

