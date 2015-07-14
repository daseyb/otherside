/*
Version: 99
Generator Magic: 85590203
ID Bound: 90
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
typedef int_42* p_int_42_49;
struct v_float_7_4_82 {
  float_7 v[4];
};
typedef v_float_7_4_82* p_v_float_7_4_82_83;

static p_v_float_7_3_8_33 color;
static p_bool_36_37 loopFlag;
static p_int_42_49 iterations;
static p_v_float_7_4_82_83 gl_FragColor;

float_7 c_20 = 0;
int_42 c_45 = 0;
int_42 c_58 = 1;
float_7 c_80 = 1;

static void_2 main() {
//Label [5]
//Variable [9] [32] Function [0]
//Variable [43] [44] Function [0]
//Variable [18] [54] Function [0]
//Variable [9] [62] Function [0]
//Variable [9] [64] Function [0]
//Variable [10] [66] Function [0]
//Load [8] [35] [34] []
//Store [32] [35] []
//Load [36] [39] [38] []
//SelectionMerge [41] Flatten
//BranchConditional [39] [40] [74] []
//  Label [40]
//  Store [44] [45] []
//  Branch [46]
//  Label [46]
//  Load [42] [48] [44] []
//  Load [42] [51] [50] []
//  SLessThan [36] [52] [48] [51]
//  LoopMerge [47] Unroll
//  BranchConditional [52] [53] [47] []
//    Label [53]
//    Load [42] [55] [44] []
//    ConvertSToF [7] [56] [55]
//    Load [42] [57] [50] []
//    IAdd [42] [59] [57] [58]
//    ConvertSToF [7] [60] [59]
//    FDiv [7] [61] [56] [60]
//    Load [8] [63] [32] []
//    Store [62] [63] []
//    Load [8] [65] [34] []
//    Store [64] [65] []
//    Store [66] [61] []
//    FunctionCall [11] [67] [16] [[62], [64], [66]]
//    Store [54] [67] []
//    AccessChain [9] [68] [54] [[58]]
//    Load [8] [69] [68] []
//    Load [8] [70] [32] []
//    FAdd [8] [71] [70] [69]
//    Store [32] [71] []
//    Load [42] [72] [44] []
//    IAdd [42] [73] [72] [58]
//    Store [44] [73] []
//    Branch [46]
//  Label [47]
//  Branch [41]
//  Label [74]
//  Load [42] [75] [50] []
//  SGreaterThan [36] [76] [75] [45]
//  SelectionMerge [78] Flatten
//  BranchConditional [76] [77] [79] []
//    Label [77]
//    Store [32] [21] []
//    Branch [78]
//    Label [79]
//    Store [32] [81] []
//    Branch [78]
//  Label [78]
//  Branch [41]
//Label [41]
//Load [8] [85] [32] []
//CompositeExtract [7] [86] [85] [0]
//CompositeExtract [7] [87] [85] [1]
//CompositeExtract [7] [88] [85] [2]
//CompositeConstruct [82] [89] [[86], [87], [88], [80]]
//Store [84] [89] []
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

