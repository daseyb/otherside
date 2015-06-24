#pragma once
#include "Khronos\spirv.h"
#include <string>

using namespace spv;

enum WordType {
  TSourceLanguage,
  TExecutionModel,
  TAddressingModel,
  TMemoryModel,
  TExecutionMode,
  TStorageClass,
  TDim,
  TSamplerAddressingMode,
  TSamplerFilterMode,
  TFPFastMathModeShift,
  TFPFastMathModeMask,
  TFPRoundingMode,
  TLinkageType,
  TAccessQualifier,
  TFunctionParameterAttribute,
  TDecoration,
  TBuiltIn,
  TSelectionControlShift,
  TSelectionControlMask,
  TLoopControlShift,
  TLoopControlMask,
  TFunctionControlShift,
  TFunctionControlMask,
  TMemorySemanticsShift,
  TMemorySemanticsMask,
  TMemoryAccessShift,
  TMemoryAccessMask,
  TExecutionScope,
  TGroupOperation,
  TKernelEnqueueFlags,
  TKernelProfilingInfoShift,
  TKernelProfilingInfoMask,
  TOp,
  TId,
  TValue,
  TChar
};

static std::string SourceLanguageStrings[] {
  "Unknown",
  "ESSL",
  "GLSL",
  "OpenCL",
};

static std::string ExecutionModelStrings[] {
  "Vertex",
  "TessellationControl",
  "TessellationEvaluation",
  "Geometry",
  "Fragment",
  "GLCompute",
  "Kernel",
};

static std::string AddressingModelStrings[] {
  "Logical",
  "Physical32",
  "Physical64",
};

static std::string MemoryModelStrings[] {
  "Simple",
  "GLSL450",
  "OpenCL12",
  "OpenCL20",
  "OpenCL21",
};

static std::string ExecutionModeStrings[] {
  "Invocations",
  "SpacingEqual",
  "SpacingFractionalEven",
  "SpacingFractionalOdd",
  "VertexOrderCw",
  "VertexOrderCcw",
  "PixelCenterInteger",
  "OriginUpperLeft",
  "EarlyFragmentTests",
  "PointMode",
  "Xfb",
  "DepthReplacing",
  "DepthAny",
  "DepthGreater",
  "DepthLess",
  "DepthUnchanged",
  "LocalSize",
  "LocalSizeHint",
  "InputPoints",
  "InputLines",
  "InputLinesAdjacency",
  "InputTriangles",
  "InputTrianglesAdjacency",
  "InputQuads",
  "InputIsolines",
  "OutputVertices",
  "OutputPoints",
  "OutputLineStrip",
  "OutputTriangleStrip",
  "VecTypeHint",
  "ContractionOff",
};

static std::string StorageClassStrings[] {
  "UniformConstant",
  "Input",
  "Uniform",
  "Output",
  "WorkgroupLocal",
  "WorkgroupGlobal",
  "PrivateGlobal",
  "Function",
  "Generic",
  "Private",
  "AtomicCounter",
};

static std::string DimStrings[] {
  "1D",
  "2D",
  "3D",
  "Cube",
  "Rect",
  "Buffer",
};

static std::string SamplerAddressingModeStrings[] {
  "None",
  "ClampToEdge",
  "Clamp",
  "Repeat",
  "RepeatMirrored",
};

static std::string SamplerFilterModeStrings[] {
  "Nearest",
  "Linear",
};

static std::string FPFastMathModeShiftStrings[] {
  "NotNaNShift",
  "NotInfShift",
  "NSZShift",
  "AllowRecipShift",
  "FastShift",
};

static std::string FPFastMathModeMaskStrings[] {
  "MaskNone",
  "NotNaNMask",
  "NotInfMask",
  "NSZMask",
  "AllowRecipMask",
  "FastMask",
};

static std::string FPRoundingModeStrings[] {
  "RTE",
  "RTZ",
  "RTP",
  "RTN",
};

static std::string LinkageTypeStrings[] {
  "Export",
  "Import",
};

static std::string AccessQualifierStrings[] {
  "ReadOnly",
  "WriteOnly",
  "ReadWrite",
};

static std::string FunctionParameterAttributeStrings[] {
  "Zext",
  "Sext",
  "ByVal",
  "Sret",
  "NoAlias",
  "NoCapture",
  "SVM",
  "NoWrite",
  "NoReadWrite",
};

static std::string DecorationStrings[] {
  "PrecisionLow",
  "PrecisionMedium",
  "PrecisionHigh",
  "Block",
  "BufferBlock",
  "RowMajor",
  "ColMajor",
  "GLSLShared",
  "GLSLStd140",
  "GLSLStd430",
  "GLSLPacked",
  "Smooth",
  "Noperspective",
  "Flat",
  "Patch",
  "Centroid",
  "Sample",
  "Invariant",
  "Restrict",
  "Aliased",
  "Volatile",
  "Constant",
  "Coherent",
  "Nonwritable",
  "Nonreadable",
  "Uniform",
  "NoStaticUse",
  "CPacked",
  "SaturatedConversion",
  "Stream",
  "Location",
  "Component",
  "Index",
  "Binding",
  "DescriptorSet",
  "Offset",
  "Alignment",
  "XfbBuffer",
  "Stride",
  "BuiltIn",
  "FuncParamAttr",
  "FPRoundingMode",
  "FPFastMathMode",
  "LinkageAttributes",
  "SpecId",
};

static std::string BuiltInStrings[] {
  "Position",
  "PointSize",
  "ClipVertex",
  "ClipDistance",
  "CullDistance",
  "VertexId",
  "InstanceId",
  "PrimitiveId",
  "InvocationId",
  "Layer",
  "ViewportIndex",
  "TessLevelOuter",
  "TessLevelInner",
  "TessCoord",
  "PatchVertices",
  "FragCoord",
  "PointCoord",
  "FrontFacing",
  "SampleId",
  "SamplePosition",
  "SampleMask",
  "FragColor",
  "FragDepth",
  "HelperInvocation",
  "NumWorkgroups",
  "WorkgroupSize",
  "WorkgroupId",
  "LocalInvocationId",
  "GlobalInvocationId",
  "LocalInvocationIndex",
  "WorkDim",
  "GlobalSize",
  "EnqueuedWorkgroupSize",
  "GlobalOffset",
  "GlobalLinearId",
  "WorkgroupLinearId",
  "SubgroupSize",
  "SubgroupMaxSize",
  "NumSubgroups",
  "NumEnqueuedSubgroups",
  "SubgroupId",
  "SubgroupLocalInvocationId",
};

static std::string SelectionControlShiftStrings[] {
  "FlattenShift",
  "DontFlattenShift",
};

static std::string SelectionControlMaskStrings[] {
  "MaskNone",
  "FlattenMask",
  "DontFlattenMask",
};

static std::string LoopControlShiftStrings[] {
  "UnrollShift",
  "DontUnrollShift",
};

static std::string LoopControlMaskStrings[] {
  "MaskNone",
  "UnrollMask",
  "DontUnrollMask",
};

static std::string FunctionControlShiftStrings[] {
  "InlineShift",
  "DontInlineShift",
  "PureShift",
  "ConstShift",
};

static std::string FunctionControlMaskStrings[] {
  "MaskNone",
  "InlineMask",
  "DontInlineMask",
  "PureMask",
  "ConstMask",
};

static std::string MemorySemanticsShiftStrings[] {
  "RelaxedShift",
  "SequentiallyConsistentShift",
  "AcquireShift",
  "ReleaseShift",
  "UniformMemoryShift",
  "SubgroupMemoryShift",
  "WorkgroupLocalMemoryShift",
  "WorkgroupGlobalMemoryShift",
  "AtomicCounterMemoryShift",
  "ImageMemoryShift",
};

static std::string MemorySemanticsMaskStrings[] {
  "MaskNone",
  "RelaxedMask",
  "SequentiallyConsistentMask",
  "AcquireMask",
  "ReleaseMask",
  "UniformMemoryMask",
  "SubgroupMemoryMask",
  "WorkgroupLocalMemoryMask",
  "WorkgroupGlobalMemoryMask",
  "AtomicCounterMemoryMask",
  "ImageMemoryMask",
};

static std::string MemoryAccessShiftStrings[] {
  "VolatileShift",
  "AlignedShift",
};

static std::string MemoryAccessMaskStrings[] {
  "MaskNone",
  "VolatileMask",
  "AlignedMask",
};

static std::string ExecutionScopeStrings[] {
  "CrossDevice",
  "Device",
  "Workgroup",
  "Subgroup",
};

static std::string GroupOperationStrings[] {
  "Reduce",
  "InclusiveScan",
  "ExclusiveScan",
};

static std::string KernelEnqueueFlagsStrings[] {
  "NoWait",
  "WaitKernel",
  "WaitWorkGroup",
};

static std::string KernelProfilingInfoShiftStrings[] {
  "CmdExecTimeShift",
};

static std::string KernelProfilingInfoMaskStrings[] {
  "MaskNone",
  "CmdExecTimeMask",
};

static std::string OpStrings[] = {
  "Nop",
  "Source",
  "SourceExtension",
  "Extension",
  "ExtInstImport",
  "MemoryModel",
  "EntryPoint",
  "ExecutionMode",
  "TypeVoid",
  "TypeBool",
  "TypeInt",
  "TypeFloat",
  "TypeVector",
  "TypeMatrix",
  "TypeSampler",
  "TypeFilter",
  "TypeArray",
  "TypeRuntimeArray",
  "TypeStruct",
  "TypeOpaque",
  "TypePointer",
  "TypeFunction",
  "TypeEvent",
  "TypeDeviceEvent",
  "TypeReserveId",
  "TypeQueue",
  "TypePipe",
  "ConstantTrue",
  "ConstantFalse",
  "Constant",
  "ConstantComposite",
  "ConstantSampler",
  "ConstantNullPointer",
  "ConstantNullObject",
  "SpecConstantTrue",
  "SpecConstantFalse",
  "SpecConstant",
  "SpecConstantComposite",
  "Variable",
  "VariableArray",
  "Function",
  "FunctionParameter",
  "FunctionEnd",
  "FunctionCall",
  "ExtInst",
  "Undef",
  "Load",
  "Store",
  "Phi",
  "DecorationGroup",
  "Decorate",
  "MemberDecorate",
  "GroupDecorate",
  "GroupMemberDecorate",
  "Name",
  "MemberName",
  "String",
  "Line",
  "VectorExtractDynamic",
  "VectorInsertDynamic",
  "VectorShuffle",
  "CompositeConstruct",
  "CompositeExtract",
  "CompositeInsert",
  "CopyObject",
  "CopyMemory",
  "CopyMemorySized",
  "Sampler",
  "TextureSample",
  "TextureSampleDref",
  "TextureSampleLod",
  "TextureSampleProj",
  "TextureSampleGrad",
  "TextureSampleOffset",
  "TextureSampleProjLod",
  "TextureSampleProjGrad",
  "TextureSampleLodOffset",
  "TextureSampleProjOffset",
  "TextureSampleGradOffset",
  "TextureSampleProjLodOffset",
  "TextureSampleProjGradOffset",
  "TextureFetchTexelLod",
  "TextureFetchTexelOffset",
  "TextureFetchSample",
  "TextureFetchTexel",
  "TextureGather",
  "TextureGatherOffset",
  "TextureGatherOffsets",
  "TextureQuerySizeLod",
  "TextureQuerySize",
  "TextureQueryLod",
  "TextureQueryLevels",
  "TextureQuerySamples",
  "AccessChain",
  "InBoundsAccessChain",
  "SNegate",
  "FNegate",
  "Not",
  "Any",
  "All",
  "ConvertFToU",
  "ConvertFToS",
  "ConvertSToF",
  "ConvertUToF",
  "UConvert",
  "SConvert",
  "FConvert",
  "ConvertPtrToU",
  "ConvertUToPtr",
  "PtrCastToGeneric",
  "GenericCastToPtr",
  "Bitcast",
  "Transpose",
  "IsNan",
  "IsInf",
  "IsFinite",
  "IsNormal",
  "SignBitSet",
  "LessOrGreater",
  "Ordered",
  "Unordered",
  "ArrayLength",
  "IAdd",
  "FAdd",
  "ISub",
  "FSub",
  "IMul",
  "FMul",
  "UDiv",
  "SDiv",
  "FDiv",
  "UMod",
  "SRem",
  "SMod",
  "FRem",
  "FMod",
  "VectorTimesScalar",
  "MatrixTimesScalar",
  "VectorTimesMatrix",
  "MatrixTimesVector",
  "MatrixTimesMatrix",
  "OuterProduct",
  "Dot",
  "ShiftRightLogical",
  "ShiftRightArithmetic",
  "ShiftLeftLogical",
  "LogicalOr",
  "LogicalXor",
  "LogicalAnd",
  "BitwiseOr",
  "BitwiseXor",
  "BitwiseAnd",
  "Select",
  "IEqual",
  "FOrdEqual",
  "FUnordEqual",
  "INotEqual",
  "FOrdNotEqual",
  "FUnordNotEqual",
  "ULessThan",
  "SLessThan",
  "FOrdLessThan",
  "FUnordLessThan",
  "UGreaterThan",
  "SGreaterThan",
  "FOrdGreaterThan",
  "FUnordGreaterThan",
  "ULessThanEqual",
  "SLessThanEqual",
  "FOrdLessThanEqual",
  "FUnordLessThanEqual",
  "UGreaterThanEqual",
  "SGreaterThanEqual",
  "FOrdGreaterThanEqual",
  "FUnordGreaterThanEqual",
  "DPdx",
  "DPdy",
  "Fwidth",
  "DPdxFine",
  "DPdyFine",
  "FwidthFine",
  "DPdxCoarse",
  "DPdyCoarse",
  "FwidthCoarse",
  "EmitVertex",
  "EndPrimitive",
  "EmitStreamVertex",
  "EndStreamPrimitive",
  "ControlBarrier",
  "MemoryBarrier",
  "ImagePointer",
  "AtomicInit",
  "AtomicLoad",
  "AtomicStore",
  "AtomicExchange",
  "AtomicCompareExchange",
  "AtomicCompareExchangeWeak",
  "AtomicIIncrement",
  "AtomicIDecrement",
  "AtomicIAdd",
  "AtomicISub",
  "AtomicUMin",
  "AtomicUMax",
  "AtomicAnd",
  "AtomicOr",
  "AtomicXor",
  "LoopMerge",
  "SelectionMerge",
  "Label",
  "Branch",
  "BranchConditional",
  "Switch",
  "Kill",
  "Return",
  "ReturnValue",
  "Unreachable",
  "LifetimeStart",
  "LifetimeStop",
  "CompileFlag",
  "AsyncGroupCopy",
  "WaitGroupEvents",
  "GroupAll",
  "GroupAny",
  "GroupBroadcast",
  "GroupIAdd",
  "GroupFAdd",
  "GroupFMin",
  "GroupUMin",
  "GroupSMin",
  "GroupFMax",
  "GroupUMax",
  "GroupSMax",
  "GenericCastToPtrExplicit",
  "GenericPtrMemSemantics",
  "ReadPipe",
  "WritePipe",
  "ReservedReadPipe",
  "ReservedWritePipe",
  "ReserveReadPipePackets",
  "ReserveWritePipePackets",
  "CommitReadPipe",
  "CommitWritePipe",
  "IsValidReserveId",
  "GetNumPipePackets",
  "GetMaxPipePackets",
  "GroupReserveReadPipePackets",
  "GroupReserveWritePipePackets",
  "GroupCommitReadPipe",
  "GroupCommitWritePipe",
  "EnqueueMarker",
  "EnqueueKernel",
  "GetKernelNDrangeSubGroupCount",
  "GetKernelNDrangeMaxSubGroupSize",
  "GetKernelWorkGroupSize",
  "GetKernelPreferredWorkGroupSizeMultiple",
  "RetainEvent",
  "ReleaseEvent",
  "CreateUserEvent",
  "IsValidEvent",
  "SetUserEventStatus",
  "CaptureEventProfilingInfo",
  "GetDefaultQueue",
  "BuildNDRange",
  "SatConvertSToU",
  "SatConvertUToS",
  "AtomicIMin",
  "AtomicIMax",
};

static void* LUTPointers[]{
  &SourceLanguageStrings,
  &ExecutionModelStrings,
  &AddressingModelStrings,
  &MemoryModelStrings,
  &ExecutionModeStrings,
  &StorageClassStrings,
  &DimStrings,
  &SamplerAddressingModeStrings,
  &SamplerFilterModeStrings,
  &FPFastMathModeShiftStrings,
  &FPFastMathModeMaskStrings,
  &FPRoundingModeStrings,
  &LinkageTypeStrings,
  &AccessQualifierStrings,
  &FunctionParameterAttributeStrings,
  &DecorationStrings,
  &BuiltInStrings,
  &SelectionControlShiftStrings,
  &SelectionControlMaskStrings,
  &LoopControlShiftStrings,
  &LoopControlMaskStrings,
  &FunctionControlShiftStrings,
  &FunctionControlMaskStrings,
  &MemorySemanticsShiftStrings,
  &MemorySemanticsMaskStrings,
  &MemoryAccessShiftStrings,
  &MemoryAccessMaskStrings,
  &ExecutionScopeStrings,
  &GroupOperationStrings,
  &KernelEnqueueFlagsStrings,
  &KernelProfilingInfoShiftStrings,
  &KernelProfilingInfoMaskStrings,
  &OpStrings,
};

static WordType NOPWordTypes[] {
  WordType::TOp
};
static uint32 NOPWordTypesCount = 1;

static WordType SourceWordTypes[] {
  WordType::TOp,
  WordType::TSourceLanguage,
  WordType::TValue
};
static uint32 SourceWordTypesCount = 3;

static WordType SourceExtensionWordTypes[] {
  WordType::TOp,
  WordType::TChar
};
static uint32 SourceExtensionWordTypesCount = 2;

static WordType ExtensionWordTypes[] {
  WordType::TOp,
  WordType::TChar
};
static uint32 ExtensionWordTypesCount = 2;

static WordType ExtInstImportWordTypes[] {
  WordType::TOp,
  WordType::TId,
  WordType::TChar
};
static uint32 ExtInstImportWordTypesCount = 3;

static WordType MemoryModelWordTypes[]{
  WordType::TOp,
  WordType::TAddressingModel,
  WordType::TMemoryModel
};
static uint32 MemoryModelWordTypesCount = 3;

static WordType EntryPointWordTypes[]{
  WordType::TOp,
  WordType::TExecutionModel,
  WordType::TId
};
static uint32 EntryPointWordTypesCount = 3;

static void* LUTOpWordTypes[] {
  &NOPWordTypes,
  &SourceWordTypes,
  &SourceExtensionWordTypes,
  &ExtensionWordTypes,
  &ExtInstImportWordTypes,
  &MemoryModelWordTypes,
  &EntryPointWordTypes,
};

static uint32 LUTOpWordTypesCount[] {
  NOPWordTypesCount,
  SourceWordTypesCount,
  SourceExtensionWordTypesCount,
  ExtensionWordTypesCount,
  ExtInstImportWordTypesCount,
  MemoryModelWordTypesCount,
  EntryPointWordTypesCount,
};