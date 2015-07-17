/*
Version: 99
Generator Magic: 85590203
ID Bound: 42
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
typedef v_float_7_3_8* p_v_float_7_3_8_11;
typedef int32 int_14;
typedef int_14* p_int_14_15;
typedef int_14* p_int_14_21;
typedef bool bool_24;
struct v_float_7_4_33 {
  float_7 v[4];
};
typedef v_float_7_4_33* p_v_float_7_4_33_34;

static p_v_float_7_3_8_11 color;
static p_int_14_21 iterations;
static p_v_float_7_4_33_34 gl_FragColor;

int_14 c_17 = 0;
int_14 c_31 = 1;
float_7 c_37 = 1;

static void_2 main() {
//Label [5]
//Variable [9] [10] Function [0]
//Variable [15] [16] Function [0]
//Load [8] [13] [12]
//Store [10] [13]
//Store [16] [17]
//Branch [18]
//Label [18]
//Load [14] [20] [16]
//Load [14] [23] [22]
//SLessThan [24] [25] [20] [23]
//LoopMerge [19] Unroll
//BranchConditional [25] [26] [19]
//  Label [26]
//  Load [8] [27] [12]
//  Load [8] [28] [10]
//  FAdd [8] [29] [28] [27]
//  Store [10] [29]
//  Load [14] [30] [16]
//  IAdd [14] [32] [30] [31]
//  Store [16] [32]
//  Branch [18]
//Label [19]
//Load [8] [36] [10]
//CompositeExtract [7] [38] [36] 12663860
//CompositeExtract [7] [39] [36] 12663880
//CompositeExtract [7] [40] [36] 12663900
//CompositeConstruct [33] [41] [12663916] [0] [4261281277] [3905671859]
//Store [35] [41]
//Branch [6]
//Label [6]
//Return
}

