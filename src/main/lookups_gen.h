#pragma once
#include "types.h"
#include "lookups.h"

struct Program;

void HandleNop(void* op, Program* prog);
struct SNop {
};

void HandleSource(void* op, Program* prog);
struct SSource {
  SourceLanguage SourceLanguage;
  uint32 Version;
};

void HandleSourceExtension(void* op, Program* prog);
struct SSourceExtension {
  char* Extension;
};

void HandleExtension(void* op, Program* prog);
struct SExtension {
  char* Name;
};

void HandleExtInstImport(void* op, Program* prog);
struct SExtInstImport {
  uint32 ResultId;
  char* Name;
};

void HandleMemoryModel(void* op, Program* prog);
struct SMemoryModel {
  AddressingModel AddressingModel;
  MemoryModel MemoryModel;
};

void HandleEntryPoint(void* op, Program* prog);
struct SEntryPoint {
  ExecutionModel ExecutionModel;
  uint32 EntryPointId;
};

void HandleExecutionMode(void* op, Program* prog);
struct SExecutionMode {
  uint32 EntryPointId;
  ExecutionMode Mode;
  uint32 ExecutionModesCount;
  uint32* ExecutionModes;
};

void HandleTypeVoid(void* op, Program* prog);
struct STypeVoid {
  uint32 ResultId;
};

void HandleTypeBool(void* op, Program* prog);
struct STypeBool {
  uint32 ResultId;
};

void HandleTypeInt(void* op, Program* prog);
struct STypeInt {
  uint32 ResultId;
  uint32 Width;
  uint32 Signedness;
};

void HandleTypeFloat(void* op, Program* prog);
struct STypeFloat {
  uint32 ResultId;
  uint32 Width;
};

void HandleTypeVector(void* op, Program* prog);
struct STypeVector {
  uint32 ResultId;
  uint32 ComponenttypeId;
  uint32 Componentcount;
};

void HandleTypeMatrix(void* op, Program* prog);
struct STypeMatrix {
  uint32 ResultId;
  uint32 ColumntypeId;
  uint32 Columncount;
};

void HandleTypeSampler(void* op, Program* prog);
struct STypeSampler {
  uint32 ResultId;
  uint32 SampledTypeId;
  Dim Dim;
  uint32 Content;
  uint32 Arrayed;
  uint32 Compare;
  uint32 MS;
  uint32 QualifierId;
};

void HandleTypeFilter(void* op, Program* prog);
struct STypeFilter {
  uint32 ResultId;
};

void HandleTypeArray(void* op, Program* prog);
struct STypeArray {
  uint32 ResultId;
  uint32 ElementtypeId;
  uint32 LengthId;
};

void HandleTypeRuntimeArray(void* op, Program* prog);
struct STypeRuntimeArray {
  uint32 ResultId;
  uint32 ElementtypeId;
};

void HandleTypeStruct(void* op, Program* prog);
struct STypeStruct {
  uint32 ResultId;
  uint32 MembertypeIdsCount;
  uint32* MembertypeIds;
};

void HandleTypeOpaque(void* op, Program* prog);
struct STypeOpaque {
  uint32 ResultId;
  char* OpaqueTypeName;
};

void HandleTypePointer(void* op, Program* prog);
struct STypePointer {
  uint32 ResultId;
  StorageClass StorageClass;
  uint32 TypeId;
};

void HandleTypeFunction(void* op, Program* prog);
struct STypeFunction {
  uint32 ResultId;
  uint32 ReturnTypeId;
  uint32 ParameterTypeIdsCount;
  uint32* ParameterTypeIds;
};

void HandleTypeEvent(void* op, Program* prog);
struct STypeEvent {
  uint32 ResultId;
};

void HandleTypeDeviceEvent(void* op, Program* prog);
struct STypeDeviceEvent {
  uint32 ResultId;
};

void HandleTypeReserveId(void* op, Program* prog);
struct STypeReserveId {
  uint32 ResultId;
};

void HandleTypeQueue(void* op, Program* prog);
struct STypeQueue {
  uint32 ResultId;
};

void HandleTypePipe(void* op, Program* prog);
struct STypePipe {
  uint32 ResultId;
  uint32 TypeId;
  AccessQualifier Qualifier;
};

void HandleConstantTrue(void* op, Program* prog);
struct SConstantTrue {
  uint32 ResultTypeId;
  uint32 ResultId;
};

void HandleConstantFalse(void* op, Program* prog);
struct SConstantFalse {
  uint32 ResultTypeId;
  uint32 ResultId;
};

void HandleConstant(void* op, Program* prog);
struct SConstant {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 ValuesCount;
  uint32* Values;
};

void HandleConstantComposite(void* op, Program* prog);
struct SConstantComposite {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 ConstituentsIdsCount;
  uint32* ConstituentsIds;
};

void HandleConstantSampler(void* op, Program* prog);
struct SConstantSampler {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 Mode;
  uint32 Param;
  uint32 Filter;
};

void HandleConstantNullPointer(void* op, Program* prog);
struct SConstantNullPointer {
  uint32 ResultTypeId;
  uint32 ResultId;
};

void HandleConstantNullObject(void* op, Program* prog);
struct SConstantNullObject {
  uint32 ResultTypeId;
  uint32 ResultId;
};

void HandleSpecConstantTrue(void* op, Program* prog);
struct SSpecConstantTrue {
  uint32 ResultTypeId;
  uint32 ResultId;
};

void HandleSpecConstantFalse(void* op, Program* prog);
struct SSpecConstantFalse {
  uint32 ResultTypeId;
  uint32 ResultId;
};

void HandleSpecConstant(void* op, Program* prog);
struct SSpecConstant {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 ValuesCount;
  uint32* Values;
};

void HandleSpecConstantComposite(void* op, Program* prog);
struct SSpecConstantComposite {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 ConstituentsIdsCount;
  uint32* ConstituentsIds;
};

void HandleVariable(void* op, Program* prog);
struct SVariable {
  uint32 ResultTypeId;
  uint32 ResultId;
  StorageClass StorageClass;
  uint32 InitializerId;
};

void HandleVariableArray(void* op, Program* prog);
struct SVariableArray {
  uint32 ResultTypeId;
  uint32 ResultId;
  StorageClass StorageClass;
  uint32 NId;
};

void HandleFunction(void* op, Program* prog);
struct SFunction {
  uint32 ResultTypeId;
  uint32 ResultId;
  FunctionControl FunctionControl;
  uint32 FunctionTypeId;
};

void HandleFunctionParameter(void* op, Program* prog);
struct SFunctionParameter {
  uint32 ResultTypeId;
  uint32 ResultId;
};

void HandleFunctionEnd(void* op, Program* prog);
struct SFunctionEnd {
};

void HandleFunctionCall(void* op, Program* prog);
struct SFunctionCall {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 FunctionId;
  uint32 ArgumentIdsCount;
  uint32* ArgumentIds;
};

void HandleExtInst(void* op, Program* prog);
struct SExtInst {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 SetId;
  uint32 Instruction;
  uint32 OperandIdsCount;
  uint32* OperandIds;
};

void HandleUndef(void* op, Program* prog);
struct SUndef {
  uint32 ResultTypeId;
  uint32 ResultId;
};

void HandleLoad(void* op, Program* prog);
struct SLoad {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 PointerId;
  uint32 MemoryAccessCount;
  uint32* MemoryAccess;
};

void HandleStore(void* op, Program* prog);
struct SStore {
  uint32 PointerId;
  uint32 ObjectId;
  uint32 MemoryAccessCount;
  uint32* MemoryAccess;
};

void HandlePhi(void* op, Program* prog);
struct SPhi {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 Id2sCount;
  uint32* Id2s;
};

void HandleDecorationGroup(void* op, Program* prog);
struct SDecorationGroup {
  uint32 ResultId;
};

void HandleDecorate(void* op, Program* prog);
struct SDecorate {
  uint32 TargetId;
  Decoration Decoration;
  uint32 DecorationsCount;
  uint32* Decorations;
};

void HandleMemberDecorate(void* op, Program* prog);
struct SMemberDecorate {
  uint32 StructuretypeId;
  uint32 Member;
  Decoration Decoration;
  uint32 DecorationsCount;
  uint32* Decorations;
};

void HandleGroupDecorate(void* op, Program* prog);
struct SGroupDecorate {
  uint32 DecorationgroupId;
  uint32 TargetIdsCount;
  uint32* TargetIds;
};

void HandleGroupMemberDecorate(void* op, Program* prog);
struct SGroupMemberDecorate {
  uint32 DecorationgroupId;
  uint32 TargetIdsCount;
  uint32* TargetIds;
};

void HandleName(void* op, Program* prog);
struct SName {
  uint32 TargetId;
  char* Name;
};

void HandleMemberName(void* op, Program* prog);
struct SMemberName {
  uint32 TypeId;
  uint32 Member;
  char* Name;
};

void HandleString(void* op, Program* prog);
struct SString {
  uint32 ResultId;
  char* String;
};

void HandleLine(void* op, Program* prog);
struct SLine {
  uint32 TargetId;
  uint32 FileId;
  uint32 Line;
  uint32 Column;
};

void HandleVectorExtractDynamic(void* op, Program* prog);
struct SVectorExtractDynamic {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 VectorId;
  uint32 IndexId;
};

void HandleVectorInsertDynamic(void* op, Program* prog);
struct SVectorInsertDynamic {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 VectorId;
  uint32 ComponentId;
  uint32 IndexId;
};

void HandleVectorShuffle(void* op, Program* prog);
struct SVectorShuffle {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 Vector1Id;
  uint32 Vector2Id;
  uint32 ComponentsCount;
  uint32* Components;
};

void HandleCompositeConstruct(void* op, Program* prog);
struct SCompositeConstruct {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 ConstituentsIdsCount;
  uint32* ConstituentsIds;
};

void HandleCompositeExtract(void* op, Program* prog);
struct SCompositeExtract {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 CompositeId;
  uint32 IndexesCount;
  uint32* Indexes;
};

void HandleCompositeInsert(void* op, Program* prog);
struct SCompositeInsert {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 ObjectId;
  uint32 CompositeId;
  uint32 IndexesCount;
  uint32* Indexes;
};

void HandleCopyObject(void* op, Program* prog);
struct SCopyObject {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 OperandId;
};

void HandleCopyMemory(void* op, Program* prog);
struct SCopyMemory {
  uint32 TargetId;
  uint32 SourceId;
  uint32 MemoryAccessCount;
  uint32* MemoryAccess;
};

void HandleCopyMemorySized(void* op, Program* prog);
struct SCopyMemorySized {
  uint32 TargetId;
  uint32 SourceId;
  uint32 SizeId;
  uint32 MemoryAccessCount;
  uint32* MemoryAccess;
};

void HandleSampler(void* op, Program* prog);
struct SSampler {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 SamplerId;
  uint32 FilterId;
};

void HandleTextureSample(void* op, Program* prog);
struct STextureSample {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 SamplerId;
  uint32 CoordinateId;
  uint32 BiasId;
};

void HandleTextureSampleDref(void* op, Program* prog);
struct STextureSampleDref {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 SamplerId;
  uint32 CoordinateId;
  uint32 DrefId;
};

void HandleTextureSampleLod(void* op, Program* prog);
struct STextureSampleLod {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 SamplerId;
  uint32 CoordinateId;
  uint32 LevelofDetailId;
};

void HandleTextureSampleProj(void* op, Program* prog);
struct STextureSampleProj {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 SamplerId;
  uint32 CoordinateId;
  uint32 BiasId;
};

void HandleTextureSampleGrad(void* op, Program* prog);
struct STextureSampleGrad {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 SamplerId;
  uint32 CoordinateId;
  uint32 dxId;
  uint32 dyId;
};

void HandleTextureSampleOffset(void* op, Program* prog);
struct STextureSampleOffset {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 SamplerId;
  uint32 CoordinateId;
  uint32 OffsetId;
  uint32 BiasId;
};

void HandleTextureSampleProjLod(void* op, Program* prog);
struct STextureSampleProjLod {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 SamplerId;
  uint32 CoordinateId;
  uint32 LevelofDetailId;
};

void HandleTextureSampleProjGrad(void* op, Program* prog);
struct STextureSampleProjGrad {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 SamplerId;
  uint32 CoordinateId;
  uint32 dxId;
  uint32 dyId;
};

void HandleTextureSampleLodOffset(void* op, Program* prog);
struct STextureSampleLodOffset {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 SamplerId;
  uint32 CoordinateId;
  uint32 LevelofDetailId;
  uint32 OffsetId;
};

void HandleTextureSampleProjOffset(void* op, Program* prog);
struct STextureSampleProjOffset {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 SamplerId;
  uint32 CoordinateId;
  uint32 OffsetId;
  uint32 BiasId;
};

void HandleTextureSampleGradOffset(void* op, Program* prog);
struct STextureSampleGradOffset {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 SamplerId;
  uint32 CoordinateId;
  uint32 dxId;
  uint32 dyId;
  uint32 OffsetId;
};

void HandleTextureSampleProjLodOffset(void* op, Program* prog);
struct STextureSampleProjLodOffset {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 SamplerId;
  uint32 CoordinateId;
  uint32 LevelofDetailId;
  uint32 OffsetId;
};

void HandleTextureSampleProjGradOffset(void* op, Program* prog);
struct STextureSampleProjGradOffset {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 SamplerId;
  uint32 CoordinateId;
  uint32 dxId;
  uint32 dyId;
  uint32 OffsetId;
};

void HandleTextureFetchTexelLod(void* op, Program* prog);
struct STextureFetchTexelLod {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 SamplerId;
  uint32 CoordinateId;
  uint32 LevelofDetailId;
};

void HandleTextureFetchTexelOffset(void* op, Program* prog);
struct STextureFetchTexelOffset {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 SamplerId;
  uint32 CoordinateId;
  uint32 OffsetId;
};

void HandleTextureFetchSample(void* op, Program* prog);
struct STextureFetchSample {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 SamplerId;
  uint32 CoordinateId;
  uint32 SampleId;
};

void HandleTextureFetchTexel(void* op, Program* prog);
struct STextureFetchTexel {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 SamplerId;
  uint32 ElementId;
};

void HandleTextureGather(void* op, Program* prog);
struct STextureGather {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 SamplerId;
  uint32 CoordinateId;
  uint32 ComponentId;
};

void HandleTextureGatherOffset(void* op, Program* prog);
struct STextureGatherOffset {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 SamplerId;
  uint32 CoordinateId;
  uint32 ComponentId;
  uint32 OffsetId;
};

void HandleTextureGatherOffsets(void* op, Program* prog);
struct STextureGatherOffsets {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 SamplerId;
  uint32 CoordinateId;
  uint32 ComponentId;
  uint32 OffsetsId;
};

void HandleTextureQuerySizeLod(void* op, Program* prog);
struct STextureQuerySizeLod {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 SamplerId;
  uint32 LevelofDetailId;
};

void HandleTextureQuerySize(void* op, Program* prog);
struct STextureQuerySize {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 SamplerId;
};

void HandleTextureQueryLod(void* op, Program* prog);
struct STextureQueryLod {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 SamplerId;
  uint32 CoordinateId;
};

void HandleTextureQueryLevels(void* op, Program* prog);
struct STextureQueryLevels {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 SamplerId;
};

void HandleTextureQuerySamples(void* op, Program* prog);
struct STextureQuerySamples {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 SamplerId;
};

void HandleAccessChain(void* op, Program* prog);
struct SAccessChain {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 BaseId;
  uint32 IndexesIdsCount;
  uint32* IndexesIds;
};

void HandleInBoundsAccessChain(void* op, Program* prog);
struct SInBoundsAccessChain {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 BaseId;
  uint32 IndexesIdsCount;
  uint32* IndexesIds;
};

void HandleSNegate(void* op, Program* prog);
struct SSNegate {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 OperandId;
};

void HandleFNegate(void* op, Program* prog);
struct SFNegate {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 OperandId;
};

void HandleNot(void* op, Program* prog);
struct SNot {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 OperandId;
};

void HandleAny(void* op, Program* prog);
struct SAny {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 VectorId;
};

void HandleAll(void* op, Program* prog);
struct SAll {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 VectorId;
};

void HandleConvertFToU(void* op, Program* prog);
struct SConvertFToU {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 FloatValueId;
};

void HandleConvertFToS(void* op, Program* prog);
struct SConvertFToS {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 FloatValueId;
};

void HandleConvertSToF(void* op, Program* prog);
struct SConvertSToF {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 SignedValueId;
};

void HandleConvertUToF(void* op, Program* prog);
struct SConvertUToF {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 UnsignedvalueId;
};

void HandleUConvert(void* op, Program* prog);
struct SUConvert {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 UnsignedvalueId;
};

void HandleSConvert(void* op, Program* prog);
struct SSConvert {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 SignedValueId;
};

void HandleFConvert(void* op, Program* prog);
struct SFConvert {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 FloatValueId;
};

void HandleConvertPtrToU(void* op, Program* prog);
struct SConvertPtrToU {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 PointerId;
};

void HandleConvertUToPtr(void* op, Program* prog);
struct SConvertUToPtr {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 IntegervalueId;
};

void HandlePtrCastToGeneric(void* op, Program* prog);
struct SPtrCastToGeneric {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 SourcepointerId;
};

void HandleGenericCastToPtr(void* op, Program* prog);
struct SGenericCastToPtr {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 SourcepointerId;
};

void HandleBitcast(void* op, Program* prog);
struct SBitcast {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 OperandId;
};

void HandleTranspose(void* op, Program* prog);
struct STranspose {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 MatrixId;
};

void HandleIsNan(void* op, Program* prog);
struct SIsNan {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 xId;
};

void HandleIsInf(void* op, Program* prog);
struct SIsInf {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 xId;
};

void HandleIsFinite(void* op, Program* prog);
struct SIsFinite {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 xId;
};

void HandleIsNormal(void* op, Program* prog);
struct SIsNormal {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 xId;
};

void HandleSignBitSet(void* op, Program* prog);
struct SSignBitSet {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 xId;
};

void HandleLessOrGreater(void* op, Program* prog);
struct SLessOrGreater {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 xId;
  uint32 yId;
};

void HandleOrdered(void* op, Program* prog);
struct SOrdered {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 xId;
  uint32 yId;
};

void HandleUnordered(void* op, Program* prog);
struct SUnordered {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 xId;
  uint32 yId;
};

void HandleArrayLength(void* op, Program* prog);
struct SArrayLength {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 StructureId;
  uint32 Arraymember;
};

void HandleIAdd(void* op, Program* prog);
struct SIAdd {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 Operand1Id;
  uint32 Operand2Id;
};

void HandleFAdd(void* op, Program* prog);
struct SFAdd {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 Operand1Id;
  uint32 Operand2Id;
};

void HandleISub(void* op, Program* prog);
struct SISub {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 Operand1Id;
  uint32 Operand2Id;
};

void HandleFSub(void* op, Program* prog);
struct SFSub {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 Operand1Id;
  uint32 Operand2Id;
};

void HandleIMul(void* op, Program* prog);
struct SIMul {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 Operand1Id;
  uint32 Operand2Id;
};

void HandleFMul(void* op, Program* prog);
struct SFMul {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 Operand1Id;
  uint32 Operand2Id;
};

void HandleUDiv(void* op, Program* prog);
struct SUDiv {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 Operand1Id;
  uint32 Operand2Id;
};

void HandleSDiv(void* op, Program* prog);
struct SSDiv {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 Operand1Id;
  uint32 Operand2Id;
};

void HandleFDiv(void* op, Program* prog);
struct SFDiv {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 Operand1Id;
  uint32 Operand2Id;
};

void HandleUMod(void* op, Program* prog);
struct SUMod {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 Operand1Id;
  uint32 Operand2Id;
};

void HandleSRem(void* op, Program* prog);
struct SSRem {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 Operand1Id;
  uint32 Operand2Id;
};

void HandleSMod(void* op, Program* prog);
struct SSMod {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 Operand1Id;
  uint32 Operand2Id;
};

void HandleFRem(void* op, Program* prog);
struct SFRem {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 Operand1Id;
  uint32 Operand2Id;
};

void HandleFMod(void* op, Program* prog);
struct SFMod {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 Operand1Id;
  uint32 Operand2Id;
};

void HandleVectorTimesScalar(void* op, Program* prog);
struct SVectorTimesScalar {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 VectorId;
  uint32 ScalarId;
};

void HandleMatrixTimesScalar(void* op, Program* prog);
struct SMatrixTimesScalar {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 MatrixId;
  uint32 ScalarId;
};

void HandleVectorTimesMatrix(void* op, Program* prog);
struct SVectorTimesMatrix {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 VectorId;
  uint32 MatrixId;
};

void HandleMatrixTimesVector(void* op, Program* prog);
struct SMatrixTimesVector {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 MatrixId;
  uint32 VectorId;
};

void HandleMatrixTimesMatrix(void* op, Program* prog);
struct SMatrixTimesMatrix {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 LeftMatrixId;
  uint32 RightMatrixId;
};

void HandleOuterProduct(void* op, Program* prog);
struct SOuterProduct {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 Vector1Id;
  uint32 Vector2Id;
};

void HandleDot(void* op, Program* prog);
struct SDot {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 Vector1Id;
  uint32 Vector2Id;
};

void HandleShiftRightLogical(void* op, Program* prog);
struct SShiftRightLogical {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 Operand1Id;
  uint32 Operand2Id;
};

void HandleShiftRightArithmetic(void* op, Program* prog);
struct SShiftRightArithmetic {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 Operand1Id;
  uint32 Operand2Id;
};

void HandleShiftLeftLogical(void* op, Program* prog);
struct SShiftLeftLogical {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 Operand1Id;
  uint32 Operand2Id;
};

void HandleLogicalOr(void* op, Program* prog);
struct SLogicalOr {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 Operand1Id;
  uint32 Operand2Id;
};

void HandleLogicalXor(void* op, Program* prog);
struct SLogicalXor {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 Operand1Id;
  uint32 Operand2Id;
};

void HandleLogicalAnd(void* op, Program* prog);
struct SLogicalAnd {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 Operand1Id;
  uint32 Operand2Id;
};

void HandleBitwiseOr(void* op, Program* prog);
struct SBitwiseOr {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 Operand1Id;
  uint32 Operand2Id;
};

void HandleBitwiseXor(void* op, Program* prog);
struct SBitwiseXor {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 Operand1Id;
  uint32 Operand2Id;
};

void HandleBitwiseAnd(void* op, Program* prog);
struct SBitwiseAnd {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 Operand1Id;
  uint32 Operand2Id;
};

void HandleSelect(void* op, Program* prog);
struct SSelect {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 ConditionId;
  uint32 Object1Id;
  uint32 Object2Id;
};

void HandleIEqual(void* op, Program* prog);
struct SIEqual {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 Operand1Id;
  uint32 Operand2Id;
};

void HandleFOrdEqual(void* op, Program* prog);
struct SFOrdEqual {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 Operand1Id;
  uint32 Operand2Id;
};

void HandleFUnordEqual(void* op, Program* prog);
struct SFUnordEqual {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 Operand1Id;
  uint32 Operand2Id;
};

void HandleINotEqual(void* op, Program* prog);
struct SINotEqual {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 Operand1Id;
  uint32 Operand2Id;
};

void HandleFOrdNotEqual(void* op, Program* prog);
struct SFOrdNotEqual {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 Operand1Id;
  uint32 Operand2Id;
};

void HandleFUnordNotEqual(void* op, Program* prog);
struct SFUnordNotEqual {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 Operand1Id;
  uint32 Operand2Id;
};

void HandleULessThan(void* op, Program* prog);
struct SULessThan {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 Operand1Id;
  uint32 Operand2Id;
};

void HandleSLessThan(void* op, Program* prog);
struct SSLessThan {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 Operand1Id;
  uint32 Operand2Id;
};

void HandleFOrdLessThan(void* op, Program* prog);
struct SFOrdLessThan {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 Operand1Id;
  uint32 Operand2Id;
};

void HandleFUnordLessThan(void* op, Program* prog);
struct SFUnordLessThan {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 Operand1Id;
  uint32 Operand2Id;
};

void HandleUGreaterThan(void* op, Program* prog);
struct SUGreaterThan {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 Operand1Id;
  uint32 Operand2Id;
};

void HandleSGreaterThan(void* op, Program* prog);
struct SSGreaterThan {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 Operand1Id;
  uint32 Operand2Id;
};

void HandleFOrdGreaterThan(void* op, Program* prog);
struct SFOrdGreaterThan {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 Operand1Id;
  uint32 Operand2Id;
};

void HandleFUnordGreaterThan(void* op, Program* prog);
struct SFUnordGreaterThan {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 Operand1Id;
  uint32 Operand2Id;
};

void HandleULessThanEqual(void* op, Program* prog);
struct SULessThanEqual {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 Operand1Id;
  uint32 Operand2Id;
};

void HandleSLessThanEqual(void* op, Program* prog);
struct SSLessThanEqual {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 Operand1Id;
  uint32 Operand2Id;
};

void HandleFOrdLessThanEqual(void* op, Program* prog);
struct SFOrdLessThanEqual {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 Operand1Id;
  uint32 Operand2Id;
};

void HandleFUnordLessThanEqual(void* op, Program* prog);
struct SFUnordLessThanEqual {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 Operand1Id;
  uint32 Operand2Id;
};

void HandleUGreaterThanEqual(void* op, Program* prog);
struct SUGreaterThanEqual {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 Operand1Id;
  uint32 Operand2Id;
};

void HandleSGreaterThanEqual(void* op, Program* prog);
struct SSGreaterThanEqual {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 Operand1Id;
  uint32 Operand2Id;
};

void HandleFOrdGreaterThanEqual(void* op, Program* prog);
struct SFOrdGreaterThanEqual {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 Operand1Id;
  uint32 Operand2Id;
};

void HandleFUnordGreaterThanEqual(void* op, Program* prog);
struct SFUnordGreaterThanEqual {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 Operand1Id;
  uint32 Operand2Id;
};

void HandleDPdx(void* op, Program* prog);
struct SDPdx {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 PId;
};

void HandleDPdy(void* op, Program* prog);
struct SDPdy {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 PId;
};

void HandleFwidth(void* op, Program* prog);
struct SFwidth {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 PId;
};

void HandleDPdxFine(void* op, Program* prog);
struct SDPdxFine {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 PId;
};

void HandleDPdyFine(void* op, Program* prog);
struct SDPdyFine {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 PId;
};

void HandleFwidthFine(void* op, Program* prog);
struct SFwidthFine {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 PId;
};

void HandleDPdxCoarse(void* op, Program* prog);
struct SDPdxCoarse {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 PId;
};

void HandleDPdyCoarse(void* op, Program* prog);
struct SDPdyCoarse {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 PId;
};

void HandleFwidthCoarse(void* op, Program* prog);
struct SFwidthCoarse {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 PId;
};

void HandleEmitVertex(void* op, Program* prog);
struct SEmitVertex {
};

void HandleEndPrimitive(void* op, Program* prog);
struct SEndPrimitive {
};

void HandleEmitStreamVertex(void* op, Program* prog);
struct SEmitStreamVertex {
  uint32 StreamId;
};

void HandleEndStreamPrimitive(void* op, Program* prog);
struct SEndStreamPrimitive {
  uint32 StreamId;
};

void HandleControlBarrier(void* op, Program* prog);
struct SControlBarrier {
  ExecutionScope Scope;
};

void HandleMemoryBarrier(void* op, Program* prog);
struct SMemoryBarrier {
  ExecutionScope Scope;
  MemorySemantics Semantics;
};

void HandleImagePointer(void* op, Program* prog);
struct SImagePointer {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 ImageId;
  uint32 CoordinateId;
  uint32 SampleId;
};

void HandleAtomicInit(void* op, Program* prog);
struct SAtomicInit {
  uint32 PointerId;
  uint32 ValueId;
};

void HandleAtomicLoad(void* op, Program* prog);
struct SAtomicLoad {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 PointerId;
  ExecutionScope Scope;
  MemorySemantics Semantics;
};

void HandleAtomicStore(void* op, Program* prog);
struct SAtomicStore {
  uint32 PointerId;
  ExecutionScope Scope;
  MemorySemantics Semantics;
  uint32 ValueId;
};

void HandleAtomicExchange(void* op, Program* prog);
struct SAtomicExchange {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 PointerId;
  ExecutionScope Scope;
  MemorySemantics Semantics;
  uint32 ValueId;
};

void HandleAtomicCompareExchange(void* op, Program* prog);
struct SAtomicCompareExchange {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 PointerId;
  ExecutionScope Scope;
  MemorySemantics Semantics;
  uint32 ValueId;
  uint32 ComparatorId;
};

void HandleAtomicCompareExchangeWeak(void* op, Program* prog);
struct SAtomicCompareExchangeWeak {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 PointerId;
  ExecutionScope Scope;
  MemorySemantics Semantics;
  uint32 ValueId;
  uint32 ComparatorId;
};

void HandleAtomicIIncrement(void* op, Program* prog);
struct SAtomicIIncrement {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 PointerId;
  ExecutionScope Scope;
  MemorySemantics Semantics;
};

void HandleAtomicIDecrement(void* op, Program* prog);
struct SAtomicIDecrement {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 PointerId;
  ExecutionScope Scope;
  MemorySemantics Semantics;
};

void HandleAtomicIAdd(void* op, Program* prog);
struct SAtomicIAdd {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 PointerId;
  ExecutionScope Scope;
  MemorySemantics Semantics;
  uint32 ValueId;
};

void HandleAtomicISub(void* op, Program* prog);
struct SAtomicISub {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 PointerId;
  ExecutionScope Scope;
  MemorySemantics Semantics;
  uint32 ValueId;
};

void HandleAtomicUMin(void* op, Program* prog);
struct SAtomicUMin {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 PointerId;
  ExecutionScope Scope;
  MemorySemantics Semantics;
  uint32 ValueId;
};

void HandleAtomicUMax(void* op, Program* prog);
struct SAtomicUMax {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 PointerId;
  ExecutionScope Scope;
  MemorySemantics Semantics;
  uint32 ValueId;
};

void HandleAtomicAnd(void* op, Program* prog);
struct SAtomicAnd {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 PointerId;
  ExecutionScope Scope;
  MemorySemantics Semantics;
  uint32 ValueId;
};

void HandleAtomicOr(void* op, Program* prog);
struct SAtomicOr {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 PointerId;
  ExecutionScope Scope;
  MemorySemantics Semantics;
  uint32 ValueId;
};

void HandleAtomicXor(void* op, Program* prog);
struct SAtomicXor {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 PointerId;
  ExecutionScope Scope;
  MemorySemantics Semantics;
  uint32 ValueId;
};

void HandleLoopMerge(void* op, Program* prog);
struct SLoopMerge {
  uint32 LabelId;
  LoopControl LoopControl;
};

void HandleSelectionMerge(void* op, Program* prog);
struct SSelectionMerge {
  uint32 LabelId;
  SelectionControl SelectionControl;
};

void HandleLabel(void* op, Program* prog);
struct SLabel {
  uint32 ResultId;
};

void HandleBranch(void* op, Program* prog);
struct SBranch {
  uint32 TargetLabelId;
};

void HandleBranchConditional(void* op, Program* prog);
struct SBranchConditional {
  uint32 ConditionId;
  uint32 TrueLabelId;
  uint32 FalseLabelId;
  uint32 BranchweightsCount;
  uint32* Branchweights;
};

void HandleSwitch(void* op, Program* prog);
struct SSwitch {
  uint32 SelectorId;
  uint32 DefaultId;
  uint32 literalIdsCount;
  uint32* literalIds;
};

void HandleKill(void* op, Program* prog);
struct SKill {
};

void HandleReturn(void* op, Program* prog);
struct SReturn {
};

void HandleReturnValue(void* op, Program* prog);
struct SReturnValue {
  uint32 ValueId;
};

void HandleUnreachable(void* op, Program* prog);
struct SUnreachable {
};

void HandleLifetimeStart(void* op, Program* prog);
struct SLifetimeStart {
  uint32 Id0;
  uint32 LiteralNumber;
};

void HandleLifetimeStop(void* op, Program* prog);
struct SLifetimeStop {
  uint32 Id0;
  uint32 LiteralNumber;
};

void HandleCompileFlag(void* op, Program* prog);
struct SCompileFlag {
  char* Flag;
};

void HandleAsyncGroupCopy(void* op, Program* prog);
struct SAsyncGroupCopy {
  uint32 ResultTypeId;
  uint32 ResultId;
  ExecutionScope Scope;
  uint32 DestinationId;
  uint32 SourceId;
  uint32 NumElementsId;
  uint32 StrideId;
  uint32 EventId;
};

void HandleWaitGroupEvents(void* op, Program* prog);
struct SWaitGroupEvents {
  uint32 ResultTypeId;
  uint32 ResultId;
  ExecutionScope Scope;
  uint32 NumEventsId;
  uint32 EventsListId;
};

void HandleGroupAll(void* op, Program* prog);
struct SGroupAll {
  uint32 ResultTypeId;
  uint32 ResultId;
  ExecutionScope Scope;
  uint32 PredicateId;
};

void HandleGroupAny(void* op, Program* prog);
struct SGroupAny {
  uint32 ResultTypeId;
  uint32 ResultId;
  ExecutionScope Scope;
  uint32 PredicateId;
};

void HandleGroupBroadcast(void* op, Program* prog);
struct SGroupBroadcast {
  uint32 ResultTypeId;
  uint32 ResultId;
  ExecutionScope Scope;
  uint32 ValueId;
  uint32 LocalIdId;
};

void HandleGroupIAdd(void* op, Program* prog);
struct SGroupIAdd {
  uint32 ResultTypeId;
  uint32 ResultId;
  ExecutionScope Scope;
  GroupOperation Operation;
  uint32 XId;
};

void HandleGroupFAdd(void* op, Program* prog);
struct SGroupFAdd {
  uint32 ResultTypeId;
  uint32 ResultId;
  ExecutionScope Scope;
  GroupOperation Operation;
  uint32 XId;
};

void HandleGroupFMin(void* op, Program* prog);
struct SGroupFMin {
  uint32 ResultTypeId;
  uint32 ResultId;
  ExecutionScope Scope;
  GroupOperation Operation;
  uint32 XId;
};

void HandleGroupUMin(void* op, Program* prog);
struct SGroupUMin {
  uint32 ResultTypeId;
  uint32 ResultId;
  ExecutionScope Scope;
  GroupOperation Operation;
  uint32 XId;
};

void HandleGroupSMin(void* op, Program* prog);
struct SGroupSMin {
  uint32 ResultTypeId;
  uint32 ResultId;
  ExecutionScope Scope;
  GroupOperation Operation;
  uint32 XId;
};

void HandleGroupFMax(void* op, Program* prog);
struct SGroupFMax {
  uint32 ResultTypeId;
  uint32 ResultId;
  ExecutionScope Scope;
  GroupOperation Operation;
  uint32 XId;
};

void HandleGroupUMax(void* op, Program* prog);
struct SGroupUMax {
  uint32 ResultTypeId;
  uint32 ResultId;
  ExecutionScope Scope;
  GroupOperation Operation;
  uint32 XId;
};

void HandleGroupSMax(void* op, Program* prog);
struct SGroupSMax {
  uint32 ResultTypeId;
  uint32 ResultId;
  ExecutionScope Scope;
  GroupOperation Operation;
  uint32 XId;
};

void HandleGenericCastToPtrExplicit(void* op, Program* prog);
struct SGenericCastToPtrExplicit {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 SourcepointerId;
  StorageClass storage;
};

void HandleGenericPtrMemSemantics(void* op, Program* prog);
struct SGenericPtrMemSemantics {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 ptrId;
};

void HandleReadPipe(void* op, Program* prog);
struct SReadPipe {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 pId;
  uint32 ptrId;
};

void HandleWritePipe(void* op, Program* prog);
struct SWritePipe {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 pId;
  uint32 ptrId;
};

void HandleReservedReadPipe(void* op, Program* prog);
struct SReservedReadPipe {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 pId;
  uint32 reserve_idId;
  uint32 indexId;
  uint32 ptrId;
};

void HandleReservedWritePipe(void* op, Program* prog);
struct SReservedWritePipe {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 pId;
  uint32 reserve_idId;
  uint32 indexId;
  uint32 ptrId;
};

void HandleReserveReadPipePackets(void* op, Program* prog);
struct SReserveReadPipePackets {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 pId;
  uint32 num_packetsId;
};

void HandleReserveWritePipePackets(void* op, Program* prog);
struct SReserveWritePipePackets {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 pId;
  uint32 num_packetsId;
};

void HandleCommitReadPipe(void* op, Program* prog);
struct SCommitReadPipe {
  uint32 pId;
  uint32 reserve_idId;
};

void HandleCommitWritePipe(void* op, Program* prog);
struct SCommitWritePipe {
  uint32 pId;
  uint32 reserve_idId;
};

void HandleIsValidReserveId(void* op, Program* prog);
struct SIsValidReserveId {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 reserve_idId;
};

void HandleGetNumPipePackets(void* op, Program* prog);
struct SGetNumPipePackets {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 pId;
};

void HandleGetMaxPipePackets(void* op, Program* prog);
struct SGetMaxPipePackets {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 pId;
};

void HandleGroupReserveReadPipePackets(void* op, Program* prog);
struct SGroupReserveReadPipePackets {
  uint32 ResultTypeId;
  uint32 ResultId;
  ExecutionScope Scope;
  uint32 pId;
  uint32 num_packetsId;
};

void HandleGroupReserveWritePipePackets(void* op, Program* prog);
struct SGroupReserveWritePipePackets {
  uint32 ResultTypeId;
  uint32 ResultId;
  ExecutionScope Scope;
  uint32 pId;
  uint32 num_packetsId;
};

void HandleGroupCommitReadPipe(void* op, Program* prog);
struct SGroupCommitReadPipe {
  ExecutionScope Scope;
  uint32 pId;
  uint32 reserve_idId;
};

void HandleGroupCommitWritePipe(void* op, Program* prog);
struct SGroupCommitWritePipe {
  ExecutionScope Scope;
  uint32 pId;
  uint32 reserve_idId;
};

void HandleEnqueueMarker(void* op, Program* prog);
struct SEnqueueMarker {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 qId;
  uint32 NumEventsId;
  uint32 WaitEventsId;
  uint32 RetEventId;
};

void HandleEnqueueKernel(void* op, Program* prog);
struct SEnqueueKernel {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 qId;
  KernelEnqueueFlags flags;
  uint32 NDRangeId;
  uint32 NumEventsId;
  uint32 WaitEventsId;
  uint32 RetEventId;
  uint32 InvokeId;
  uint32 ParamId;
  uint32 ParamSizeId;
  uint32 ParamAlignId;
  uint32 LocalSizeIdsCount;
  uint32* LocalSizeIds;
};

void HandleGetKernelNDrangeSubGroupCount(void* op, Program* prog);
struct SGetKernelNDrangeSubGroupCount {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 NDRangeId;
  uint32 InvokeId;
};

void HandleGetKernelNDrangeMaxSubGroupSize(void* op, Program* prog);
struct SGetKernelNDrangeMaxSubGroupSize {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 NDRangeId;
  uint32 InvokeId;
};

void HandleGetKernelWorkGroupSize(void* op, Program* prog);
struct SGetKernelWorkGroupSize {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 InvokeId;
};

void HandleGetKernelPreferredWorkGroupSizeMultiple(void* op, Program* prog);
struct SGetKernelPreferredWorkGroupSizeMultiple {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 InvokeId;
};

void HandleRetainEvent(void* op, Program* prog);
struct SRetainEvent {
  uint32 eventId;
};

void HandleReleaseEvent(void* op, Program* prog);
struct SReleaseEvent {
  uint32 eventId;
};

void HandleCreateUserEvent(void* op, Program* prog);
struct SCreateUserEvent {
  uint32 ResultTypeId;
  uint32 ResultId;
};

void HandleIsValidEvent(void* op, Program* prog);
struct SIsValidEvent {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 eventId;
};

void HandleSetUserEventStatus(void* op, Program* prog);
struct SSetUserEventStatus {
  uint32 eventId;
  uint32 statusId;
};

void HandleCaptureEventProfilingInfo(void* op, Program* prog);
struct SCaptureEventProfilingInfo {
  uint32 eventId;
  KernelProfilingInfo info;
  uint32 valueId;
};

void HandleGetDefaultQueue(void* op, Program* prog);
struct SGetDefaultQueue {
  uint32 ResultTypeId;
  uint32 ResultId;
};

void HandleBuildNDRange(void* op, Program* prog);
struct SBuildNDRange {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 GlobalWorkSizeId;
  uint32 LocalWorkSizeId;
  uint32 GlobalWorkOffsetId;
};

void HandleSatConvertSToU(void* op, Program* prog);
struct SSatConvertSToU {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 SignedValueId;
};

void HandleSatConvertUToS(void* op, Program* prog);
struct SSatConvertUToS {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 UnsignedValueId;
};

void HandleAtomicIMin(void* op, Program* prog);
struct SAtomicIMin {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 PointerId;
  ExecutionScope Scope;
  MemorySemantics Semantics;
  uint32 ValueId;
};

void HandleAtomicIMax(void* op, Program* prog);
struct SAtomicIMax {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 PointerId;
  ExecutionScope Scope;
  MemorySemantics Semantics;
  uint32 ValueId;
};


static WordType NopWordTypes[]{
  WordType::TOp,
};
static uint32 NopWordTypesCount = 1;

static WordType SourceWordTypes[]{
  WordType::TOp,
  WordType::TSourceLanguage,
  WordType::TLiteralNumber,
};
static uint32 SourceWordTypesCount = 3;

static WordType SourceExtensionWordTypes[]{
  WordType::TOp,
  WordType::TLiteralString,
};
static uint32 SourceExtensionWordTypesCount = 2;

static WordType ExtensionWordTypes[]{
  WordType::TOp,
  WordType::TLiteralString,
};
static uint32 ExtensionWordTypesCount = 2;

static WordType ExtInstImportWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TLiteralString,
};
static uint32 ExtInstImportWordTypesCount = 3;

static WordType MemoryModelWordTypes[]{
  WordType::TOp,
  WordType::TAddressingModel,
  WordType::TMemoryModel,
};
static uint32 MemoryModelWordTypesCount = 3;

static WordType EntryPointWordTypes[]{
  WordType::TOp,
  WordType::TExecutionModel,
  WordType::TId,
};
static uint32 EntryPointWordTypesCount = 3;

static WordType ExecutionModeWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TExecutionMode,
  WordType::TLiteralNumberList,
};
static uint32 ExecutionModeWordTypesCount = 4;

static WordType TypeVoidWordTypes[]{
  WordType::TOp,
  WordType::TId,
};
static uint32 TypeVoidWordTypesCount = 2;

static WordType TypeBoolWordTypes[]{
  WordType::TOp,
  WordType::TId,
};
static uint32 TypeBoolWordTypesCount = 2;

static WordType TypeIntWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TLiteralNumber,
  WordType::TLiteralNumber,
};
static uint32 TypeIntWordTypesCount = 4;

static WordType TypeFloatWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TLiteralNumber,
};
static uint32 TypeFloatWordTypesCount = 3;

static WordType TypeVectorWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TLiteralNumber,
};
static uint32 TypeVectorWordTypesCount = 4;

static WordType TypeMatrixWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TLiteralNumber,
};
static uint32 TypeMatrixWordTypesCount = 4;

static WordType TypeSamplerWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TDim,
  WordType::TLiteralNumber,
  WordType::TLiteralNumber,
  WordType::TLiteralNumber,
  WordType::TLiteralNumber,
  WordType::TId,
};
static uint32 TypeSamplerWordTypesCount = 9;

static WordType TypeFilterWordTypes[]{
  WordType::TOp,
  WordType::TId,
};
static uint32 TypeFilterWordTypesCount = 2;

static WordType TypeArrayWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
static uint32 TypeArrayWordTypesCount = 4;

static WordType TypeRuntimeArrayWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
};
static uint32 TypeRuntimeArrayWordTypesCount = 3;

static WordType TypeStructWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TIdList,
};
static uint32 TypeStructWordTypesCount = 3;

static WordType TypeOpaqueWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TLiteralString,
};
static uint32 TypeOpaqueWordTypesCount = 3;

static WordType TypePointerWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TStorageClass,
  WordType::TId,
};
static uint32 TypePointerWordTypesCount = 4;

static WordType TypeFunctionWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TIdList,
};
static uint32 TypeFunctionWordTypesCount = 4;

static WordType TypeEventWordTypes[]{
  WordType::TOp,
  WordType::TId,
};
static uint32 TypeEventWordTypesCount = 2;

static WordType TypeDeviceEventWordTypes[]{
  WordType::TOp,
  WordType::TId,
};
static uint32 TypeDeviceEventWordTypesCount = 2;

static WordType TypeReserveIdWordTypes[]{
  WordType::TOp,
  WordType::TId,
};
static uint32 TypeReserveIdWordTypesCount = 2;

static WordType TypeQueueWordTypes[]{
  WordType::TOp,
  WordType::TId,
};
static uint32 TypeQueueWordTypesCount = 2;

static WordType TypePipeWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TAccessQualifier,
};
static uint32 TypePipeWordTypesCount = 4;

static WordType ConstantTrueWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
};
static uint32 ConstantTrueWordTypesCount = 3;

static WordType ConstantFalseWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
};
static uint32 ConstantFalseWordTypesCount = 3;

static WordType ConstantWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TLiteralNumberList,
};
static uint32 ConstantWordTypesCount = 4;

static WordType ConstantCompositeWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TIdList,
};
static uint32 ConstantCompositeWordTypesCount = 4;

static WordType ConstantSamplerWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TLiteralNumber,
  WordType::TLiteralNumber,
  WordType::TLiteralNumber,
};
static uint32 ConstantSamplerWordTypesCount = 6;

static WordType ConstantNullPointerWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
};
static uint32 ConstantNullPointerWordTypesCount = 3;

static WordType ConstantNullObjectWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
};
static uint32 ConstantNullObjectWordTypesCount = 3;

static WordType SpecConstantTrueWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
};
static uint32 SpecConstantTrueWordTypesCount = 3;

static WordType SpecConstantFalseWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
};
static uint32 SpecConstantFalseWordTypesCount = 3;

static WordType SpecConstantWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TLiteralNumberList,
};
static uint32 SpecConstantWordTypesCount = 4;

static WordType SpecConstantCompositeWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TIdList,
};
static uint32 SpecConstantCompositeWordTypesCount = 4;

static WordType VariableWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TStorageClass,
  WordType::TId,
};
static uint32 VariableWordTypesCount = 5;

static WordType VariableArrayWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TStorageClass,
  WordType::TId,
};
static uint32 VariableArrayWordTypesCount = 5;

static WordType FunctionWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TFunctionControl,
  WordType::TId,
};
static uint32 FunctionWordTypesCount = 5;

static WordType FunctionParameterWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
};
static uint32 FunctionParameterWordTypesCount = 3;

static WordType FunctionEndWordTypes[]{
  WordType::TOp,
};
static uint32 FunctionEndWordTypesCount = 1;

static WordType FunctionCallWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TIdList,
};
static uint32 FunctionCallWordTypesCount = 5;

static WordType ExtInstWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TLiteralNumber,
  WordType::TIdList,
};
static uint32 ExtInstWordTypesCount = 6;

static WordType UndefWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
};
static uint32 UndefWordTypesCount = 3;

static WordType LoadWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TLiteralNumberList,
};
static uint32 LoadWordTypesCount = 5;

static WordType StoreWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TLiteralNumberList,
};
static uint32 StoreWordTypesCount = 4;

static WordType PhiWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TIdList,
};
static uint32 PhiWordTypesCount = 4;

static WordType DecorationGroupWordTypes[]{
  WordType::TOp,
  WordType::TId,
};
static uint32 DecorationGroupWordTypesCount = 2;

static WordType DecorateWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TDecoration,
  WordType::TLiteralNumberList,
};
static uint32 DecorateWordTypesCount = 4;

static WordType MemberDecorateWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TLiteralNumber,
  WordType::TDecoration,
  WordType::TLiteralNumberList,
};
static uint32 MemberDecorateWordTypesCount = 5;

static WordType GroupDecorateWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TIdList,
};
static uint32 GroupDecorateWordTypesCount = 3;

static WordType GroupMemberDecorateWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TIdList,
};
static uint32 GroupMemberDecorateWordTypesCount = 3;

static WordType NameWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TLiteralString,
};
static uint32 NameWordTypesCount = 3;

static WordType MemberNameWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TLiteralNumber,
  WordType::TLiteralString,
};
static uint32 MemberNameWordTypesCount = 4;

static WordType StringWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TLiteralString,
};
static uint32 StringWordTypesCount = 3;

static WordType LineWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TLiteralNumber,
  WordType::TLiteralNumber,
};
static uint32 LineWordTypesCount = 5;

static WordType VectorExtractDynamicWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
static uint32 VectorExtractDynamicWordTypesCount = 5;

static WordType VectorInsertDynamicWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
static uint32 VectorInsertDynamicWordTypesCount = 6;

static WordType VectorShuffleWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TLiteralNumberList,
};
static uint32 VectorShuffleWordTypesCount = 6;

static WordType CompositeConstructWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TIdList,
};
static uint32 CompositeConstructWordTypesCount = 4;

static WordType CompositeExtractWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TLiteralNumberList,
};
static uint32 CompositeExtractWordTypesCount = 5;

static WordType CompositeInsertWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TLiteralNumberList,
};
static uint32 CompositeInsertWordTypesCount = 6;

static WordType CopyObjectWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
static uint32 CopyObjectWordTypesCount = 4;

static WordType CopyMemoryWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TLiteralNumberList,
};
static uint32 CopyMemoryWordTypesCount = 4;

static WordType CopyMemorySizedWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TLiteralNumberList,
};
static uint32 CopyMemorySizedWordTypesCount = 5;

static WordType SamplerWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
static uint32 SamplerWordTypesCount = 5;

static WordType TextureSampleWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
static uint32 TextureSampleWordTypesCount = 6;

static WordType TextureSampleDrefWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
static uint32 TextureSampleDrefWordTypesCount = 6;

static WordType TextureSampleLodWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
static uint32 TextureSampleLodWordTypesCount = 6;

static WordType TextureSampleProjWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
static uint32 TextureSampleProjWordTypesCount = 6;

static WordType TextureSampleGradWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
static uint32 TextureSampleGradWordTypesCount = 7;

static WordType TextureSampleOffsetWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
static uint32 TextureSampleOffsetWordTypesCount = 7;

static WordType TextureSampleProjLodWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
static uint32 TextureSampleProjLodWordTypesCount = 6;

static WordType TextureSampleProjGradWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
static uint32 TextureSampleProjGradWordTypesCount = 7;

static WordType TextureSampleLodOffsetWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
static uint32 TextureSampleLodOffsetWordTypesCount = 7;

static WordType TextureSampleProjOffsetWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
static uint32 TextureSampleProjOffsetWordTypesCount = 7;

static WordType TextureSampleGradOffsetWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
static uint32 TextureSampleGradOffsetWordTypesCount = 8;

static WordType TextureSampleProjLodOffsetWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
static uint32 TextureSampleProjLodOffsetWordTypesCount = 7;

static WordType TextureSampleProjGradOffsetWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
static uint32 TextureSampleProjGradOffsetWordTypesCount = 8;

static WordType TextureFetchTexelLodWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
static uint32 TextureFetchTexelLodWordTypesCount = 6;

static WordType TextureFetchTexelOffsetWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
static uint32 TextureFetchTexelOffsetWordTypesCount = 6;

static WordType TextureFetchSampleWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
static uint32 TextureFetchSampleWordTypesCount = 6;

static WordType TextureFetchTexelWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
static uint32 TextureFetchTexelWordTypesCount = 5;

static WordType TextureGatherWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
static uint32 TextureGatherWordTypesCount = 6;

static WordType TextureGatherOffsetWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
static uint32 TextureGatherOffsetWordTypesCount = 7;

static WordType TextureGatherOffsetsWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
static uint32 TextureGatherOffsetsWordTypesCount = 7;

static WordType TextureQuerySizeLodWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
static uint32 TextureQuerySizeLodWordTypesCount = 5;

static WordType TextureQuerySizeWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
static uint32 TextureQuerySizeWordTypesCount = 4;

static WordType TextureQueryLodWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
static uint32 TextureQueryLodWordTypesCount = 5;

static WordType TextureQueryLevelsWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
static uint32 TextureQueryLevelsWordTypesCount = 4;

static WordType TextureQuerySamplesWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
static uint32 TextureQuerySamplesWordTypesCount = 4;

static WordType AccessChainWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TIdList,
};
static uint32 AccessChainWordTypesCount = 5;

static WordType InBoundsAccessChainWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TIdList,
};
static uint32 InBoundsAccessChainWordTypesCount = 5;

static WordType SNegateWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
static uint32 SNegateWordTypesCount = 4;

static WordType FNegateWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
static uint32 FNegateWordTypesCount = 4;

static WordType NotWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
static uint32 NotWordTypesCount = 4;

static WordType AnyWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
static uint32 AnyWordTypesCount = 4;

static WordType AllWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
static uint32 AllWordTypesCount = 4;

static WordType ConvertFToUWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
static uint32 ConvertFToUWordTypesCount = 4;

static WordType ConvertFToSWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
static uint32 ConvertFToSWordTypesCount = 4;

static WordType ConvertSToFWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
static uint32 ConvertSToFWordTypesCount = 4;

static WordType ConvertUToFWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
static uint32 ConvertUToFWordTypesCount = 4;

static WordType UConvertWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
static uint32 UConvertWordTypesCount = 4;

static WordType SConvertWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
static uint32 SConvertWordTypesCount = 4;

static WordType FConvertWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
static uint32 FConvertWordTypesCount = 4;

static WordType ConvertPtrToUWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
static uint32 ConvertPtrToUWordTypesCount = 4;

static WordType ConvertUToPtrWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
static uint32 ConvertUToPtrWordTypesCount = 4;

static WordType PtrCastToGenericWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
static uint32 PtrCastToGenericWordTypesCount = 4;

static WordType GenericCastToPtrWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
static uint32 GenericCastToPtrWordTypesCount = 4;

static WordType BitcastWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
static uint32 BitcastWordTypesCount = 4;

static WordType TransposeWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
static uint32 TransposeWordTypesCount = 4;

static WordType IsNanWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
static uint32 IsNanWordTypesCount = 4;

static WordType IsInfWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
static uint32 IsInfWordTypesCount = 4;

static WordType IsFiniteWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
static uint32 IsFiniteWordTypesCount = 4;

static WordType IsNormalWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
static uint32 IsNormalWordTypesCount = 4;

static WordType SignBitSetWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
static uint32 SignBitSetWordTypesCount = 4;

static WordType LessOrGreaterWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
static uint32 LessOrGreaterWordTypesCount = 5;

static WordType OrderedWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
static uint32 OrderedWordTypesCount = 5;

static WordType UnorderedWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
static uint32 UnorderedWordTypesCount = 5;

static WordType ArrayLengthWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TLiteralNumber,
};
static uint32 ArrayLengthWordTypesCount = 5;

static WordType IAddWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
static uint32 IAddWordTypesCount = 5;

static WordType FAddWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
static uint32 FAddWordTypesCount = 5;

static WordType ISubWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
static uint32 ISubWordTypesCount = 5;

static WordType FSubWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
static uint32 FSubWordTypesCount = 5;

static WordType IMulWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
static uint32 IMulWordTypesCount = 5;

static WordType FMulWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
static uint32 FMulWordTypesCount = 5;

static WordType UDivWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
static uint32 UDivWordTypesCount = 5;

static WordType SDivWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
static uint32 SDivWordTypesCount = 5;

static WordType FDivWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
static uint32 FDivWordTypesCount = 5;

static WordType UModWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
static uint32 UModWordTypesCount = 5;

static WordType SRemWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
static uint32 SRemWordTypesCount = 5;

static WordType SModWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
static uint32 SModWordTypesCount = 5;

static WordType FRemWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
static uint32 FRemWordTypesCount = 5;

static WordType FModWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
static uint32 FModWordTypesCount = 5;

static WordType VectorTimesScalarWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
static uint32 VectorTimesScalarWordTypesCount = 5;

static WordType MatrixTimesScalarWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
static uint32 MatrixTimesScalarWordTypesCount = 5;

static WordType VectorTimesMatrixWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
static uint32 VectorTimesMatrixWordTypesCount = 5;

static WordType MatrixTimesVectorWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
static uint32 MatrixTimesVectorWordTypesCount = 5;

static WordType MatrixTimesMatrixWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
static uint32 MatrixTimesMatrixWordTypesCount = 5;

static WordType OuterProductWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
static uint32 OuterProductWordTypesCount = 5;

static WordType DotWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
static uint32 DotWordTypesCount = 5;

static WordType ShiftRightLogicalWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
static uint32 ShiftRightLogicalWordTypesCount = 5;

static WordType ShiftRightArithmeticWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
static uint32 ShiftRightArithmeticWordTypesCount = 5;

static WordType ShiftLeftLogicalWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
static uint32 ShiftLeftLogicalWordTypesCount = 5;

static WordType LogicalOrWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
static uint32 LogicalOrWordTypesCount = 5;

static WordType LogicalXorWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
static uint32 LogicalXorWordTypesCount = 5;

static WordType LogicalAndWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
static uint32 LogicalAndWordTypesCount = 5;

static WordType BitwiseOrWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
static uint32 BitwiseOrWordTypesCount = 5;

static WordType BitwiseXorWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
static uint32 BitwiseXorWordTypesCount = 5;

static WordType BitwiseAndWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
static uint32 BitwiseAndWordTypesCount = 5;

static WordType SelectWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
static uint32 SelectWordTypesCount = 6;

static WordType IEqualWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
static uint32 IEqualWordTypesCount = 5;

static WordType FOrdEqualWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
static uint32 FOrdEqualWordTypesCount = 5;

static WordType FUnordEqualWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
static uint32 FUnordEqualWordTypesCount = 5;

static WordType INotEqualWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
static uint32 INotEqualWordTypesCount = 5;

static WordType FOrdNotEqualWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
static uint32 FOrdNotEqualWordTypesCount = 5;

static WordType FUnordNotEqualWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
static uint32 FUnordNotEqualWordTypesCount = 5;

static WordType ULessThanWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
static uint32 ULessThanWordTypesCount = 5;

static WordType SLessThanWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
static uint32 SLessThanWordTypesCount = 5;

static WordType FOrdLessThanWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
static uint32 FOrdLessThanWordTypesCount = 5;

static WordType FUnordLessThanWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
static uint32 FUnordLessThanWordTypesCount = 5;

static WordType UGreaterThanWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
static uint32 UGreaterThanWordTypesCount = 5;

static WordType SGreaterThanWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
static uint32 SGreaterThanWordTypesCount = 5;

static WordType FOrdGreaterThanWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
static uint32 FOrdGreaterThanWordTypesCount = 5;

static WordType FUnordGreaterThanWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
static uint32 FUnordGreaterThanWordTypesCount = 5;

static WordType ULessThanEqualWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
static uint32 ULessThanEqualWordTypesCount = 5;

static WordType SLessThanEqualWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
static uint32 SLessThanEqualWordTypesCount = 5;

static WordType FOrdLessThanEqualWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
static uint32 FOrdLessThanEqualWordTypesCount = 5;

static WordType FUnordLessThanEqualWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
static uint32 FUnordLessThanEqualWordTypesCount = 5;

static WordType UGreaterThanEqualWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
static uint32 UGreaterThanEqualWordTypesCount = 5;

static WordType SGreaterThanEqualWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
static uint32 SGreaterThanEqualWordTypesCount = 5;

static WordType FOrdGreaterThanEqualWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
static uint32 FOrdGreaterThanEqualWordTypesCount = 5;

static WordType FUnordGreaterThanEqualWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
static uint32 FUnordGreaterThanEqualWordTypesCount = 5;

static WordType DPdxWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
static uint32 DPdxWordTypesCount = 4;

static WordType DPdyWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
static uint32 DPdyWordTypesCount = 4;

static WordType FwidthWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
static uint32 FwidthWordTypesCount = 4;

static WordType DPdxFineWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
static uint32 DPdxFineWordTypesCount = 4;

static WordType DPdyFineWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
static uint32 DPdyFineWordTypesCount = 4;

static WordType FwidthFineWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
static uint32 FwidthFineWordTypesCount = 4;

static WordType DPdxCoarseWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
static uint32 DPdxCoarseWordTypesCount = 4;

static WordType DPdyCoarseWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
static uint32 DPdyCoarseWordTypesCount = 4;

static WordType FwidthCoarseWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
static uint32 FwidthCoarseWordTypesCount = 4;

static WordType EmitVertexWordTypes[]{
  WordType::TOp,
};
static uint32 EmitVertexWordTypesCount = 1;

static WordType EndPrimitiveWordTypes[]{
  WordType::TOp,
};
static uint32 EndPrimitiveWordTypesCount = 1;

static WordType EmitStreamVertexWordTypes[]{
  WordType::TOp,
  WordType::TId,
};
static uint32 EmitStreamVertexWordTypesCount = 2;

static WordType EndStreamPrimitiveWordTypes[]{
  WordType::TOp,
  WordType::TId,
};
static uint32 EndStreamPrimitiveWordTypesCount = 2;

static WordType ControlBarrierWordTypes[]{
  WordType::TOp,
  WordType::TExecutionScope,
};
static uint32 ControlBarrierWordTypesCount = 2;

static WordType MemoryBarrierWordTypes[]{
  WordType::TOp,
  WordType::TExecutionScope,
  WordType::TMemorySemantics,
};
static uint32 MemoryBarrierWordTypesCount = 3;

static WordType ImagePointerWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
static uint32 ImagePointerWordTypesCount = 6;

static WordType AtomicInitWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
};
static uint32 AtomicInitWordTypesCount = 3;

static WordType AtomicLoadWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TExecutionScope,
  WordType::TMemorySemantics,
};
static uint32 AtomicLoadWordTypesCount = 6;

static WordType AtomicStoreWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TExecutionScope,
  WordType::TMemorySemantics,
  WordType::TId,
};
static uint32 AtomicStoreWordTypesCount = 5;

static WordType AtomicExchangeWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TExecutionScope,
  WordType::TMemorySemantics,
  WordType::TId,
};
static uint32 AtomicExchangeWordTypesCount = 7;

static WordType AtomicCompareExchangeWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TExecutionScope,
  WordType::TMemorySemantics,
  WordType::TId,
  WordType::TId,
};
static uint32 AtomicCompareExchangeWordTypesCount = 8;

static WordType AtomicCompareExchangeWeakWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TExecutionScope,
  WordType::TMemorySemantics,
  WordType::TId,
  WordType::TId,
};
static uint32 AtomicCompareExchangeWeakWordTypesCount = 8;

static WordType AtomicIIncrementWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TExecutionScope,
  WordType::TMemorySemantics,
};
static uint32 AtomicIIncrementWordTypesCount = 6;

static WordType AtomicIDecrementWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TExecutionScope,
  WordType::TMemorySemantics,
};
static uint32 AtomicIDecrementWordTypesCount = 6;

static WordType AtomicIAddWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TExecutionScope,
  WordType::TMemorySemantics,
  WordType::TId,
};
static uint32 AtomicIAddWordTypesCount = 7;

static WordType AtomicISubWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TExecutionScope,
  WordType::TMemorySemantics,
  WordType::TId,
};
static uint32 AtomicISubWordTypesCount = 7;

static WordType AtomicUMinWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TExecutionScope,
  WordType::TMemorySemantics,
  WordType::TId,
};
static uint32 AtomicUMinWordTypesCount = 7;

static WordType AtomicUMaxWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TExecutionScope,
  WordType::TMemorySemantics,
  WordType::TId,
};
static uint32 AtomicUMaxWordTypesCount = 7;

static WordType AtomicAndWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TExecutionScope,
  WordType::TMemorySemantics,
  WordType::TId,
};
static uint32 AtomicAndWordTypesCount = 7;

static WordType AtomicOrWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TExecutionScope,
  WordType::TMemorySemantics,
  WordType::TId,
};
static uint32 AtomicOrWordTypesCount = 7;

static WordType AtomicXorWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TExecutionScope,
  WordType::TMemorySemantics,
  WordType::TId,
};
static uint32 AtomicXorWordTypesCount = 7;

static WordType LoopMergeWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TLoopControl,
};
static uint32 LoopMergeWordTypesCount = 3;

static WordType SelectionMergeWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TSelectionControl,
};
static uint32 SelectionMergeWordTypesCount = 3;

static WordType LabelWordTypes[]{
  WordType::TOp,
  WordType::TId,
};
static uint32 LabelWordTypesCount = 2;

static WordType BranchWordTypes[]{
  WordType::TOp,
  WordType::TId,
};
static uint32 BranchWordTypesCount = 2;

static WordType BranchConditionalWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TLiteralNumberList,
};
static uint32 BranchConditionalWordTypesCount = 5;

static WordType SwitchWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TIdList,
};
static uint32 SwitchWordTypesCount = 4;

static WordType KillWordTypes[]{
  WordType::TOp,
};
static uint32 KillWordTypesCount = 1;

static WordType ReturnWordTypes[]{
  WordType::TOp,
};
static uint32 ReturnWordTypesCount = 1;

static WordType ReturnValueWordTypes[]{
  WordType::TOp,
  WordType::TId,
};
static uint32 ReturnValueWordTypesCount = 2;

static WordType UnreachableWordTypes[]{
  WordType::TOp,
};
static uint32 UnreachableWordTypesCount = 1;

static WordType LifetimeStartWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TLiteralNumber,
};
static uint32 LifetimeStartWordTypesCount = 3;

static WordType LifetimeStopWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TLiteralNumber,
};
static uint32 LifetimeStopWordTypesCount = 3;

static WordType CompileFlagWordTypes[]{
  WordType::TOp,
  WordType::TLiteralString,
};
static uint32 CompileFlagWordTypesCount = 2;

static WordType AsyncGroupCopyWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TExecutionScope,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
static uint32 AsyncGroupCopyWordTypesCount = 9;

static WordType WaitGroupEventsWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TExecutionScope,
  WordType::TId,
  WordType::TId,
};
static uint32 WaitGroupEventsWordTypesCount = 6;

static WordType GroupAllWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TExecutionScope,
  WordType::TId,
};
static uint32 GroupAllWordTypesCount = 5;

static WordType GroupAnyWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TExecutionScope,
  WordType::TId,
};
static uint32 GroupAnyWordTypesCount = 5;

static WordType GroupBroadcastWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TExecutionScope,
  WordType::TId,
  WordType::TId,
};
static uint32 GroupBroadcastWordTypesCount = 6;

static WordType GroupIAddWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TExecutionScope,
  WordType::TGroupOperation,
  WordType::TId,
};
static uint32 GroupIAddWordTypesCount = 6;

static WordType GroupFAddWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TExecutionScope,
  WordType::TGroupOperation,
  WordType::TId,
};
static uint32 GroupFAddWordTypesCount = 6;

static WordType GroupFMinWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TExecutionScope,
  WordType::TGroupOperation,
  WordType::TId,
};
static uint32 GroupFMinWordTypesCount = 6;

static WordType GroupUMinWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TExecutionScope,
  WordType::TGroupOperation,
  WordType::TId,
};
static uint32 GroupUMinWordTypesCount = 6;

static WordType GroupSMinWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TExecutionScope,
  WordType::TGroupOperation,
  WordType::TId,
};
static uint32 GroupSMinWordTypesCount = 6;

static WordType GroupFMaxWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TExecutionScope,
  WordType::TGroupOperation,
  WordType::TId,
};
static uint32 GroupFMaxWordTypesCount = 6;

static WordType GroupUMaxWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TExecutionScope,
  WordType::TGroupOperation,
  WordType::TId,
};
static uint32 GroupUMaxWordTypesCount = 6;

static WordType GroupSMaxWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TExecutionScope,
  WordType::TGroupOperation,
  WordType::TId,
};
static uint32 GroupSMaxWordTypesCount = 6;

static WordType GenericCastToPtrExplicitWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TStorageClass,
};
static uint32 GenericCastToPtrExplicitWordTypesCount = 5;

static WordType GenericPtrMemSemanticsWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
static uint32 GenericPtrMemSemanticsWordTypesCount = 4;

static WordType ReadPipeWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
static uint32 ReadPipeWordTypesCount = 5;

static WordType WritePipeWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
static uint32 WritePipeWordTypesCount = 5;

static WordType ReservedReadPipeWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
static uint32 ReservedReadPipeWordTypesCount = 7;

static WordType ReservedWritePipeWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
static uint32 ReservedWritePipeWordTypesCount = 7;

static WordType ReserveReadPipePacketsWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
static uint32 ReserveReadPipePacketsWordTypesCount = 5;

static WordType ReserveWritePipePacketsWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
static uint32 ReserveWritePipePacketsWordTypesCount = 5;

static WordType CommitReadPipeWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
};
static uint32 CommitReadPipeWordTypesCount = 3;

static WordType CommitWritePipeWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
};
static uint32 CommitWritePipeWordTypesCount = 3;

static WordType IsValidReserveIdWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
static uint32 IsValidReserveIdWordTypesCount = 4;

static WordType GetNumPipePacketsWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
static uint32 GetNumPipePacketsWordTypesCount = 4;

static WordType GetMaxPipePacketsWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
static uint32 GetMaxPipePacketsWordTypesCount = 4;

static WordType GroupReserveReadPipePacketsWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TExecutionScope,
  WordType::TId,
  WordType::TId,
};
static uint32 GroupReserveReadPipePacketsWordTypesCount = 6;

static WordType GroupReserveWritePipePacketsWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TExecutionScope,
  WordType::TId,
  WordType::TId,
};
static uint32 GroupReserveWritePipePacketsWordTypesCount = 6;

static WordType GroupCommitReadPipeWordTypes[]{
  WordType::TOp,
  WordType::TExecutionScope,
  WordType::TId,
  WordType::TId,
};
static uint32 GroupCommitReadPipeWordTypesCount = 4;

static WordType GroupCommitWritePipeWordTypes[]{
  WordType::TOp,
  WordType::TExecutionScope,
  WordType::TId,
  WordType::TId,
};
static uint32 GroupCommitWritePipeWordTypesCount = 4;

static WordType EnqueueMarkerWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
static uint32 EnqueueMarkerWordTypesCount = 7;

static WordType EnqueueKernelWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TKernelEnqueueFlags,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TIdList,
};
static uint32 EnqueueKernelWordTypesCount = 14;

static WordType GetKernelNDrangeSubGroupCountWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
static uint32 GetKernelNDrangeSubGroupCountWordTypesCount = 5;

static WordType GetKernelNDrangeMaxSubGroupSizeWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
static uint32 GetKernelNDrangeMaxSubGroupSizeWordTypesCount = 5;

static WordType GetKernelWorkGroupSizeWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
static uint32 GetKernelWorkGroupSizeWordTypesCount = 4;

static WordType GetKernelPreferredWorkGroupSizeMultipleWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
static uint32 GetKernelPreferredWorkGroupSizeMultipleWordTypesCount = 4;

static WordType RetainEventWordTypes[]{
  WordType::TOp,
  WordType::TId,
};
static uint32 RetainEventWordTypesCount = 2;

static WordType ReleaseEventWordTypes[]{
  WordType::TOp,
  WordType::TId,
};
static uint32 ReleaseEventWordTypesCount = 2;

static WordType CreateUserEventWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
};
static uint32 CreateUserEventWordTypesCount = 3;

static WordType IsValidEventWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
static uint32 IsValidEventWordTypesCount = 4;

static WordType SetUserEventStatusWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
};
static uint32 SetUserEventStatusWordTypesCount = 3;

static WordType CaptureEventProfilingInfoWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TKernelProfilingInfo,
  WordType::TId,
};
static uint32 CaptureEventProfilingInfoWordTypesCount = 4;

static WordType GetDefaultQueueWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
};
static uint32 GetDefaultQueueWordTypesCount = 3;

static WordType BuildNDRangeWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
static uint32 BuildNDRangeWordTypesCount = 6;

static WordType SatConvertSToUWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
static uint32 SatConvertSToUWordTypesCount = 4;

static WordType SatConvertUToSWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
static uint32 SatConvertUToSWordTypesCount = 4;

static WordType AtomicIMinWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TExecutionScope,
  WordType::TMemorySemantics,
  WordType::TId,
};
static uint32 AtomicIMinWordTypesCount = 7;

static WordType AtomicIMaxWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TExecutionScope,
  WordType::TMemorySemantics,
  WordType::TId,
};
static uint32 AtomicIMaxWordTypesCount = 7;

extern void* LUTOpWordTypes[Op::Count];
extern uint32 LUTOpWordTypesCount[Op::Count];

typedef void(*OpHandler)(void*, Program*);
extern OpHandler LUTHandlerMethods[Op::Count];