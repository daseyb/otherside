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
// [5]	= Label
// [9]	= Variable [10(col)] Function [0]
// [26]	= Variable [27(lightDist)] Function [0]
// [26]	= Variable [38(intensity)] Function [0]
// [12]	= Load [15] [14(testTex)] []
// [16]	= Load [19] [18(uv)] []
// [8]	= ImageSampleImplicitLod [20] [15] [19] []
// [10(col)]	= Store [20] []
// [8]	= Load [21] [10(col)] []
// [22]	= VectorShuffle [23] [21] [21] [0, 2, 0]
// [8]	= Load [24] [10(col)] []
// [8]	= VectorShuffle [25] [24] [23] [4, 5, 6, 3]
// [10(col)]	= Store [25] []
// [16]	= Load [28] [18(uv)] []
// [34]	= AccessChain [35] [31(light)] [[33]]
// [16]	= Load [36] [35] []
// [7]	= ExtInst [37] [1] 66 [[28], [36]]
// [27(lightDist)]	= Store [37] []
// [7]	= Load [40] [27(lightDist)] []
// [42]	= AccessChain [43] [31(light)] [[41]]
// [8]	= Load [44] [43] []
// [7]	= CompositeExtract [45] [44] [3]
// [7]	= FDiv [46] [40] [45]
// [7]	= FSub [47] [39] [46]
// [7]	= ExtInst [49] [1] 43 [[47], [48], [39]]
// [38(intensity)]	= Store [49] []
// [8]	= Load [52] [10(col)] []
// [22]	= VectorShuffle [53] [52] [52] [0, 1, 2]
// [42]	= AccessChain [54] [31(light)] [[41]]
// [8]	= Load [55] [54] []
// [22]	= VectorShuffle [56] [55] [55] [0, 1, 2]
// [7]	= Load [57] [38(intensity)] []
// [22]	= VectorTimesScalar [58] [56] [57]
// [22]	= ExtInst [61] [1] 26 [[58], [60]]
// [22]	= FAdd [62] [53] [61]
// [8]	= Load [63] [51(gl_FragColor)] []
// [8]	= VectorShuffle [64] [63] [62] [4, 5, 6, 3]
// [51(gl_FragColor)]	= Store [64] []
// [8]	= Load [65] [51(gl_FragColor)] []
// [8]	= CompositeInsert [66] [39] [65] [3]
// [51(gl_FragColor)]	= Store [66] []
// [6]	= Branch
// [6]	= Label
//Return
}

