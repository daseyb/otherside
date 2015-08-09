/*
Version: 99
Generator Magic: 85590203
ID Bound: 68
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
typedef * p__13;
struct v_float_7_2_16 {
  float_7 v[2];
};
typedef v_float_7_2_16* p_v_float_7_2_16_17;
struct v_float_7_3_22 {
  float_7 v[3];
};
typedef float_7* p_float_7_26;
struct Light {
  v_float_7_4_8 color;
  v_float_7_2_16 color;
};
typedef Light* p_Light_30;
typedef int32 int_32;
typedef v_float_7_2_16* p_v_float_7_2_16_34;
typedef v_float_7_4_8* p_v_float_7_4_8_42;
typedef v_float_7_4_8* p_v_float_7_4_8_50;

static p__13 testTex;
static p_v_float_7_2_16_17 uv;
static p_Light_30 light;
static p_v_float_7_4_8_50 gl_FragColor;
static p_v_float_7_2_16_34 texSize;

int_32 c_33 = 1;
float_7 c_39 = 1;
int_32 c_41 = 0;
float_7 c_48 = 0;
float_7 c_59 = 2;

static void_2 main() {
//Label [5]
//Variable [9] [10] Function [0]
//Variable [26] [27] Function [0]
//Variable [26] [38] Function [0]
//Load [12] [15] [14] []
//Load [16] [19] [18] []
//ImageSampleImplicitLod [8] [20] [15] [19] []
//Store [10] [20] []
//Load [8] [21] [10] []
//VectorShuffle [22] [23] [21] [21] [0, 2, 0]
//Load [8] [24] [10] []
//VectorShuffle [8] [25] [24] [23] [4, 5, 6, 3]
//Store [10] [25] []
//Load [16] [28] [18] []
//AccessChain [34] [35] [31] [[33]]
//Load [16] [36] [35] []
//ExtInst [7] [37] [1] 66 [[28], [36]]
//Store [27] [37] []
//Load [7] [40] [27] []
//AccessChain [42] [43] [31] [[41]]
//Load [8] [44] [43] []
//CompositeExtract [7] [45] [44] [3]
//FDiv [7] [46] [40] [45]
//FSub [7] [47] [39] [46]
//ExtInst [7] [49] [1] 43 [[47], [48], [39]]
//Store [38] [49] []
//Load [8] [52] [10] []
//VectorShuffle [22] [53] [52] [52] [0, 1, 2]
//AccessChain [42] [54] [31] [[41]]
//Load [8] [55] [54] []
//VectorShuffle [22] [56] [55] [55] [0, 1, 2]
//Load [7] [57] [38] []
//VectorTimesScalar [22] [58] [56] [57]
//ExtInst [22] [61] [1] 26 [[58], [60]]
//FAdd [22] [62] [53] [61]
//Load [8] [63] [51] []
//VectorShuffle [8] [64] [63] [62] [4, 5, 6, 3]
//Store [51] [64] []
//Load [8] [65] [51] []
//CompositeInsert [8] [66] [39] [65] [3]
//Store [51] [66] []
//Branch [6]
//Label [6]
//Return
}

