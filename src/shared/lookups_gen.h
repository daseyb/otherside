#pragma once
#include "types.h"
#include "lookups.h"

struct ParseProgram;

#pragma pack(push, 1)
void HandleNop(void* op, ParseProgram* prog);
struct SNop {
};

void HandleUndef(void* op, ParseProgram* prog);
struct SUndef {
  uint32 ResultTypeId;
  uint32 ResultId;
};

void HandleSource(void* op, ParseProgram* prog);
struct SSource {
  spv::SourceLanguage SourceLanguage;
  uint32 Version;
};

void HandleSourceExtension(void* op, ParseProgram* prog);
struct SSourceExtension {
  char* Extension;
};

void HandleName(void* op, ParseProgram* prog);
struct SName {
  uint32 TargetId;
  char* Name;
};

void HandleMemberName(void* op, ParseProgram* prog);
struct SMemberName {
  uint32 TypeId;
  uint32 Member;
  char* Name;
};

void HandleString(void* op, ParseProgram* prog);
struct SString {
  uint32 ResultId;
  char* String;
};

void HandleLine(void* op, ParseProgram* prog);
struct SLine {
  uint32 TargetId;
  uint32 FileId;
  uint32 Line;
  uint32 Column;
};

void HandleExtension(void* op, ParseProgram* prog);
struct SExtension {
  char* Name;
};

void HandleExtInstImport(void* op, ParseProgram* prog);
struct SExtInstImport {
  uint32 ResultId;
  char* Name;
};

void HandleExtInst(void* op, ParseProgram* prog);
struct SExtInst {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 SetId;
  uint32 Instruction;
  uint32 OperandIdsCount;
  uint32* OperandIds;
};

void HandleMemoryModel(void* op, ParseProgram* prog);
struct SMemoryModel {
  spv::AddressingModel AddressingModel;
  spv::MemoryModel MemoryModel;
};

void HandleEntryPoint(void* op, ParseProgram* prog);
struct SEntryPoint {
  spv::ExecutionModel ExecutionModel;
  uint32 EntryPointId;
  char* Name;
};

void HandleExecutionMode(void* op, ParseProgram* prog);
struct SExecutionMode {
  uint32 EntryPointId;
  spv::ExecutionMode Mode;
  uint32 ExecutionModesCount;
  uint32* ExecutionModes;
};

void HandleCapability(void* op, ParseProgram* prog);
struct SCapability {
  spv::Capability Capability;
};

void HandleTypeVoid(void* op, ParseProgram* prog);
struct STypeVoid {
  uint32 ResultId;
};

void HandleTypeBool(void* op, ParseProgram* prog);
struct STypeBool {
  uint32 ResultId;
};

void HandleTypeInt(void* op, ParseProgram* prog);
struct STypeInt {
  uint32 ResultId;
  uint32 Width;
  uint32 Signedness;
};

void HandleTypeFloat(void* op, ParseProgram* prog);
struct STypeFloat {
  uint32 ResultId;
  uint32 Width;
};

void HandleTypeVector(void* op, ParseProgram* prog);
struct STypeVector {
  uint32 ResultId;
  uint32 ComponentTypeId;
  uint32 ComponentCount;
};

void HandleTypeMatrix(void* op, ParseProgram* prog);
struct STypeMatrix {
  uint32 ResultId;
  uint32 ColumnTypeId;
  uint32 ColumnCount;
};

void HandleTypeImage(void* op, ParseProgram* prog);
struct STypeImage {
  uint32 ResultId;
  uint32 SampledTypeId;
  spv::Dim Dim;
  uint32 Depth;
  uint32 Arrayed;
  uint32 MS;
  uint32 Sampled;
  spv::ImageFormat ImageFormat;
  uint32 AccessQualifiersCount;
  uint32* AccessQualifiers;
};

void HandleTypeSampler(void* op, ParseProgram* prog);
struct STypeSampler {
  uint32 ResultId;
};

void HandleTypeSampledImage(void* op, ParseProgram* prog);
struct STypeSampledImage {
  uint32 ResultId;
  uint32 ImageTypeId;
};

void HandleTypeArray(void* op, ParseProgram* prog);
struct STypeArray {
  uint32 ResultId;
  uint32 ElementTypeId;
  uint32 LengthId;
};

void HandleTypeRuntimeArray(void* op, ParseProgram* prog);
struct STypeRuntimeArray {
  uint32 ResultId;
  uint32 ElementTypeId;
};

void HandleTypeStruct(void* op, ParseProgram* prog);
struct STypeStruct {
  uint32 ResultId;
  uint32 MembertypeIdsCount;
  uint32* MembertypeIds;
};

void HandleTypeOpaque(void* op, ParseProgram* prog);
struct STypeOpaque {
  uint32 ResultId;
  char* OpaqueTypeName;
};

void HandleTypePointer(void* op, ParseProgram* prog);
struct STypePointer {
  uint32 ResultId;
  spv::StorageClass StorageClass;
  uint32 TypeId;
};

void HandleTypeFunction(void* op, ParseProgram* prog);
struct STypeFunction {
  uint32 ResultId;
  uint32 ReturnTypeId;
  uint32 ParameterTypeIdsCount;
  uint32* ParameterTypeIds;
};

void HandleTypeEvent(void* op, ParseProgram* prog);
struct STypeEvent {
  uint32 ResultId;
};

void HandleTypeDeviceEvent(void* op, ParseProgram* prog);
struct STypeDeviceEvent {
  uint32 ResultId;
};

void HandleTypeReserveId(void* op, ParseProgram* prog);
struct STypeReserveId {
  uint32 ResultId;
};

void HandleTypeQueue(void* op, ParseProgram* prog);
struct STypeQueue {
  uint32 ResultId;
};

void HandleTypePipe(void* op, ParseProgram* prog);
struct STypePipe {
  uint32 ResultId;
  uint32 TypeId;
  spv::AccessQualifier Qualifier;
};

void HandleConstantTrue(void* op, ParseProgram* prog);
struct SConstantTrue {
  uint32 ResultTypeId;
  uint32 ResultId;
};

void HandleConstantFalse(void* op, ParseProgram* prog);
struct SConstantFalse {
  uint32 ResultTypeId;
  uint32 ResultId;
};

void HandleConstant(void* op, ParseProgram* prog);
struct SConstant {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 ValuesCount;
  uint32* Values;
};

void HandleConstantComposite(void* op, ParseProgram* prog);
struct SConstantComposite {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 ConstituentsIdsCount;
  uint32* ConstituentsIds;
};

void HandleConstantSampler(void* op, ParseProgram* prog);
struct SConstantSampler {
  uint32 ResultTypeId;
  uint32 ResultId;
  spv::SamplerAddressingMode SamplerAddressingMode;
  uint32 Param;
  spv::SamplerFilterMode SamplerFilterMode;
};

void HandleConstantNull(void* op, ParseProgram* prog);
struct SConstantNull {
  uint32 ResultTypeId;
  uint32 ResultId;
};

void HandleSpecConstantTrue(void* op, ParseProgram* prog);
struct SSpecConstantTrue {
  uint32 ResultTypeId;
  uint32 ResultId;
};

void HandleSpecConstantFalse(void* op, ParseProgram* prog);
struct SSpecConstantFalse {
  uint32 ResultTypeId;
  uint32 ResultId;
};

void HandleSpecConstant(void* op, ParseProgram* prog);
struct SSpecConstant {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 ValuesCount;
  uint32* Values;
};

void HandleSpecConstantComposite(void* op, ParseProgram* prog);
struct SSpecConstantComposite {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 ConstituentsIdsCount;
  uint32* ConstituentsIds;
};

void HandleSpecConstantOp(void* op, ParseProgram* prog);
struct SSpecConstantOp {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 Opcode;
  uint32 OperandsIdsCount;
  uint32* OperandsIds;
};

void HandleFunction(void* op, ParseProgram* prog);
struct SFunction {
  uint32 ResultTypeId;
  uint32 ResultId;
  spv::FunctionControlMask FunctionControl;
  uint32 FunctionTypeId;
};

void HandleFunctionParameter(void* op, ParseProgram* prog);
struct SFunctionParameter {
  uint32 ResultTypeId;
  uint32 ResultId;
};

void HandleFunctionEnd(void* op, ParseProgram* prog);
struct SFunctionEnd {
};

void HandleFunctionCall(void* op, ParseProgram* prog);
struct SFunctionCall {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 FunctionId;
  uint32 ArgumentIdsCount;
  uint32* ArgumentIds;
};

void HandleVariable(void* op, ParseProgram* prog);
struct SVariable {
  uint32 ResultTypeId;
  uint32 ResultId;
  spv::StorageClass StorageClass;
  uint32 InitializerId;
};

void HandleImageTexelPointer(void* op, ParseProgram* prog);
struct SImageTexelPointer {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 ImageId;
  uint32 CoordinateId;
  uint32 SampleId;
};

void HandleLoad(void* op, ParseProgram* prog);
struct SLoad {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 PointerId;
  uint32 MemoryAccessCount;
  uint32* MemoryAccess;
};

void HandleStore(void* op, ParseProgram* prog);
struct SStore {
  uint32 PointerId;
  uint32 ObjectId;
  uint32 MemoryAccessCount;
  uint32* MemoryAccess;
};

void HandleCopyMemory(void* op, ParseProgram* prog);
struct SCopyMemory {
  uint32 TargetId;
  uint32 SourceId;
  uint32 MemoryAccessCount;
  uint32* MemoryAccess;
};

void HandleCopyMemorySized(void* op, ParseProgram* prog);
struct SCopyMemorySized {
  uint32 TargetId;
  uint32 SourceId;
  uint32 SizeId;
  uint32 MemoryAccessCount;
  uint32* MemoryAccess;
};

void HandleAccessChain(void* op, ParseProgram* prog);
struct SAccessChain {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 BaseId;
  uint32 IndexesIdsCount;
  uint32* IndexesIds;
};

void HandleInBoundsAccessChain(void* op, ParseProgram* prog);
struct SInBoundsAccessChain {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 BaseId;
  uint32 IndexesIdsCount;
  uint32* IndexesIds;
};

void HandlePtrAccessChain(void* op, ParseProgram* prog);
struct SPtrAccessChain {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 BaseId;
  uint32 ElementId;
  uint32 IndexesIdsCount;
  uint32* IndexesIds;
};

void HandleArrayLength(void* op, ParseProgram* prog);
struct SArrayLength {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 StructureId;
  uint32 Arraymember;
};

void HandleGenericPtrMemSemantics(void* op, ParseProgram* prog);
struct SGenericPtrMemSemantics {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 PointerId;
};

void HandleDecorate(void* op, ParseProgram* prog);
struct SDecorate {
  uint32 TargetId;
  spv::Decoration Decoration;
  uint32 DecorationsCount;
  uint32* Decorations;
};

void HandleMemberDecorate(void* op, ParseProgram* prog);
struct SMemberDecorate {
  uint32 StructureTypeId;
  uint32 Member;
  spv::Decoration Decoration;
  uint32 DecorationsCount;
  uint32* Decorations;
};

void HandleDecorationGroup(void* op, ParseProgram* prog);
struct SDecorationGroup {
  uint32 ResultId;
};

void HandleGroupDecorate(void* op, ParseProgram* prog);
struct SGroupDecorate {
  uint32 DecorationGroupId;
  uint32 TargetsIdsCount;
  uint32* TargetsIds;
};

void HandleGroupMemberDecorate(void* op, ParseProgram* prog);
struct SGroupMemberDecorate {
  uint32 DecorationGroupId;
  uint32 IdsCount;
  uint32* Ids;
};

void HandleVectorExtractDynamic(void* op, ParseProgram* prog);
struct SVectorExtractDynamic {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 VectorId;
  uint32 IndexId;
};

void HandleVectorInsertDynamic(void* op, ParseProgram* prog);
struct SVectorInsertDynamic {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 VectorId;
  uint32 ComponentId;
  uint32 IndexId;
};

void HandleVectorShuffle(void* op, ParseProgram* prog);
struct SVectorShuffle {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 Vector1Id;
  uint32 Vector2Id;
  uint32 ComponentsCount;
  uint32* Components;
};

void HandleCompositeConstruct(void* op, ParseProgram* prog);
struct SCompositeConstruct {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 ConstituentsIdsCount;
  uint32* ConstituentsIds;
};

void HandleCompositeExtract(void* op, ParseProgram* prog);
struct SCompositeExtract {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 CompositeId;
  uint32 IndexesCount;
  uint32* Indexes;
};

void HandleCompositeInsert(void* op, ParseProgram* prog);
struct SCompositeInsert {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 ObjectId;
  uint32 CompositeId;
  uint32 IndexesCount;
  uint32* Indexes;
};

void HandleCopyObject(void* op, ParseProgram* prog);
struct SCopyObject {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 OperandId;
};

void HandleTranspose(void* op, ParseProgram* prog);
struct STranspose {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 MatrixId;
};

void HandleSampledImage(void* op, ParseProgram* prog);
struct SSampledImage {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 ImageId;
  uint32 SamplerId;
};

void HandleImageSampleImplicitLod(void* op, ParseProgram* prog);
struct SImageSampleImplicitLod {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 SampledImageId;
  uint32 CoordinateId;
  uint32 ImageOperandsIdsCount;
  uint32* ImageOperandsIds;
};

void HandleImageSampleExplicitLod(void* op, ParseProgram* prog);
struct SImageSampleExplicitLod {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 SampledImageId;
  uint32 CoordinateId;
  uint32 ImageOperandsIdsCount;
  uint32* ImageOperandsIds;
};

void HandleImageSampleDrefImplicitLod(void* op, ParseProgram* prog);
struct SImageSampleDrefImplicitLod {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 SampledImageId;
  uint32 CoordinateId;
  uint32 DrefId;
  uint32 ImageOperandsIdsCount;
  uint32* ImageOperandsIds;
};

void HandleImageSampleDrefExplicitLod(void* op, ParseProgram* prog);
struct SImageSampleDrefExplicitLod {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 SampledImageId;
  uint32 CoordinateId;
  uint32 DrefId;
  uint32 ImageOperandsIdsCount;
  uint32* ImageOperandsIds;
};

void HandleImageSampleProjImplicitLod(void* op, ParseProgram* prog);
struct SImageSampleProjImplicitLod {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 SampledImageId;
  uint32 CoordinateId;
  uint32 ImageOperandsIdsCount;
  uint32* ImageOperandsIds;
};

void HandleImageSampleProjExplicitLod(void* op, ParseProgram* prog);
struct SImageSampleProjExplicitLod {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 SampledImageId;
  uint32 CoordinateId;
  uint32 ImageOperandsIdsCount;
  uint32* ImageOperandsIds;
};

void HandleImageSampleProjDrefImplicitLod(void* op, ParseProgram* prog);
struct SImageSampleProjDrefImplicitLod {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 SampledImageId;
  uint32 CoordinateId;
  uint32 DrefId;
  uint32 ImageOperandsIdsCount;
  uint32* ImageOperandsIds;
};

void HandleImageSampleProjDrefExplicitLod(void* op, ParseProgram* prog);
struct SImageSampleProjDrefExplicitLod {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 SampledImageId;
  uint32 CoordinateId;
  uint32 DrefId;
  uint32 ImageOperandsIdsCount;
  uint32* ImageOperandsIds;
};

void HandleImageFetch(void* op, ParseProgram* prog);
struct SImageFetch {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 SampledImageId;
  uint32 CoordinateId;
  uint32 ImageOperandsIdsCount;
  uint32* ImageOperandsIds;
};

void HandleImageGather(void* op, ParseProgram* prog);
struct SImageGather {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 SampledImageId;
  uint32 CoordinateId;
  uint32 ComponentId;
  uint32 ImageOperandsIdsCount;
  uint32* ImageOperandsIds;
};

void HandleImageDrefGather(void* op, ParseProgram* prog);
struct SImageDrefGather {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 SampledImageId;
  uint32 CoordinateId;
  uint32 DrefId;
  uint32 ImageOperandsIdsCount;
  uint32* ImageOperandsIds;
};

void HandleImageRead(void* op, ParseProgram* prog);
struct SImageRead {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 ImageId;
  uint32 CoordinateId;
};

void HandleImageWrite(void* op, ParseProgram* prog);
struct SImageWrite {
  uint32 ImageId;
  uint32 CoordinateId;
  uint32 TexelId;
};

void HandleImageQueryDim(void* op, ParseProgram* prog);
struct SImageQueryDim {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 ImageId;
};

void HandleImageQueryFormat(void* op, ParseProgram* prog);
struct SImageQueryFormat {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 ImageId;
};

void HandleImageQueryOrder(void* op, ParseProgram* prog);
struct SImageQueryOrder {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 ImageId;
};

void HandleImageQuerySizeLod(void* op, ParseProgram* prog);
struct SImageQuerySizeLod {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 ImageId;
  uint32 LevelofDetailId;
};

void HandleImageQuerySize(void* op, ParseProgram* prog);
struct SImageQuerySize {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 ImageId;
};

void HandleImageQueryLod(void* op, ParseProgram* prog);
struct SImageQueryLod {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 ImageId;
  uint32 CoordinateId;
};

void HandleImageQueryLevels(void* op, ParseProgram* prog);
struct SImageQueryLevels {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 ImageId;
};

void HandleImageQuerySamples(void* op, ParseProgram* prog);
struct SImageQuerySamples {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 ImageId;
};

void HandleConvertFToU(void* op, ParseProgram* prog);
struct SConvertFToU {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 FloatValueId;
};

void HandleConvertFToS(void* op, ParseProgram* prog);
struct SConvertFToS {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 FloatValueId;
};

void HandleConvertSToF(void* op, ParseProgram* prog);
struct SConvertSToF {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 SignedValueId;
};

void HandleConvertUToF(void* op, ParseProgram* prog);
struct SConvertUToF {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 UnsignedValueId;
};

void HandleUConvert(void* op, ParseProgram* prog);
struct SUConvert {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 UnsignedValueId;
};

void HandleSConvert(void* op, ParseProgram* prog);
struct SSConvert {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 SignedValueId;
};

void HandleFConvert(void* op, ParseProgram* prog);
struct SFConvert {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 FloatValueId;
};

void HandleQuantizeToF16(void* op, ParseProgram* prog);
struct SQuantizeToF16 {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 ValueId;
};

void HandleConvertPtrToU(void* op, ParseProgram* prog);
struct SConvertPtrToU {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 PointerId;
};

void HandleSatConvertSToU(void* op, ParseProgram* prog);
struct SSatConvertSToU {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 SignedValueId;
};

void HandleSatConvertUToS(void* op, ParseProgram* prog);
struct SSatConvertUToS {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 UnsignedValueId;
};

void HandleConvertUToPtr(void* op, ParseProgram* prog);
struct SConvertUToPtr {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 IntegerValueId;
};

void HandlePtrCastToGeneric(void* op, ParseProgram* prog);
struct SPtrCastToGeneric {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 PointerId;
};

void HandleGenericCastToPtr(void* op, ParseProgram* prog);
struct SGenericCastToPtr {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 PointerId;
};

void HandleGenericCastToPtrExplicit(void* op, ParseProgram* prog);
struct SGenericCastToPtrExplicit {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 PointerId;
  spv::StorageClass Storage;
};

void HandleBitcast(void* op, ParseProgram* prog);
struct SBitcast {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 OperandId;
};

void HandleSNegate(void* op, ParseProgram* prog);
struct SSNegate {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 OperandId;
};

void HandleFNegate(void* op, ParseProgram* prog);
struct SFNegate {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 OperandId;
};

void HandleIAdd(void* op, ParseProgram* prog);
struct SIAdd {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 Operand1Id;
  uint32 Operand2Id;
};

void HandleFAdd(void* op, ParseProgram* prog);
struct SFAdd {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 Operand1Id;
  uint32 Operand2Id;
};

void HandleISub(void* op, ParseProgram* prog);
struct SISub {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 Operand1Id;
  uint32 Operand2Id;
};

void HandleFSub(void* op, ParseProgram* prog);
struct SFSub {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 Operand1Id;
  uint32 Operand2Id;
};

void HandleIMul(void* op, ParseProgram* prog);
struct SIMul {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 Operand1Id;
  uint32 Operand2Id;
};

void HandleFMul(void* op, ParseProgram* prog);
struct SFMul {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 Operand1Id;
  uint32 Operand2Id;
};

void HandleUDiv(void* op, ParseProgram* prog);
struct SUDiv {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 Operand1Id;
  uint32 Operand2Id;
};

void HandleSDiv(void* op, ParseProgram* prog);
struct SSDiv {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 Operand1Id;
  uint32 Operand2Id;
};

void HandleFDiv(void* op, ParseProgram* prog);
struct SFDiv {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 Operand1Id;
  uint32 Operand2Id;
};

void HandleUMod(void* op, ParseProgram* prog);
struct SUMod {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 Operand1Id;
  uint32 Operand2Id;
};

void HandleSRem(void* op, ParseProgram* prog);
struct SSRem {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 Operand1Id;
  uint32 Operand2Id;
};

void HandleSMod(void* op, ParseProgram* prog);
struct SSMod {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 Operand1Id;
  uint32 Operand2Id;
};

void HandleFRem(void* op, ParseProgram* prog);
struct SFRem {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 Operand1Id;
  uint32 Operand2Id;
};

void HandleFMod(void* op, ParseProgram* prog);
struct SFMod {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 Operand1Id;
  uint32 Operand2Id;
};

void HandleVectorTimesScalar(void* op, ParseProgram* prog);
struct SVectorTimesScalar {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 VectorId;
  uint32 ScalarId;
};

void HandleMatrixTimesScalar(void* op, ParseProgram* prog);
struct SMatrixTimesScalar {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 MatrixId;
  uint32 ScalarId;
};

void HandleVectorTimesMatrix(void* op, ParseProgram* prog);
struct SVectorTimesMatrix {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 VectorId;
  uint32 MatrixId;
};

void HandleMatrixTimesVector(void* op, ParseProgram* prog);
struct SMatrixTimesVector {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 MatrixId;
  uint32 VectorId;
};

void HandleMatrixTimesMatrix(void* op, ParseProgram* prog);
struct SMatrixTimesMatrix {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 LeftMatrixId;
  uint32 RightMatrixId;
};

void HandleOuterProduct(void* op, ParseProgram* prog);
struct SOuterProduct {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 Vector1Id;
  uint32 Vector2Id;
};

void HandleDot(void* op, ParseProgram* prog);
struct SDot {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 Vector1Id;
  uint32 Vector2Id;
};

void HandleIAddCarry(void* op, ParseProgram* prog);
struct SIAddCarry {
  uint32 ResultTypeId;
  uint32 ResultId;
};

void HandleISubBorrow(void* op, ParseProgram* prog);
struct SISubBorrow {
  uint32 ResultTypeId;
  uint32 ResultId;
};

void HandleIMulExtended(void* op, ParseProgram* prog);
struct SIMulExtended {
  uint32 ResultTypeId;
  uint32 ResultId;
};

void HandleAny(void* op, ParseProgram* prog);
struct SAny {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 VectorId;
};

void HandleAll(void* op, ParseProgram* prog);
struct SAll {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 VectorId;
};

void HandleIsNan(void* op, ParseProgram* prog);
struct SIsNan {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 xId;
};

void HandleIsInf(void* op, ParseProgram* prog);
struct SIsInf {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 xId;
};

void HandleIsFinite(void* op, ParseProgram* prog);
struct SIsFinite {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 xId;
};

void HandleIsNormal(void* op, ParseProgram* prog);
struct SIsNormal {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 xId;
};

void HandleSignBitSet(void* op, ParseProgram* prog);
struct SSignBitSet {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 xId;
};

void HandleLessOrGreater(void* op, ParseProgram* prog);
struct SLessOrGreater {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 xId;
  uint32 yId;
};

void HandleOrdered(void* op, ParseProgram* prog);
struct SOrdered {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 xId;
  uint32 yId;
};

void HandleUnordered(void* op, ParseProgram* prog);
struct SUnordered {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 xId;
  uint32 yId;
};

void HandleLogicalEqual(void* op, ParseProgram* prog);
struct SLogicalEqual {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 Operand1Id;
  uint32 Operand2Id;
};

void HandleLogicalNotEqual(void* op, ParseProgram* prog);
struct SLogicalNotEqual {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 Operand1Id;
  uint32 Operand2Id;
};

void HandleLogicalOr(void* op, ParseProgram* prog);
struct SLogicalOr {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 Operand1Id;
  uint32 Operand2Id;
};

void HandleLogicalAnd(void* op, ParseProgram* prog);
struct SLogicalAnd {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 Operand1Id;
  uint32 Operand2Id;
};

void HandleLogicalNot(void* op, ParseProgram* prog);
struct SLogicalNot {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 OperandId;
};

void HandleSelect(void* op, ParseProgram* prog);
struct SSelect {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 ConditionId;
  uint32 Object1Id;
  uint32 Object2Id;
};

void HandleIEqual(void* op, ParseProgram* prog);
struct SIEqual {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 Operand1Id;
  uint32 Operand2Id;
};

void HandleINotEqual(void* op, ParseProgram* prog);
struct SINotEqual {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 Operand1Id;
  uint32 Operand2Id;
};

void HandleUGreaterThan(void* op, ParseProgram* prog);
struct SUGreaterThan {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 Operand1Id;
  uint32 Operand2Id;
};

void HandleSGreaterThan(void* op, ParseProgram* prog);
struct SSGreaterThan {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 Operand1Id;
  uint32 Operand2Id;
};

void HandleUGreaterThanEqual(void* op, ParseProgram* prog);
struct SUGreaterThanEqual {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 Operand1Id;
  uint32 Operand2Id;
};

void HandleSGreaterThanEqual(void* op, ParseProgram* prog);
struct SSGreaterThanEqual {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 Operand1Id;
  uint32 Operand2Id;
};

void HandleULessThan(void* op, ParseProgram* prog);
struct SULessThan {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 Operand1Id;
  uint32 Operand2Id;
};

void HandleSLessThan(void* op, ParseProgram* prog);
struct SSLessThan {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 Operand1Id;
  uint32 Operand2Id;
};

void HandleULessThanEqual(void* op, ParseProgram* prog);
struct SULessThanEqual {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 Operand1Id;
  uint32 Operand2Id;
};

void HandleSLessThanEqual(void* op, ParseProgram* prog);
struct SSLessThanEqual {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 Operand1Id;
  uint32 Operand2Id;
};

void HandleFOrdEqual(void* op, ParseProgram* prog);
struct SFOrdEqual {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 Operand1Id;
  uint32 Operand2Id;
};

void HandleFUnordEqual(void* op, ParseProgram* prog);
struct SFUnordEqual {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 Operand1Id;
  uint32 Operand2Id;
};

void HandleFOrdNotEqual(void* op, ParseProgram* prog);
struct SFOrdNotEqual {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 Operand1Id;
  uint32 Operand2Id;
};

void HandleFUnordNotEqual(void* op, ParseProgram* prog);
struct SFUnordNotEqual {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 Operand1Id;
  uint32 Operand2Id;
};

void HandleFOrdLessThan(void* op, ParseProgram* prog);
struct SFOrdLessThan {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 Operand1Id;
  uint32 Operand2Id;
};

void HandleFUnordLessThan(void* op, ParseProgram* prog);
struct SFUnordLessThan {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 Operand1Id;
  uint32 Operand2Id;
};

void HandleFOrdGreaterThan(void* op, ParseProgram* prog);
struct SFOrdGreaterThan {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 Operand1Id;
  uint32 Operand2Id;
};

void HandleFUnordGreaterThan(void* op, ParseProgram* prog);
struct SFUnordGreaterThan {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 Operand1Id;
  uint32 Operand2Id;
};

void HandleFOrdLessThanEqual(void* op, ParseProgram* prog);
struct SFOrdLessThanEqual {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 Operand1Id;
  uint32 Operand2Id;
};

void HandleFUnordLessThanEqual(void* op, ParseProgram* prog);
struct SFUnordLessThanEqual {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 Operand1Id;
  uint32 Operand2Id;
};

void HandleFOrdGreaterThanEqual(void* op, ParseProgram* prog);
struct SFOrdGreaterThanEqual {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 Operand1Id;
  uint32 Operand2Id;
};

void HandleFUnordGreaterThanEqual(void* op, ParseProgram* prog);
struct SFUnordGreaterThanEqual {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 Operand1Id;
  uint32 Operand2Id;
};

void HandleShiftRightLogical(void* op, ParseProgram* prog);
struct SShiftRightLogical {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 BaseId;
  uint32 ShiftId;
};

void HandleShiftRightArithmetic(void* op, ParseProgram* prog);
struct SShiftRightArithmetic {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 BaseId;
  uint32 ShiftId;
};

void HandleShiftLeftLogical(void* op, ParseProgram* prog);
struct SShiftLeftLogical {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 BaseId;
  uint32 ShiftId;
};

void HandleBitwiseOr(void* op, ParseProgram* prog);
struct SBitwiseOr {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 Operand1Id;
  uint32 Operand2Id;
};

void HandleBitwiseXor(void* op, ParseProgram* prog);
struct SBitwiseXor {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 Operand1Id;
  uint32 Operand2Id;
};

void HandleBitwiseAnd(void* op, ParseProgram* prog);
struct SBitwiseAnd {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 Operand1Id;
  uint32 Operand2Id;
};

void HandleNot(void* op, ParseProgram* prog);
struct SNot {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 OperandId;
};

void HandleBitFieldInsert(void* op, ParseProgram* prog);
struct SBitFieldInsert {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 BaseId;
  uint32 InsertId;
  uint32 OffsetId;
  uint32 CountId;
};

void HandleBitFieldSExtract(void* op, ParseProgram* prog);
struct SBitFieldSExtract {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 BaseId;
  uint32 OffsetId;
  uint32 CountId;
};

void HandleBitFieldUExtract(void* op, ParseProgram* prog);
struct SBitFieldUExtract {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 BaseId;
  uint32 OffsetId;
  uint32 CountId;
};

void HandleBitReverse(void* op, ParseProgram* prog);
struct SBitReverse {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 BaseId;
};

void HandleBitCount(void* op, ParseProgram* prog);
struct SBitCount {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 BaseId;
};

void HandleDPdx(void* op, ParseProgram* prog);
struct SDPdx {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 PId;
};

void HandleDPdy(void* op, ParseProgram* prog);
struct SDPdy {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 PId;
};

void HandleFwidth(void* op, ParseProgram* prog);
struct SFwidth {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 PId;
};

void HandleDPdxFine(void* op, ParseProgram* prog);
struct SDPdxFine {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 PId;
};

void HandleDPdyFine(void* op, ParseProgram* prog);
struct SDPdyFine {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 PId;
};

void HandleFwidthFine(void* op, ParseProgram* prog);
struct SFwidthFine {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 PId;
};

void HandleDPdxCoarse(void* op, ParseProgram* prog);
struct SDPdxCoarse {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 PId;
};

void HandleDPdyCoarse(void* op, ParseProgram* prog);
struct SDPdyCoarse {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 PId;
};

void HandleFwidthCoarse(void* op, ParseProgram* prog);
struct SFwidthCoarse {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 PId;
};

void HandleEmitVertex(void* op, ParseProgram* prog);
struct SEmitVertex {
};

void HandleEndPrimitive(void* op, ParseProgram* prog);
struct SEndPrimitive {
};

void HandleEmitStreamVertex(void* op, ParseProgram* prog);
struct SEmitStreamVertex {
  uint32 StreamId;
};

void HandleEndStreamPrimitive(void* op, ParseProgram* prog);
struct SEndStreamPrimitive {
  uint32 StreamId;
};

void HandleControlBarrier(void* op, ParseProgram* prog);
struct SControlBarrier {
  uint32 ExecutionId;
  uint32 MemoryId;
  uint32 SemanticsId;
};

void HandleMemoryBarrier(void* op, ParseProgram* prog);
struct SMemoryBarrier {
  uint32 MemoryId;
  uint32 SemanticsId;
};

void HandleAtomicLoad(void* op, ParseProgram* prog);
struct SAtomicLoad {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 PointerId;
  uint32 ScopeId;
  uint32 SemanticsId;
};

void HandleAtomicStore(void* op, ParseProgram* prog);
struct SAtomicStore {
  uint32 PointerId;
  uint32 ScopeId;
  uint32 SemanticsId;
  uint32 ValueId;
};

void HandleAtomicExchange(void* op, ParseProgram* prog);
struct SAtomicExchange {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 PointerId;
  uint32 ScopeId;
  uint32 SemanticsId;
  uint32 ValueId;
};

void HandleAtomicCompareExchange(void* op, ParseProgram* prog);
struct SAtomicCompareExchange {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 PointerId;
  uint32 ScopeId;
  uint32 EqualId;
  uint32 UnequalId;
  uint32 ValueId;
  uint32 ComparatorId;
};

void HandleAtomicCompareExchangeWeak(void* op, ParseProgram* prog);
struct SAtomicCompareExchangeWeak {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 PointerId;
  uint32 ScopeId;
  uint32 EqualId;
  uint32 UnequalId;
  uint32 ValueId;
  uint32 ComparatorId;
};

void HandleAtomicIIncrement(void* op, ParseProgram* prog);
struct SAtomicIIncrement {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 PointerId;
  uint32 ScopeId;
  uint32 SemanticsId;
};

void HandleAtomicIDecrement(void* op, ParseProgram* prog);
struct SAtomicIDecrement {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 PointerId;
  uint32 ScopeId;
  uint32 SemanticsId;
};

void HandleAtomicIAdd(void* op, ParseProgram* prog);
struct SAtomicIAdd {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 PointerId;
  uint32 ScopeId;
  uint32 SemanticsId;
  uint32 ValueId;
};

void HandleAtomicISub(void* op, ParseProgram* prog);
struct SAtomicISub {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 PointerId;
  uint32 ScopeId;
  uint32 SemanticsId;
  uint32 ValueId;
};

void HandleAtomicSMin(void* op, ParseProgram* prog);
struct SAtomicSMin {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 PointerId;
  uint32 ScopeId;
  uint32 SemanticsId;
  uint32 ValueId;
};

void HandleAtomicUMin(void* op, ParseProgram* prog);
struct SAtomicUMin {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 PointerId;
  uint32 ScopeId;
  uint32 SemanticsId;
  uint32 ValueId;
};

void HandleAtomicSMax(void* op, ParseProgram* prog);
struct SAtomicSMax {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 PointerId;
  uint32 ScopeId;
  uint32 SemanticsId;
  uint32 ValueId;
};

void HandleAtomicUMax(void* op, ParseProgram* prog);
struct SAtomicUMax {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 PointerId;
  uint32 ScopeId;
  uint32 SemanticsId;
  uint32 ValueId;
};

void HandleAtomicAnd(void* op, ParseProgram* prog);
struct SAtomicAnd {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 PointerId;
  uint32 ScopeId;
  uint32 SemanticsId;
  uint32 ValueId;
};

void HandleAtomicOr(void* op, ParseProgram* prog);
struct SAtomicOr {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 PointerId;
  uint32 ScopeId;
  uint32 SemanticsId;
  uint32 ValueId;
};

void HandleAtomicXor(void* op, ParseProgram* prog);
struct SAtomicXor {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 PointerId;
  uint32 ScopeId;
  uint32 SemanticsId;
  uint32 ValueId;
};

void HandlePhi(void* op, ParseProgram* prog);
struct SPhi {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 VariableIdsCount;
  uint32* VariableIds;
};

void HandleLoopMerge(void* op, ParseProgram* prog);
struct SLoopMerge {
  uint32 MergeBlockId;
  spv::LoopControlMask LoopControl;
};

void HandleSelectionMerge(void* op, ParseProgram* prog);
struct SSelectionMerge {
  uint32 MergeBlockId;
  spv::SelectionControlMask SelectionControl;
};

void HandleLabel(void* op, ParseProgram* prog);
struct SLabel {
  uint32 ResultId;
};

void HandleBranch(void* op, ParseProgram* prog);
struct SBranch {
  uint32 TargetLabelId;
};

void HandleBranchConditional(void* op, ParseProgram* prog);
struct SBranchConditional {
  uint32 ConditionId;
  uint32 TrueLabelId;
  uint32 FalseLabelId;
  uint32 BranchweightsCount;
  uint32* Branchweights;
};

void HandleSwitch(void* op, ParseProgram* prog);
struct SSwitch {
  uint32 SelectorId;
  uint32 DefaultId;
  uint32 literalIdsCount;
  uint32* literalIds;
};

void HandleKill(void* op, ParseProgram* prog);
struct SKill {
};

void HandleReturn(void* op, ParseProgram* prog);
struct SReturn {
};

void HandleReturnValue(void* op, ParseProgram* prog);
struct SReturnValue {
  uint32 ValueId;
};

void HandleUnreachable(void* op, ParseProgram* prog);
struct SUnreachable {
};

void HandleLifetimeStart(void* op, ParseProgram* prog);
struct SLifetimeStart {
  uint32 PointerId;
  uint32 Size;
};

void HandleLifetimeStop(void* op, ParseProgram* prog);
struct SLifetimeStop {
  uint32 PointerId;
  uint32 Size;
};

void HandleAsyncGroupCopy(void* op, ParseProgram* prog);
struct SAsyncGroupCopy {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 ExecutionId;
  uint32 DestinationId;
  uint32 SourceId;
  uint32 NumElementsId;
  uint32 StrideId;
  uint32 EventId;
};

void HandleWaitGroupEvents(void* op, ParseProgram* prog);
struct SWaitGroupEvents {
  uint32 ExecutionId;
  uint32 NumEventsId;
  uint32 EventsListId;
};

void HandleGroupAll(void* op, ParseProgram* prog);
struct SGroupAll {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 ExecutionId;
  uint32 PredicateId;
};

void HandleGroupAny(void* op, ParseProgram* prog);
struct SGroupAny {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 ExecutionId;
  uint32 PredicateId;
};

void HandleGroupBroadcast(void* op, ParseProgram* prog);
struct SGroupBroadcast {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 ExecutionId;
  uint32 ValueId;
  uint32 LocalIdId;
};

void HandleGroupIAdd(void* op, ParseProgram* prog);
struct SGroupIAdd {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 ExecutionId;
  spv::GroupOperation Operation;
  uint32 XId;
};

void HandleGroupFAdd(void* op, ParseProgram* prog);
struct SGroupFAdd {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 ExecutionId;
  spv::GroupOperation Operation;
  uint32 XId;
};

void HandleGroupFMin(void* op, ParseProgram* prog);
struct SGroupFMin {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 ExecutionId;
  spv::GroupOperation Operation;
  uint32 XId;
};

void HandleGroupUMin(void* op, ParseProgram* prog);
struct SGroupUMin {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 ExecutionId;
  spv::GroupOperation Operation;
  uint32 XId;
};

void HandleGroupSMin(void* op, ParseProgram* prog);
struct SGroupSMin {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 ExecutionId;
  spv::GroupOperation Operation;
  uint32 XId;
};

void HandleGroupFMax(void* op, ParseProgram* prog);
struct SGroupFMax {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 ExecutionId;
  spv::GroupOperation Operation;
  uint32 XId;
};

void HandleGroupUMax(void* op, ParseProgram* prog);
struct SGroupUMax {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 ExecutionId;
  spv::GroupOperation Operation;
  uint32 XId;
};

void HandleGroupSMax(void* op, ParseProgram* prog);
struct SGroupSMax {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 ExecutionId;
  spv::GroupOperation Operation;
  uint32 XId;
};

void HandleReadPipe(void* op, ParseProgram* prog);
struct SReadPipe {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 PipeId;
  uint32 PointerId;
};

void HandleWritePipe(void* op, ParseProgram* prog);
struct SWritePipe {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 PipeId;
  uint32 PointerId;
};

void HandleReservedReadPipe(void* op, ParseProgram* prog);
struct SReservedReadPipe {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 PipeId;
  uint32 ReserveIdId;
  uint32 IndexId;
  uint32 PointerId;
};

void HandleReservedWritePipe(void* op, ParseProgram* prog);
struct SReservedWritePipe {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 PipeId;
  uint32 ReserveIdId;
  uint32 IndexId;
  uint32 PointerId;
};

void HandleReserveReadPipePackets(void* op, ParseProgram* prog);
struct SReserveReadPipePackets {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 PipeId;
  uint32 NumPacketsId;
};

void HandleReserveWritePipePackets(void* op, ParseProgram* prog);
struct SReserveWritePipePackets {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 PipeId;
  uint32 NumPacketsId;
};

void HandleCommitReadPipe(void* op, ParseProgram* prog);
struct SCommitReadPipe {
  uint32 PipeId;
  uint32 ReserveIdId;
};

void HandleCommitWritePipe(void* op, ParseProgram* prog);
struct SCommitWritePipe {
  uint32 PipeId;
  uint32 ReserveIdId;
};

void HandleIsValidReserveId(void* op, ParseProgram* prog);
struct SIsValidReserveId {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 ReserveIdId;
};

void HandleGetNumPipePackets(void* op, ParseProgram* prog);
struct SGetNumPipePackets {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 PipeId;
};

void HandleGetMaxPipePackets(void* op, ParseProgram* prog);
struct SGetMaxPipePackets {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 PipeId;
};

void HandleGroupReserveReadPipePackets(void* op, ParseProgram* prog);
struct SGroupReserveReadPipePackets {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 ExecutionId;
  uint32 PipeId;
  uint32 NumPacketsId;
};

void HandleGroupReserveWritePipePackets(void* op, ParseProgram* prog);
struct SGroupReserveWritePipePackets {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 ExecutionId;
  uint32 PipeId;
  uint32 NumPacketsId;
};

void HandleGroupCommitReadPipe(void* op, ParseProgram* prog);
struct SGroupCommitReadPipe {
  uint32 ExecutionId;
  uint32 PipeId;
  uint32 ReserveIdId;
};

void HandleGroupCommitWritePipe(void* op, ParseProgram* prog);
struct SGroupCommitWritePipe {
  uint32 ExecutionId;
  uint32 PipeId;
  uint32 ReserveIdId;
};

void HandleEnqueueMarker(void* op, ParseProgram* prog);
struct SEnqueueMarker {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 QueueId;
  uint32 NumEventsId;
  uint32 WaitEventsId;
  uint32 RetEventId;
};

void HandleEnqueueKernel(void* op, ParseProgram* prog);
struct SEnqueueKernel {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 QueueId;
  uint32 FlagsId;
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

void HandleGetKernelNDrangeSubGroupCount(void* op, ParseProgram* prog);
struct SGetKernelNDrangeSubGroupCount {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 NDRangeId;
  uint32 InvokeId;
  uint32 ParamId;
  uint32 ParamSizeId;
  uint32 ParamAlignId;
};

void HandleGetKernelNDrangeMaxSubGroupSize(void* op, ParseProgram* prog);
struct SGetKernelNDrangeMaxSubGroupSize {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 NDRangeId;
  uint32 InvokeId;
  uint32 ParamId;
  uint32 ParamSizeId;
  uint32 ParamAlignId;
};

void HandleGetKernelWorkGroupSize(void* op, ParseProgram* prog);
struct SGetKernelWorkGroupSize {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 InvokeId;
  uint32 ParamId;
  uint32 ParamSizeId;
  uint32 ParamAlignId;
};

void HandleGetKernelPreferredWorkGroupSizeMultiple(void* op, ParseProgram* prog);
struct SGetKernelPreferredWorkGroupSizeMultiple {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 InvokeId;
  uint32 ParamId;
  uint32 ParamSizeId;
  uint32 ParamAlignId;
};

void HandleRetainEvent(void* op, ParseProgram* prog);
struct SRetainEvent {
  uint32 EventId;
};

void HandleReleaseEvent(void* op, ParseProgram* prog);
struct SReleaseEvent {
  uint32 EventId;
};

void HandleCreateUserEvent(void* op, ParseProgram* prog);
struct SCreateUserEvent {
  uint32 ResultTypeId;
  uint32 ResultId;
};

void HandleIsValidEvent(void* op, ParseProgram* prog);
struct SIsValidEvent {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 EventId;
};

void HandleSetUserEventStatus(void* op, ParseProgram* prog);
struct SSetUserEventStatus {
  uint32 EventId;
  uint32 StatusId;
};

void HandleCaptureEventProfilingInfo(void* op, ParseProgram* prog);
struct SCaptureEventProfilingInfo {
  uint32 EventId;
  uint32 ProfilingInfoId;
  uint32 ValueId;
};

void HandleGetDefaultQueue(void* op, ParseProgram* prog);
struct SGetDefaultQueue {
  uint32 ResultTypeId;
  uint32 ResultId;
};

void HandleBuildNDRange(void* op, ParseProgram* prog);
struct SBuildNDRange {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 GlobalWorkSizeId;
  uint32 LocalWorkSizeId;
  uint32 GlobalWorkOffsetId;
};

#pragma pack(pop)

extern void* LUTOpWordTypes[(uint32)Op::COUNT+1];

extern uint32 LUTOpWordTypesCount[(uint32)Op::COUNT+1];

typedef void(*OpHandler)(void*, ParseProgram*);
extern OpHandler LUTHandlerMethods[(uint32)Op::COUNT+1];