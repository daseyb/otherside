/*
Version: 99
Generator Magic: 85590203
ID Bound: 87
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
struct v_float_7_3_8 {
  float_7 v[3];
};
typedef v_float_7_3_8* p_v_float_7_3_8_9;
typedef float_7* p_float_7_10;
struct lerp_res {
  v_float_7_3_8 val;
};
typedef lerp_res* p_lerp_res_18;
typedef v_float_7_3_8* p_v_float_7_3_8_31;
typedef bool bool_34;
typedef bool_34* p_bool_34_35;
typedef int32 int_40;
typedef int_40* p_int_40_41;
typedef int_40* p_int_40_47;
struct v_float_7_4_79 {
  float_7 v[4];
};
typedef v_float_7_4_79* p_v_float_7_4_79_80;

static p_v_float_7_3_8_31 color;
static p_bool_34_35 loopFlag;
static p_int_40_47 iterations;
static p_v_float_7_4_79_80 gl_FragColor;

int_40 c_43 = 0;
float_7 c_55 = 2;
int_40 c_68 = 1;
float_7 c_74 = 0;
float_7 c_77 = 1;

static void_2 main() {
//Label [5]
//Variable [9] [30] Function [0]
//Variable [41] [42] Function [0]
//Variable [18] [52] Function [0]
//Variable [9] [57] Function [0]
//Variable [9] [59] Function [0]
//Variable [10] [61] Function [0]
//Load [8] [33] [32]
//Store [30] [33]
//Load [34] [37] [36]
//SelectionMerge [39] Flatten
//BranchConditional [37] [38] [39]
//  Label [38]
//  Store [42] [43]
//  Branch [44]
//  Label [44]
//  Load [40] [46] [42]
//  Load [40] [49] [48]
//  SLessThan [34] [50] [46] [49]
//  LoopMerge [45] Unroll
//  BranchConditional [50] [51] [45]
//    Label [51]
//    Load [40] [53] [42]
//    ConvertSToF [7] [54] [53]
//    FDiv [7] [56] [54] [55]
//    Load [8] [58] [30]
//    Store [57] [58]
//    Load [8] [60] [32]
//    Store [59] [60]
//    Store [61] [56]
//    FunctionCall [11] [62] [16] [16102208] [0] [4261281277]
//    Store [52] [62]
//    AccessChain [9] [63] [52] [16102248]
//    Load [8] [64] [63]
//    Load [8] [65] [30]
//    FAdd [8] [66] [65] [64]
//    Store [30] [66]
//    Load [40] [67] [42]
//    IAdd [40] [69] [67] [68]
//    Store [42] [69]
//    Branch [44]
//  Label [45]
//  Branch [39]
//Label [39]
//Load [40] [70] [48]
//SGreaterThan [34] [71] [70] [43]
//SelectionMerge [73] Flatten
//BranchConditional [71] [72] [76]
//  Label [72]
//  Store [30] [75]
//  Branch [73]
//  Label [76]
//  Store [30] [78]
//  Branch [73]
//Label [73]
//Load [8] [82] [32]
//CompositeExtract [7] [83] [82] 16102556
//CompositeExtract [7] [84] [82] 16102576
//CompositeExtract [7] [85] [82] 16102596
//CompositeConstruct [79] [86] [16102612] [0] [4261281277] [1807288827]
//Store [81] [86]
//Branch [6]
//Label [6]
//Return
}

static lerp_res mlerp(vf3;vf3;f1;(p_v_float_7_3_8_9 a, p_v_float_7_3_8_9 b, p_float_7_10 t) {
//Label [17]
//Variable [18] [19] Function [0]
//Load [8] [20] [13]
//Load [8] [21] [14]
//Load [8] [22] [13]
//FSub [8] [23] [21] [22]
//Load [7] [24] [15]
//VectorTimesScalar [8] [25] [23] [24]
//FAdd [8] [26] [20] [25]
//CompositeConstruct [11] [27] [16102880]
//Store [19] [27]
//Load [11] [28] [19]
//ReturnValue [28]
}

