#pragma once
#include "types.h"
#include "lookups.h"

struct Program;

#pragma pack(push, 1)
void HandleNop(void* op, Program* prog);
struct SNop {
};

void HandleUndef(void* op, Program* prog);
struct SUndef {
  uint32 ResultTypeId;
  uint32 ResultId;
};

void HandleSource(void* op, Program* prog);
struct SSource {
  spv::SourceLanguage SourceLanguage;
  uint32 Version;
};

void HandleSourceExtension(void* op, Program* prog);
struct SSourceExtension {
  char* Extension;
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

void HandleExtension(void* op, Program* prog);
struct SExtension {
  char* Name;
};

void HandleExtInstImport(void* op, Program* prog);
struct SExtInstImport {
  uint32 ResultId;
  char* Name;
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

void HandleMemoryModel(void* op, Program* prog);
struct SMemoryModel {
  spv::AddressingModel AddressingModel;
  spv::MemoryModel MemoryModel;
};

void HandleEntryPoint(void* op, Program* prog);
struct SEntryPoint {
  spv::ExecutionModel ExecutionModel;
  uint32 EntryPointId;
  char* Name;
};

void HandleExecutionMode(void* op, Program* prog);
struct SExecutionMode {
  uint32 EntryPointId;
  spv::ExecutionMode Mode;
  uint32 ExecutionModesCount;
  uint32* ExecutionModes;
};

void HandleCapability(void* op, Program* prog);
struct SCapability {
  spv::Capability Capability;
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
  uint32 ComponentTypeId;
  uint32 ComponentCount;
};

void HandleTypeMatrix(void* op, Program* prog);
struct STypeMatrix {
  uint32 ResultId;
  uint32 ColumnTypeId;
  uint32 ColumnCount;
};

void HandleTypeImage(void* op, Program* prog);
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

void HandleTypeSampler(void* op, Program* prog);
struct STypeSampler {
  uint32 ResultId;
};

void HandleTypeSampledImage(void* op, Program* prog);
struct STypeSampledImage {
  uint32 ResultId;
  uint32 ImageTypeId;
};

void HandleTypeArray(void* op, Program* prog);
struct STypeArray {
  uint32 ResultId;
  uint32 ElementTypeId;
  uint32 LengthId;
};

void HandleTypeRuntimeArray(void* op, Program* prog);
struct STypeRuntimeArray {
  uint32 ResultId;
  uint32 ElementTypeId;
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
  spv::StorageClass StorageClass;
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
  spv::AccessQualifier Qualifier;
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
  spv::SamplerAddressingMode SamplerAddressingMode;
  uint32 Param;
  spv::SamplerFilterMode SamplerFilterMode;
};

void HandleConstantNull(void* op, Program* prog);
struct SConstantNull {
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

void HandleSpecConstantOp(void* op, Program* prog);
struct SSpecConstantOp {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 Opcode;
  uint32 OperandsIdsCount;
  uint32* OperandsIds;
};

void HandleFunction(void* op, Program* prog);
struct SFunction {
  uint32 ResultTypeId;
  uint32 ResultId;
  spv::FunctionControlMask FunctionControl;
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

void HandleVariable(void* op, Program* prog);
struct SVariable {
  uint32 ResultTypeId;
  uint32 ResultId;
  spv::StorageClass StorageClass;
  uint32 InitializerId;
};

void HandleImageTexelPointer(void* op, Program* prog);
struct SImageTexelPointer {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 ImageId;
  uint32 CoordinateId;
  uint32 SampleId;
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

void HandlePtrAccessChain(void* op, Program* prog);
struct SPtrAccessChain {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 BaseId;
  uint32 ElementId;
  uint32 IndexesIdsCount;
  uint32* IndexesIds;
};

void HandleArrayLength(void* op, Program* prog);
struct SArrayLength {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 StructureId;
  uint32 Arraymember;
};

void HandleGenericPtrMemSemantics(void* op, Program* prog);
struct SGenericPtrMemSemantics {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 PointerId;
};

void HandleDecorate(void* op, Program* prog);
struct SDecorate {
  uint32 TargetId;
  spv::Decoration Decoration;
  uint32 DecorationsCount;
  uint32* Decorations;
};

void HandleMemberDecorate(void* op, Program* prog);
struct SMemberDecorate {
  uint32 StructureTypeId;
  uint32 Member;
  spv::Decoration Decoration;
  uint32 DecorationsCount;
  uint32* Decorations;
};

void HandleDecorationGroup(void* op, Program* prog);
struct SDecorationGroup {
  uint32 ResultId;
};

void HandleGroupDecorate(void* op, Program* prog);
struct SGroupDecorate {
  uint32 DecorationGroupId;
  uint32 TargetsIdsCount;
  uint32* TargetsIds;
};

void HandleGroupMemberDecorate(void* op, Program* prog);
struct SGroupMemberDecorate {
  uint32 DecorationGroupId;
  uint32 IdsCount;
  uint32* Ids;
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

void HandleTranspose(void* op, Program* prog);
struct STranspose {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 MatrixId;
};

void HandleSampledImage(void* op, Program* prog);
struct SSampledImage {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 ImageId;
  uint32 SamplerId;
};

void HandleImageSampleImplicitLod(void* op, Program* prog);
struct SImageSampleImplicitLod {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 SampledImageId;
  uint32 CoordinateId;
  uint32 ImageOperandsIdsCount;
  uint32* ImageOperandsIds;
};

void HandleImageSampleExplicitLod(void* op, Program* prog);
struct SImageSampleExplicitLod {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 SampledImageId;
  uint32 CoordinateId;
  uint32 ImageOperandsIdsCount;
  uint32* ImageOperandsIds;
};

void HandleImageSampleDrefImplicitLod(void* op, Program* prog);
struct SImageSampleDrefImplicitLod {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 SampledImageId;
  uint32 CoordinateId;
  uint32 DrefId;
  uint32 ImageOperandsIdsCount;
  uint32* ImageOperandsIds;
};

void HandleImageSampleDrefExplicitLod(void* op, Program* prog);
struct SImageSampleDrefExplicitLod {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 SampledImageId;
  uint32 CoordinateId;
  uint32 DrefId;
  uint32 ImageOperandsIdsCount;
  uint32* ImageOperandsIds;
};

void HandleImageSampleProjImplicitLod(void* op, Program* prog);
struct SImageSampleProjImplicitLod {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 SampledImageId;
  uint32 CoordinateId;
  uint32 ImageOperandsIdsCount;
  uint32* ImageOperandsIds;
};

void HandleImageSampleProjExplicitLod(void* op, Program* prog);
struct SImageSampleProjExplicitLod {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 SampledImageId;
  uint32 CoordinateId;
  uint32 ImageOperandsIdsCount;
  uint32* ImageOperandsIds;
};

void HandleImageSampleProjDrefImplicitLod(void* op, Program* prog);
struct SImageSampleProjDrefImplicitLod {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 SampledImageId;
  uint32 CoordinateId;
  uint32 DrefId;
  uint32 ImageOperandsIdsCount;
  uint32* ImageOperandsIds;
};

void HandleImageSampleProjDrefExplicitLod(void* op, Program* prog);
struct SImageSampleProjDrefExplicitLod {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 SampledImageId;
  uint32 CoordinateId;
  uint32 DrefId;
  uint32 ImageOperandsIdsCount;
  uint32* ImageOperandsIds;
};

void HandleImageFetch(void* op, Program* prog);
struct SImageFetch {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 SampledImageId;
  uint32 CoordinateId;
  uint32 ImageOperandsIdsCount;
  uint32* ImageOperandsIds;
};

void HandleImageGather(void* op, Program* prog);
struct SImageGather {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 SampledImageId;
  uint32 CoordinateId;
  uint32 ComponentId;
  uint32 ImageOperandsIdsCount;
  uint32* ImageOperandsIds;
};

void HandleImageDrefGather(void* op, Program* prog);
struct SImageDrefGather {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 SampledImageId;
  uint32 CoordinateId;
  uint32 DrefId;
  uint32 ImageOperandsIdsCount;
  uint32* ImageOperandsIds;
};

void HandleImageRead(void* op, Program* prog);
struct SImageRead {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 ImageId;
  uint32 CoordinateId;
};

void HandleImageWrite(void* op, Program* prog);
struct SImageWrite {
  uint32 ImageId;
  uint32 CoordinateId;
  uint32 TexelId;
};

void HandleImageQueryDim(void* op, Program* prog);
struct SImageQueryDim {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 ImageId;
};

void HandleImageQueryFormat(void* op, Program* prog);
struct SImageQueryFormat {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 ImageId;
};

void HandleImageQueryOrder(void* op, Program* prog);
struct SImageQueryOrder {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 ImageId;
};

void HandleImageQuerySizeLod(void* op, Program* prog);
struct SImageQuerySizeLod {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 ImageId;
  uint32 LevelofDetailId;
};

void HandleImageQuerySize(void* op, Program* prog);
struct SImageQuerySize {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 ImageId;
};

void HandleImageQueryLod(void* op, Program* prog);
struct SImageQueryLod {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 ImageId;
  uint32 CoordinateId;
};

void HandleImageQueryLevels(void* op, Program* prog);
struct SImageQueryLevels {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 ImageId;
};

void HandleImageQuerySamples(void* op, Program* prog);
struct SImageQuerySamples {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 ImageId;
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
  uint32 UnsignedValueId;
};

void HandleUConvert(void* op, Program* prog);
struct SUConvert {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 UnsignedValueId;
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

void HandleQuantizeToF16(void* op, Program* prog);
struct SQuantizeToF16 {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 ValueId;
};

void HandleConvertPtrToU(void* op, Program* prog);
struct SConvertPtrToU {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 PointerId;
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

void HandleConvertUToPtr(void* op, Program* prog);
struct SConvertUToPtr {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 IntegerValueId;
};

void HandlePtrCastToGeneric(void* op, Program* prog);
struct SPtrCastToGeneric {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 PointerId;
};

void HandleGenericCastToPtr(void* op, Program* prog);
struct SGenericCastToPtr {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 PointerId;
};

void HandleGenericCastToPtrExplicit(void* op, Program* prog);
struct SGenericCastToPtrExplicit {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 PointerId;
  spv::StorageClass Storage;
};

void HandleBitcast(void* op, Program* prog);
struct SBitcast {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 OperandId;
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

void HandleIAddCarry(void* op, Program* prog);
struct SIAddCarry {
  uint32 ResultTypeId;
  uint32 ResultId;
};

void HandleISubBorrow(void* op, Program* prog);
struct SISubBorrow {
  uint32 ResultTypeId;
  uint32 ResultId;
};

void HandleIMulExtended(void* op, Program* prog);
struct SIMulExtended {
  uint32 ResultTypeId;
  uint32 ResultId;
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

void HandleLogicalEqual(void* op, Program* prog);
struct SLogicalEqual {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 Operand1Id;
  uint32 Operand2Id;
};

void HandleLogicalNotEqual(void* op, Program* prog);
struct SLogicalNotEqual {
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

void HandleLogicalAnd(void* op, Program* prog);
struct SLogicalAnd {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 Operand1Id;
  uint32 Operand2Id;
};

void HandleLogicalNot(void* op, Program* prog);
struct SLogicalNot {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 OperandId;
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

void HandleINotEqual(void* op, Program* prog);
struct SINotEqual {
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

void HandleShiftRightLogical(void* op, Program* prog);
struct SShiftRightLogical {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 BaseId;
  uint32 ShiftId;
};

void HandleShiftRightArithmetic(void* op, Program* prog);
struct SShiftRightArithmetic {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 BaseId;
  uint32 ShiftId;
};

void HandleShiftLeftLogical(void* op, Program* prog);
struct SShiftLeftLogical {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 BaseId;
  uint32 ShiftId;
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

void HandleNot(void* op, Program* prog);
struct SNot {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 OperandId;
};

void HandleBitFieldInsert(void* op, Program* prog);
struct SBitFieldInsert {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 BaseId;
  uint32 InsertId;
  uint32 OffsetId;
  uint32 CountId;
};

void HandleBitFieldSExtract(void* op, Program* prog);
struct SBitFieldSExtract {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 BaseId;
  uint32 OffsetId;
  uint32 CountId;
};

void HandleBitFieldUExtract(void* op, Program* prog);
struct SBitFieldUExtract {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 BaseId;
  uint32 OffsetId;
  uint32 CountId;
};

void HandleBitReverse(void* op, Program* prog);
struct SBitReverse {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 BaseId;
};

void HandleBitCount(void* op, Program* prog);
struct SBitCount {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 BaseId;
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
  uint32 ExecutionId;
  uint32 MemoryId;
  uint32 SemanticsId;
};

void HandleMemoryBarrier(void* op, Program* prog);
struct SMemoryBarrier {
  uint32 MemoryId;
  uint32 SemanticsId;
};

void HandleAtomicLoad(void* op, Program* prog);
struct SAtomicLoad {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 PointerId;
  uint32 ScopeId;
  uint32 SemanticsId;
};

void HandleAtomicStore(void* op, Program* prog);
struct SAtomicStore {
  uint32 PointerId;
  uint32 ScopeId;
  uint32 SemanticsId;
  uint32 ValueId;
};

void HandleAtomicExchange(void* op, Program* prog);
struct SAtomicExchange {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 PointerId;
  uint32 ScopeId;
  uint32 SemanticsId;
  uint32 ValueId;
};

void HandleAtomicCompareExchange(void* op, Program* prog);
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

void HandleAtomicCompareExchangeWeak(void* op, Program* prog);
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

void HandleAtomicIIncrement(void* op, Program* prog);
struct SAtomicIIncrement {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 PointerId;
  uint32 ScopeId;
  uint32 SemanticsId;
};

void HandleAtomicIDecrement(void* op, Program* prog);
struct SAtomicIDecrement {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 PointerId;
  uint32 ScopeId;
  uint32 SemanticsId;
};

void HandleAtomicIAdd(void* op, Program* prog);
struct SAtomicIAdd {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 PointerId;
  uint32 ScopeId;
  uint32 SemanticsId;
  uint32 ValueId;
};

void HandleAtomicISub(void* op, Program* prog);
struct SAtomicISub {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 PointerId;
  uint32 ScopeId;
  uint32 SemanticsId;
  uint32 ValueId;
};

void HandleAtomicSMin(void* op, Program* prog);
struct SAtomicSMin {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 PointerId;
  uint32 ScopeId;
  uint32 SemanticsId;
  uint32 ValueId;
};

void HandleAtomicUMin(void* op, Program* prog);
struct SAtomicUMin {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 PointerId;
  uint32 ScopeId;
  uint32 SemanticsId;
  uint32 ValueId;
};

void HandleAtomicSMax(void* op, Program* prog);
struct SAtomicSMax {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 PointerId;
  uint32 ScopeId;
  uint32 SemanticsId;
  uint32 ValueId;
};

void HandleAtomicUMax(void* op, Program* prog);
struct SAtomicUMax {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 PointerId;
  uint32 ScopeId;
  uint32 SemanticsId;
  uint32 ValueId;
};

void HandleAtomicAnd(void* op, Program* prog);
struct SAtomicAnd {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 PointerId;
  uint32 ScopeId;
  uint32 SemanticsId;
  uint32 ValueId;
};

void HandleAtomicOr(void* op, Program* prog);
struct SAtomicOr {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 PointerId;
  uint32 ScopeId;
  uint32 SemanticsId;
  uint32 ValueId;
};

void HandleAtomicXor(void* op, Program* prog);
struct SAtomicXor {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 PointerId;
  uint32 ScopeId;
  uint32 SemanticsId;
  uint32 ValueId;
};

void HandlePhi(void* op, Program* prog);
struct SPhi {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 VariableIdsCount;
  uint32* VariableIds;
};

void HandleLoopMerge(void* op, Program* prog);
struct SLoopMerge {
  uint32 MergeBlockId;
  spv::LoopControlMask LoopControl;
};

void HandleSelectionMerge(void* op, Program* prog);
struct SSelectionMerge {
  uint32 MergeBlockId;
  spv::SelectionControlMask SelectionControl;
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
  uint32 PointerId;
  uint32 Size;
};

void HandleLifetimeStop(void* op, Program* prog);
struct SLifetimeStop {
  uint32 PointerId;
  uint32 Size;
};

void HandleAsyncGroupCopy(void* op, Program* prog);
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

void HandleWaitGroupEvents(void* op, Program* prog);
struct SWaitGroupEvents {
  uint32 ExecutionId;
  uint32 NumEventsId;
  uint32 EventsListId;
};

void HandleGroupAll(void* op, Program* prog);
struct SGroupAll {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 ExecutionId;
  uint32 PredicateId;
};

void HandleGroupAny(void* op, Program* prog);
struct SGroupAny {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 ExecutionId;
  uint32 PredicateId;
};

void HandleGroupBroadcast(void* op, Program* prog);
struct SGroupBroadcast {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 ExecutionId;
  uint32 ValueId;
  uint32 LocalIdId;
};

void HandleGroupIAdd(void* op, Program* prog);
struct SGroupIAdd {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 ExecutionId;
  spv::GroupOperation Operation;
  uint32 XId;
};

void HandleGroupFAdd(void* op, Program* prog);
struct SGroupFAdd {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 ExecutionId;
  spv::GroupOperation Operation;
  uint32 XId;
};

void HandleGroupFMin(void* op, Program* prog);
struct SGroupFMin {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 ExecutionId;
  spv::GroupOperation Operation;
  uint32 XId;
};

void HandleGroupUMin(void* op, Program* prog);
struct SGroupUMin {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 ExecutionId;
  spv::GroupOperation Operation;
  uint32 XId;
};

void HandleGroupSMin(void* op, Program* prog);
struct SGroupSMin {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 ExecutionId;
  spv::GroupOperation Operation;
  uint32 XId;
};

void HandleGroupFMax(void* op, Program* prog);
struct SGroupFMax {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 ExecutionId;
  spv::GroupOperation Operation;
  uint32 XId;
};

void HandleGroupUMax(void* op, Program* prog);
struct SGroupUMax {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 ExecutionId;
  spv::GroupOperation Operation;
  uint32 XId;
};

void HandleGroupSMax(void* op, Program* prog);
struct SGroupSMax {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 ExecutionId;
  spv::GroupOperation Operation;
  uint32 XId;
};

void HandleReadPipe(void* op, Program* prog);
struct SReadPipe {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 PipeId;
  uint32 PointerId;
};

void HandleWritePipe(void* op, Program* prog);
struct SWritePipe {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 PipeId;
  uint32 PointerId;
};

void HandleReservedReadPipe(void* op, Program* prog);
struct SReservedReadPipe {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 PipeId;
  uint32 ReserveIdId;
  uint32 IndexId;
  uint32 PointerId;
};

void HandleReservedWritePipe(void* op, Program* prog);
struct SReservedWritePipe {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 PipeId;
  uint32 ReserveIdId;
  uint32 IndexId;
  uint32 PointerId;
};

void HandleReserveReadPipePackets(void* op, Program* prog);
struct SReserveReadPipePackets {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 PipeId;
  uint32 NumPacketsId;
};

void HandleReserveWritePipePackets(void* op, Program* prog);
struct SReserveWritePipePackets {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 PipeId;
  uint32 NumPacketsId;
};

void HandleCommitReadPipe(void* op, Program* prog);
struct SCommitReadPipe {
  uint32 PipeId;
  uint32 ReserveIdId;
};

void HandleCommitWritePipe(void* op, Program* prog);
struct SCommitWritePipe {
  uint32 PipeId;
  uint32 ReserveIdId;
};

void HandleIsValidReserveId(void* op, Program* prog);
struct SIsValidReserveId {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 ReserveIdId;
};

void HandleGetNumPipePackets(void* op, Program* prog);
struct SGetNumPipePackets {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 PipeId;
};

void HandleGetMaxPipePackets(void* op, Program* prog);
struct SGetMaxPipePackets {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 PipeId;
};

void HandleGroupReserveReadPipePackets(void* op, Program* prog);
struct SGroupReserveReadPipePackets {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 ExecutionId;
  uint32 PipeId;
  uint32 NumPacketsId;
};

void HandleGroupReserveWritePipePackets(void* op, Program* prog);
struct SGroupReserveWritePipePackets {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 ExecutionId;
  uint32 PipeId;
  uint32 NumPacketsId;
};

void HandleGroupCommitReadPipe(void* op, Program* prog);
struct SGroupCommitReadPipe {
  uint32 ExecutionId;
  uint32 PipeId;
  uint32 ReserveIdId;
};

void HandleGroupCommitWritePipe(void* op, Program* prog);
struct SGroupCommitWritePipe {
  uint32 ExecutionId;
  uint32 PipeId;
  uint32 ReserveIdId;
};

void HandleEnqueueMarker(void* op, Program* prog);
struct SEnqueueMarker {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 QueueId;
  uint32 NumEventsId;
  uint32 WaitEventsId;
  uint32 RetEventId;
};

void HandleEnqueueKernel(void* op, Program* prog);
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

void HandleGetKernelNDrangeSubGroupCount(void* op, Program* prog);
struct SGetKernelNDrangeSubGroupCount {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 NDRangeId;
  uint32 InvokeId;
  uint32 ParamId;
  uint32 ParamSizeId;
  uint32 ParamAlignId;
};

void HandleGetKernelNDrangeMaxSubGroupSize(void* op, Program* prog);
struct SGetKernelNDrangeMaxSubGroupSize {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 NDRangeId;
  uint32 InvokeId;
  uint32 ParamId;
  uint32 ParamSizeId;
  uint32 ParamAlignId;
};

void HandleGetKernelWorkGroupSize(void* op, Program* prog);
struct SGetKernelWorkGroupSize {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 InvokeId;
  uint32 ParamId;
  uint32 ParamSizeId;
  uint32 ParamAlignId;
};

void HandleGetKernelPreferredWorkGroupSizeMultiple(void* op, Program* prog);
struct SGetKernelPreferredWorkGroupSizeMultiple {
  uint32 ResultTypeId;
  uint32 ResultId;
  uint32 InvokeId;
  uint32 ParamId;
  uint32 ParamSizeId;
  uint32 ParamAlignId;
};

void HandleRetainEvent(void* op, Program* prog);
struct SRetainEvent {
  uint32 EventId;
};

void HandleReleaseEvent(void* op, Program* prog);
struct SReleaseEvent {
  uint32 EventId;
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
  uint32 EventId;
};

void HandleSetUserEventStatus(void* op, Program* prog);
struct SSetUserEventStatus {
  uint32 EventId;
  uint32 StatusId;
};

void HandleCaptureEventProfilingInfo(void* op, Program* prog);
struct SCaptureEventProfilingInfo {
  uint32 EventId;
  uint32 ProfilingInfoId;
  uint32 ValueId;
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

#pragma pack(pop)

extern void* LUTOpWordTypes[Op::COUNT];

extern uint32 LUTOpWordTypesCount[Op::COUNT];

typedef void(*OpHandler)(void*, Program*);
extern OpHandler LUTHandlerMethods[Op::COUNT];