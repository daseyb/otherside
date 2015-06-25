#pragma once
#include "lookups.h"

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
  WordType::TLiteralNumber,
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
  WordType::TId,
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
  WordType::TId,
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
  WordType::TLiteralNumber,
};
static uint32 ConstantWordTypesCount = 4;

static WordType ConstantCompositeWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
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
  WordType::TLiteralNumber,
};
static uint32 SpecConstantWordTypesCount = 4;

static WordType SpecConstantCompositeWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
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
  WordType::TId,
};
static uint32 FunctionCallWordTypesCount = 5;

static WordType ExtInstWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TLiteralNumber,
  WordType::TId,
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
  WordType::TLiteralNumber,
};
static uint32 LoadWordTypesCount = 5;

static WordType StoreWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TLiteralNumber,
};
static uint32 StoreWordTypesCount = 4;

static WordType PhiWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
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
  WordType::TLiteralNumber,
};
static uint32 DecorateWordTypesCount = 4;

static WordType MemberDecorateWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TLiteralNumber,
  WordType::TDecoration,
  WordType::TLiteralNumber,
};
static uint32 MemberDecorateWordTypesCount = 5;

static WordType GroupDecorateWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
};
static uint32 GroupDecorateWordTypesCount = 3;

static WordType GroupMemberDecorateWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
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
  WordType::TLiteralNumber,
};
static uint32 VectorShuffleWordTypesCount = 6;

static WordType CompositeConstructWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
static uint32 CompositeConstructWordTypesCount = 4;

static WordType CompositeExtractWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TLiteralNumber,
};
static uint32 CompositeExtractWordTypesCount = 5;

static WordType CompositeInsertWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TLiteralNumber,
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
  WordType::TLiteralNumber,
};
static uint32 CopyMemoryWordTypesCount = 4;

static WordType CopyMemorySizedWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TLiteralNumber,
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
  WordType::TId,
};
static uint32 AccessChainWordTypesCount = 5;

static WordType InBoundsAccessChainWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
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
  WordType::TLiteralNumber,
};
static uint32 BranchConditionalWordTypesCount = 5;

static WordType SwitchWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
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
  WordType::TId,
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

static void* LUTOpWordTypes[]{
  &NopWordTypes,
  &SourceWordTypes,
  &SourceExtensionWordTypes,
  &ExtensionWordTypes,
  &ExtInstImportWordTypes,
  &MemoryModelWordTypes,
  &EntryPointWordTypes,
  &ExecutionModeWordTypes,
  &TypeVoidWordTypes,
  &TypeBoolWordTypes,
  &TypeIntWordTypes,
  &TypeFloatWordTypes,
  &TypeVectorWordTypes,
  &TypeMatrixWordTypes,
  &TypeSamplerWordTypes,
  &TypeFilterWordTypes,
  &TypeArrayWordTypes,
  &TypeRuntimeArrayWordTypes,
  &TypeStructWordTypes,
  &TypeOpaqueWordTypes,
  &TypePointerWordTypes,
  &TypeFunctionWordTypes,
  &TypeEventWordTypes,
  &TypeDeviceEventWordTypes,
  &TypeReserveIdWordTypes,
  &TypeQueueWordTypes,
  &TypePipeWordTypes,
  &ConstantTrueWordTypes,
  &ConstantFalseWordTypes,
  &ConstantWordTypes,
  &ConstantCompositeWordTypes,
  &ConstantSamplerWordTypes,
  &ConstantNullPointerWordTypes,
  &ConstantNullObjectWordTypes,
  &SpecConstantTrueWordTypes,
  &SpecConstantFalseWordTypes,
  &SpecConstantWordTypes,
  &SpecConstantCompositeWordTypes,
  &VariableWordTypes,
  &VariableArrayWordTypes,
  &FunctionWordTypes,
  &FunctionParameterWordTypes,
  &FunctionEndWordTypes,
  &FunctionCallWordTypes,
  &ExtInstWordTypes,
  &UndefWordTypes,
  &LoadWordTypes,
  &StoreWordTypes,
  &PhiWordTypes,
  &DecorationGroupWordTypes,
  &DecorateWordTypes,
  &MemberDecorateWordTypes,
  &GroupDecorateWordTypes,
  &GroupMemberDecorateWordTypes,
  &NameWordTypes,
  &MemberNameWordTypes,
  &StringWordTypes,
  &LineWordTypes,
  &VectorExtractDynamicWordTypes,
  &VectorInsertDynamicWordTypes,
  &VectorShuffleWordTypes,
  &CompositeConstructWordTypes,
  &CompositeExtractWordTypes,
  &CompositeInsertWordTypes,
  &CopyObjectWordTypes,
  &CopyMemoryWordTypes,
  &CopyMemorySizedWordTypes,
  &SamplerWordTypes,
  &TextureSampleWordTypes,
  &TextureSampleDrefWordTypes,
  &TextureSampleLodWordTypes,
  &TextureSampleProjWordTypes,
  &TextureSampleGradWordTypes,
  &TextureSampleOffsetWordTypes,
  &TextureSampleProjLodWordTypes,
  &TextureSampleProjGradWordTypes,
  &TextureSampleLodOffsetWordTypes,
  &TextureSampleProjOffsetWordTypes,
  &TextureSampleGradOffsetWordTypes,
  &TextureSampleProjLodOffsetWordTypes,
  &TextureSampleProjGradOffsetWordTypes,
  &TextureFetchTexelLodWordTypes,
  &TextureFetchTexelOffsetWordTypes,
  &TextureFetchSampleWordTypes,
  &TextureFetchTexelWordTypes,
  &TextureGatherWordTypes,
  &TextureGatherOffsetWordTypes,
  &TextureGatherOffsetsWordTypes,
  &TextureQuerySizeLodWordTypes,
  &TextureQuerySizeWordTypes,
  &TextureQueryLodWordTypes,
  &TextureQueryLevelsWordTypes,
  &TextureQuerySamplesWordTypes,
  &AccessChainWordTypes,
  &InBoundsAccessChainWordTypes,
  &SNegateWordTypes,
  &FNegateWordTypes,
  &NotWordTypes,
  &AnyWordTypes,
  &AllWordTypes,
  &ConvertFToUWordTypes,
  &ConvertFToSWordTypes,
  &ConvertSToFWordTypes,
  &ConvertUToFWordTypes,
  &UConvertWordTypes,
  &SConvertWordTypes,
  &FConvertWordTypes,
  &ConvertPtrToUWordTypes,
  &ConvertUToPtrWordTypes,
  &PtrCastToGenericWordTypes,
  &GenericCastToPtrWordTypes,
  &BitcastWordTypes,
  &TransposeWordTypes,
  &IsNanWordTypes,
  &IsInfWordTypes,
  &IsFiniteWordTypes,
  &IsNormalWordTypes,
  &SignBitSetWordTypes,
  &LessOrGreaterWordTypes,
  &OrderedWordTypes,
  &UnorderedWordTypes,
  &ArrayLengthWordTypes,
  &IAddWordTypes,
  &FAddWordTypes,
  &ISubWordTypes,
  &FSubWordTypes,
  &IMulWordTypes,
  &FMulWordTypes,
  &UDivWordTypes,
  &SDivWordTypes,
  &FDivWordTypes,
  &UModWordTypes,
  &SRemWordTypes,
  &SModWordTypes,
  &FRemWordTypes,
  &FModWordTypes,
  &VectorTimesScalarWordTypes,
  &MatrixTimesScalarWordTypes,
  &VectorTimesMatrixWordTypes,
  &MatrixTimesVectorWordTypes,
  &MatrixTimesMatrixWordTypes,
  &OuterProductWordTypes,
  &DotWordTypes,
  &ShiftRightLogicalWordTypes,
  &ShiftRightArithmeticWordTypes,
  &ShiftLeftLogicalWordTypes,
  &LogicalOrWordTypes,
  &LogicalXorWordTypes,
  &LogicalAndWordTypes,
  &BitwiseOrWordTypes,
  &BitwiseXorWordTypes,
  &BitwiseAndWordTypes,
  &SelectWordTypes,
  &IEqualWordTypes,
  &FOrdEqualWordTypes,
  &FUnordEqualWordTypes,
  &INotEqualWordTypes,
  &FOrdNotEqualWordTypes,
  &FUnordNotEqualWordTypes,
  &ULessThanWordTypes,
  &SLessThanWordTypes,
  &FOrdLessThanWordTypes,
  &FUnordLessThanWordTypes,
  &UGreaterThanWordTypes,
  &SGreaterThanWordTypes,
  &FOrdGreaterThanWordTypes,
  &FUnordGreaterThanWordTypes,
  &ULessThanEqualWordTypes,
  &SLessThanEqualWordTypes,
  &FOrdLessThanEqualWordTypes,
  &FUnordLessThanEqualWordTypes,
  &UGreaterThanEqualWordTypes,
  &SGreaterThanEqualWordTypes,
  &FOrdGreaterThanEqualWordTypes,
  &FUnordGreaterThanEqualWordTypes,
  &DPdxWordTypes,
  &DPdyWordTypes,
  &FwidthWordTypes,
  &DPdxFineWordTypes,
  &DPdyFineWordTypes,
  &FwidthFineWordTypes,
  &DPdxCoarseWordTypes,
  &DPdyCoarseWordTypes,
  &FwidthCoarseWordTypes,
  &EmitVertexWordTypes,
  &EndPrimitiveWordTypes,
  &EmitStreamVertexWordTypes,
  &EndStreamPrimitiveWordTypes,
  &ControlBarrierWordTypes,
  &MemoryBarrierWordTypes,
  &ImagePointerWordTypes,
  &AtomicInitWordTypes,
  &AtomicLoadWordTypes,
  &AtomicStoreWordTypes,
  &AtomicExchangeWordTypes,
  &AtomicCompareExchangeWordTypes,
  &AtomicCompareExchangeWeakWordTypes,
  &AtomicIIncrementWordTypes,
  &AtomicIDecrementWordTypes,
  &AtomicIAddWordTypes,
  &AtomicISubWordTypes,
  &AtomicUMinWordTypes,
  &AtomicUMaxWordTypes,
  &AtomicAndWordTypes,
  &AtomicOrWordTypes,
  &AtomicXorWordTypes,
  &LoopMergeWordTypes,
  &SelectionMergeWordTypes,
  &LabelWordTypes,
  &BranchWordTypes,
  &BranchConditionalWordTypes,
  &SwitchWordTypes,
  &KillWordTypes,
  &ReturnWordTypes,
  &ReturnValueWordTypes,
  &UnreachableWordTypes,
  &LifetimeStartWordTypes,
  &LifetimeStopWordTypes,
  &CompileFlagWordTypes,
  &AsyncGroupCopyWordTypes,
  &WaitGroupEventsWordTypes,
  &GroupAllWordTypes,
  &GroupAnyWordTypes,
  &GroupBroadcastWordTypes,
  &GroupIAddWordTypes,
  &GroupFAddWordTypes,
  &GroupFMinWordTypes,
  &GroupUMinWordTypes,
  &GroupSMinWordTypes,
  &GroupFMaxWordTypes,
  &GroupUMaxWordTypes,
  &GroupSMaxWordTypes,
  &GenericCastToPtrExplicitWordTypes,
  &GenericPtrMemSemanticsWordTypes,
  &ReadPipeWordTypes,
  &WritePipeWordTypes,
  &ReservedReadPipeWordTypes,
  &ReservedWritePipeWordTypes,
  &ReserveReadPipePacketsWordTypes,
  &ReserveWritePipePacketsWordTypes,
  &CommitReadPipeWordTypes,
  &CommitWritePipeWordTypes,
  &IsValidReserveIdWordTypes,
  &GetNumPipePacketsWordTypes,
  &GetMaxPipePacketsWordTypes,
  &GroupReserveReadPipePacketsWordTypes,
  &GroupReserveWritePipePacketsWordTypes,
  &GroupCommitReadPipeWordTypes,
  &GroupCommitWritePipeWordTypes,
  &EnqueueMarkerWordTypes,
  &EnqueueKernelWordTypes,
  &GetKernelNDrangeSubGroupCountWordTypes,
  &GetKernelNDrangeMaxSubGroupSizeWordTypes,
  &GetKernelWorkGroupSizeWordTypes,
  &GetKernelPreferredWorkGroupSizeMultipleWordTypes,
  &RetainEventWordTypes,
  &ReleaseEventWordTypes,
  &CreateUserEventWordTypes,
  &IsValidEventWordTypes,
  &SetUserEventStatusWordTypes,
  &CaptureEventProfilingInfoWordTypes,
  &GetDefaultQueueWordTypes,
  &BuildNDRangeWordTypes,
  &SatConvertSToUWordTypes,
  &SatConvertUToSWordTypes,
  &AtomicIMinWordTypes,
  &AtomicIMaxWordTypes,
};

static uint32 LUTOpWordTypesCount[]{
  NopWordTypesCount,
  SourceWordTypesCount,
  SourceExtensionWordTypesCount,
  ExtensionWordTypesCount,
  ExtInstImportWordTypesCount,
  MemoryModelWordTypesCount,
  EntryPointWordTypesCount,
  ExecutionModeWordTypesCount,
  TypeVoidWordTypesCount,
  TypeBoolWordTypesCount,
  TypeIntWordTypesCount,
  TypeFloatWordTypesCount,
  TypeVectorWordTypesCount,
  TypeMatrixWordTypesCount,
  TypeSamplerWordTypesCount,
  TypeFilterWordTypesCount,
  TypeArrayWordTypesCount,
  TypeRuntimeArrayWordTypesCount,
  TypeStructWordTypesCount,
  TypeOpaqueWordTypesCount,
  TypePointerWordTypesCount,
  TypeFunctionWordTypesCount,
  TypeEventWordTypesCount,
  TypeDeviceEventWordTypesCount,
  TypeReserveIdWordTypesCount,
  TypeQueueWordTypesCount,
  TypePipeWordTypesCount,
  ConstantTrueWordTypesCount,
  ConstantFalseWordTypesCount,
  ConstantWordTypesCount,
  ConstantCompositeWordTypesCount,
  ConstantSamplerWordTypesCount,
  ConstantNullPointerWordTypesCount,
  ConstantNullObjectWordTypesCount,
  SpecConstantTrueWordTypesCount,
  SpecConstantFalseWordTypesCount,
  SpecConstantWordTypesCount,
  SpecConstantCompositeWordTypesCount,
  VariableWordTypesCount,
  VariableArrayWordTypesCount,
  FunctionWordTypesCount,
  FunctionParameterWordTypesCount,
  FunctionEndWordTypesCount,
  FunctionCallWordTypesCount,
  ExtInstWordTypesCount,
  UndefWordTypesCount,
  LoadWordTypesCount,
  StoreWordTypesCount,
  PhiWordTypesCount,
  DecorationGroupWordTypesCount,
  DecorateWordTypesCount,
  MemberDecorateWordTypesCount,
  GroupDecorateWordTypesCount,
  GroupMemberDecorateWordTypesCount,
  NameWordTypesCount,
  MemberNameWordTypesCount,
  StringWordTypesCount,
  LineWordTypesCount,
  VectorExtractDynamicWordTypesCount,
  VectorInsertDynamicWordTypesCount,
  VectorShuffleWordTypesCount,
  CompositeConstructWordTypesCount,
  CompositeExtractWordTypesCount,
  CompositeInsertWordTypesCount,
  CopyObjectWordTypesCount,
  CopyMemoryWordTypesCount,
  CopyMemorySizedWordTypesCount,
  SamplerWordTypesCount,
  TextureSampleWordTypesCount,
  TextureSampleDrefWordTypesCount,
  TextureSampleLodWordTypesCount,
  TextureSampleProjWordTypesCount,
  TextureSampleGradWordTypesCount,
  TextureSampleOffsetWordTypesCount,
  TextureSampleProjLodWordTypesCount,
  TextureSampleProjGradWordTypesCount,
  TextureSampleLodOffsetWordTypesCount,
  TextureSampleProjOffsetWordTypesCount,
  TextureSampleGradOffsetWordTypesCount,
  TextureSampleProjLodOffsetWordTypesCount,
  TextureSampleProjGradOffsetWordTypesCount,
  TextureFetchTexelLodWordTypesCount,
  TextureFetchTexelOffsetWordTypesCount,
  TextureFetchSampleWordTypesCount,
  TextureFetchTexelWordTypesCount,
  TextureGatherWordTypesCount,
  TextureGatherOffsetWordTypesCount,
  TextureGatherOffsetsWordTypesCount,
  TextureQuerySizeLodWordTypesCount,
  TextureQuerySizeWordTypesCount,
  TextureQueryLodWordTypesCount,
  TextureQueryLevelsWordTypesCount,
  TextureQuerySamplesWordTypesCount,
  AccessChainWordTypesCount,
  InBoundsAccessChainWordTypesCount,
  SNegateWordTypesCount,
  FNegateWordTypesCount,
  NotWordTypesCount,
  AnyWordTypesCount,
  AllWordTypesCount,
  ConvertFToUWordTypesCount,
  ConvertFToSWordTypesCount,
  ConvertSToFWordTypesCount,
  ConvertUToFWordTypesCount,
  UConvertWordTypesCount,
  SConvertWordTypesCount,
  FConvertWordTypesCount,
  ConvertPtrToUWordTypesCount,
  ConvertUToPtrWordTypesCount,
  PtrCastToGenericWordTypesCount,
  GenericCastToPtrWordTypesCount,
  BitcastWordTypesCount,
  TransposeWordTypesCount,
  IsNanWordTypesCount,
  IsInfWordTypesCount,
  IsFiniteWordTypesCount,
  IsNormalWordTypesCount,
  SignBitSetWordTypesCount,
  LessOrGreaterWordTypesCount,
  OrderedWordTypesCount,
  UnorderedWordTypesCount,
  ArrayLengthWordTypesCount,
  IAddWordTypesCount,
  FAddWordTypesCount,
  ISubWordTypesCount,
  FSubWordTypesCount,
  IMulWordTypesCount,
  FMulWordTypesCount,
  UDivWordTypesCount,
  SDivWordTypesCount,
  FDivWordTypesCount,
  UModWordTypesCount,
  SRemWordTypesCount,
  SModWordTypesCount,
  FRemWordTypesCount,
  FModWordTypesCount,
  VectorTimesScalarWordTypesCount,
  MatrixTimesScalarWordTypesCount,
  VectorTimesMatrixWordTypesCount,
  MatrixTimesVectorWordTypesCount,
  MatrixTimesMatrixWordTypesCount,
  OuterProductWordTypesCount,
  DotWordTypesCount,
  ShiftRightLogicalWordTypesCount,
  ShiftRightArithmeticWordTypesCount,
  ShiftLeftLogicalWordTypesCount,
  LogicalOrWordTypesCount,
  LogicalXorWordTypesCount,
  LogicalAndWordTypesCount,
  BitwiseOrWordTypesCount,
  BitwiseXorWordTypesCount,
  BitwiseAndWordTypesCount,
  SelectWordTypesCount,
  IEqualWordTypesCount,
  FOrdEqualWordTypesCount,
  FUnordEqualWordTypesCount,
  INotEqualWordTypesCount,
  FOrdNotEqualWordTypesCount,
  FUnordNotEqualWordTypesCount,
  ULessThanWordTypesCount,
  SLessThanWordTypesCount,
  FOrdLessThanWordTypesCount,
  FUnordLessThanWordTypesCount,
  UGreaterThanWordTypesCount,
  SGreaterThanWordTypesCount,
  FOrdGreaterThanWordTypesCount,
  FUnordGreaterThanWordTypesCount,
  ULessThanEqualWordTypesCount,
  SLessThanEqualWordTypesCount,
  FOrdLessThanEqualWordTypesCount,
  FUnordLessThanEqualWordTypesCount,
  UGreaterThanEqualWordTypesCount,
  SGreaterThanEqualWordTypesCount,
  FOrdGreaterThanEqualWordTypesCount,
  FUnordGreaterThanEqualWordTypesCount,
  DPdxWordTypesCount,
  DPdyWordTypesCount,
  FwidthWordTypesCount,
  DPdxFineWordTypesCount,
  DPdyFineWordTypesCount,
  FwidthFineWordTypesCount,
  DPdxCoarseWordTypesCount,
  DPdyCoarseWordTypesCount,
  FwidthCoarseWordTypesCount,
  EmitVertexWordTypesCount,
  EndPrimitiveWordTypesCount,
  EmitStreamVertexWordTypesCount,
  EndStreamPrimitiveWordTypesCount,
  ControlBarrierWordTypesCount,
  MemoryBarrierWordTypesCount,
  ImagePointerWordTypesCount,
  AtomicInitWordTypesCount,
  AtomicLoadWordTypesCount,
  AtomicStoreWordTypesCount,
  AtomicExchangeWordTypesCount,
  AtomicCompareExchangeWordTypesCount,
  AtomicCompareExchangeWeakWordTypesCount,
  AtomicIIncrementWordTypesCount,
  AtomicIDecrementWordTypesCount,
  AtomicIAddWordTypesCount,
  AtomicISubWordTypesCount,
  AtomicUMinWordTypesCount,
  AtomicUMaxWordTypesCount,
  AtomicAndWordTypesCount,
  AtomicOrWordTypesCount,
  AtomicXorWordTypesCount,
  LoopMergeWordTypesCount,
  SelectionMergeWordTypesCount,
  LabelWordTypesCount,
  BranchWordTypesCount,
  BranchConditionalWordTypesCount,
  SwitchWordTypesCount,
  KillWordTypesCount,
  ReturnWordTypesCount,
  ReturnValueWordTypesCount,
  UnreachableWordTypesCount,
  LifetimeStartWordTypesCount,
  LifetimeStopWordTypesCount,
  CompileFlagWordTypesCount,
  AsyncGroupCopyWordTypesCount,
  WaitGroupEventsWordTypesCount,
  GroupAllWordTypesCount,
  GroupAnyWordTypesCount,
  GroupBroadcastWordTypesCount,
  GroupIAddWordTypesCount,
  GroupFAddWordTypesCount,
  GroupFMinWordTypesCount,
  GroupUMinWordTypesCount,
  GroupSMinWordTypesCount,
  GroupFMaxWordTypesCount,
  GroupUMaxWordTypesCount,
  GroupSMaxWordTypesCount,
  GenericCastToPtrExplicitWordTypesCount,
  GenericPtrMemSemanticsWordTypesCount,
  ReadPipeWordTypesCount,
  WritePipeWordTypesCount,
  ReservedReadPipeWordTypesCount,
  ReservedWritePipeWordTypesCount,
  ReserveReadPipePacketsWordTypesCount,
  ReserveWritePipePacketsWordTypesCount,
  CommitReadPipeWordTypesCount,
  CommitWritePipeWordTypesCount,
  IsValidReserveIdWordTypesCount,
  GetNumPipePacketsWordTypesCount,
  GetMaxPipePacketsWordTypesCount,
  GroupReserveReadPipePacketsWordTypesCount,
  GroupReserveWritePipePacketsWordTypesCount,
  GroupCommitReadPipeWordTypesCount,
  GroupCommitWritePipeWordTypesCount,
  EnqueueMarkerWordTypesCount,
  EnqueueKernelWordTypesCount,
  GetKernelNDrangeSubGroupCountWordTypesCount,
  GetKernelNDrangeMaxSubGroupSizeWordTypesCount,
  GetKernelWorkGroupSizeWordTypesCount,
  GetKernelPreferredWorkGroupSizeMultipleWordTypesCount,
  RetainEventWordTypesCount,
  ReleaseEventWordTypesCount,
  CreateUserEventWordTypesCount,
  IsValidEventWordTypesCount,
  SetUserEventStatusWordTypesCount,
  CaptureEventProfilingInfoWordTypesCount,
  GetDefaultQueueWordTypesCount,
  BuildNDRangeWordTypesCount,
  SatConvertSToUWordTypesCount,
  SatConvertUToSWordTypesCount,
  AtomicIMinWordTypesCount,
  AtomicIMaxWordTypesCount,
};