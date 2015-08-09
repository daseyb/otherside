/*
Version: 99
Generator Magic: 85590203
ID Bound: 89
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
  v_float_7_3_8 val1;
  v_float_7_3_8 val1;
};
typedef lerp_res* p_lerp_res_18;
typedef v_float_7_3_8* p_v_float_7_3_8_33;
typedef bool bool_36;
typedef bool_36* p_bool_36_37;
typedef int32 int_42;
typedef int_42* p_int_42_43;
typedef int_42* p_int_42_50;
struct v_float_7_4_81 {
  float_7 v[4];
};
typedef v_float_7_4_81* p_v_float_7_4_81_82;

static p_v_float_7_3_8_33 color;
static p_bool_36_37 loopFlag;
static p_int_42_50 iterations;
static p_v_float_7_4_81_82 gl_FragColor;

float_7 c_20 = 0;
int_42 c_45 = 0;
int_42 c_66 = 1;
float_7 c_79 = 1;

static void_2 main() {
//Label [5]
//Variable [9] [32] Function [0]
//Variable [43] [44] Function [0]
//Variable [18] [54] Function [0]
//Variable [9] [60] Function [0]
//Variable [9] [62] Function [0]
//Variable [10] [64] Function [0]
//Load [8] [35] [34] []
//Store [32] [35] []
//Load [36] [39] [38] []
//SelectionMerge [41] Flatten
//BranchConditional [39] [40] [73] []
//  Label [40]
//  Store [44] [45] []
//  Branch [46]
//  Label [46]
//  Load [42] [49] [44] []
//  Load [42] [52] [51] []
//  SLessThan [36] [53] [49] [52]
//  LoopMerge [47] Unroll
//  BranchConditional [53] [48] [47] []
//    Label [48]
//    Load [42] [55] [44] []
//    ConvertSToF [7] [56] [55]
//    Load [42] [57] [51] []
//    ConvertSToF [7] [58] [57]
//    FDiv [7] [59] [56] [58]
//    Load [8] [61] [32] []
//    Store [60] [61] []
//    Load [8] [63] [34] []
//    Store [62] [63] []
//    Store [64] [59] []
//    FunctionCall [11] [65] [16] [[60], [62], [64]]
//    Store [54] [65] []
//    AccessChain [9] [67] [54] [[66]]
//    Load [8] [68] [67] []
//    Load [8] [69] [32] []
//    FAdd [8] [70] [69] [68]
//    Store [32] [70] []
//    Load [42] [71] [44] []
//    IAdd [42] [72] [71] [66]
//    Store [44] [72] []
//    Branch [46]
//  Label [47]
//  Branch [41]
//  Label [73]
//  Load [42] [74] [51] []
//  SGreaterThan [36] [75] [74] [45]
//  SelectionMerge [77] Flatten
//  BranchConditional [75] [76] [78] []
//    Label [76]
//    Store [32] [21] []
//    Branch [77]
//    Label [78]
//    Store [32] [80] []
//    Branch [77]
//  Label [77]
//  Branch [41]
//Label [41]
//Load [8] [84] [32] []
//CompositeExtract [7] [85] [84] [0]
//CompositeExtract [7] [86] [84] [1]
//CompositeExtract [7] [87] [84] [2]
//CompositeConstruct [81] [88] [[85], [86], [87], [79]]
//Store [83] [88] []
//Branch [6]
//Label [6]
//Return
}

static lerp_res mlerp(vf3;vf3;f1;(p_v_float_7_3_8_9 a, p_v_float_7_3_8_9 b, p_float_7_10 t) {
//Label [17]
//Variable [18] [19] Function [0]
//Load [8] [22] [13] []
//Load [8] [23] [14] []
//Load [8] [24] [13] []
//FSub [8] [25] [23] [24]
//Load [7] [26] [15] []
//VectorTimesScalar [8] [27] [25] [26]
//FAdd [8] [28] [22] [27]
//CompositeConstruct [11] [29] [[21], [28]]
//Store [19] [29] []
//Load [11] [30] [19] []
//ReturnValue [30]
}

