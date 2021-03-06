#pragma once
#include "Khronos/spirv.h"
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
  TImageFormat,
  TImageChannelOrder,
  TImageChannelDataType,
  TImageOperandsShift,
  TImageOperandsMask,
  TFPFastMathModeShift,
  TFPFastMathModeMask,
  TFPRoundingMode,
  TLinkageType,
  TAccessQualifier,
  TFunctionParameterAttribute,
  TDecoration,
  TBuiltIn,
  TSelectionControl,
  TSelectionControlShift,
  TSelectionControlMask,
  TLoopControl,
  TLoopControlShift,
  TLoopControlMask,
  TFunctionControl,
  TFunctionControlShift,
  TFunctionControlMask,
  TMemorySemantics,
  TMemorySemanticsShift,
  TMemorySemanticsMask,
  TMemoryAccess,
  TMemoryAccessShift,
  TMemoryAccessMask,
  TScope,
  TGroupOperation,
  TKernelEnqueueFlags,
  TKernelProfilingInfo,
  TKernelProfilingInfoShift,
  TKernelProfilingInfoMask,
  TCapability,
  TOp,
  TId,
  TLiteralNumber,
  TLiteralString,
  TIdList,
  TLiteralNumberList
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
  "OpenCL",
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
  "OriginLowerLeft",
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
  "AtomicCounter",
  "Image",
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

static std::string ImageFormatStrings[] {
  "Unknown",
  "Rgba32f",
  "Rgba16f",
  "R32f",
  "Rgba8",
  "Rgba8Snorm",
  "Rg32f",
  "Rg16f",
  "R11fG11fB10f",
  "R16f",
  "Rgba16",
  "Rgb10A2",
  "Rg16",
  "Rg8",
  "R16",
  "R8",
  "Rgba16Snorm",
  "Rg16Snorm",
  "Rg8Snorm",
  "R16Snorm",
  "R8Snorm",
  "Rgba32i",
  "Rgba16i",
  "Rgba8i",
  "R32i",
  "Rg32i",
  "Rg16i",
  "Rg8i",
  "R16i",
  "R8i",
  "Rgba32ui",
  "Rgba16ui",
  "Rgba8ui",
  "R32ui",
  "Rgb10a2ui",
  "Rg32ui",
  "Rg16ui",
  "Rg8ui",
  "R16ui",
  "R8ui",
};

static std::string ImageChannelOrderStrings[] {
  "R",
  "A",
  "RG",
  "RA",
  "RGB",
  "RGBA",
  "BGRA",
  "ARGB",
  "Intensity",
  "Luminance",
  "Rx",
  "RGx",
  "RGBx",
  "Depth",
  "DepthStencil",
  "sRGB",
  "sRGBx",
  "sRGBA",
  "sBGRA",
};

static std::string ImageChannelDataTypeStrings[] {
  "SnormInt8",
  "SnormInt16",
  "UnormInt8",
  "UnormInt16",
  "UnormShort565",
  "UnormShort555",
  "UnormInt101010",
  "SignedInt8",
  "SignedInt16",
  "SignedInt32",
  "UnsignedInt8",
  "UnsignedInt16",
  "UnsignedInt32",
  "HalfFloat",
  "Float",
  "UnormInt24",
};

static std::string ImageOperandsShiftStrings[] {
  "Bias",
  "Lod",
  "Grad",
  "ConstOffset",
  "Offset",
  "ConstOffsets",
  "Sample",
};

static std::string ImageOperandsMaskStrings[] {
  "MaskNone",
  "Bias",
  "Lod",
  "Grad",
  "ConstOffset",
  "Offset",
  "ConstOffsets",
  "Sample",
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
  "RelaxedPrecision",
  "SpecId",
  "Block",
  "BufferBlock",
  "RowMajor",
  "ColMajor",
  "ArrayStride",
  "MatrixStride",
  "GLSLShared",
  "GLSLPacked",
  "CPacked",
  "BuiltIn",
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
  "SaturatedConversion",
  "Stream",
  "Location",
  "Component",
  "Index",
  "Binding",
  "DescriptorSet",
  "Offset",
  "XfbBuffer",
  "XfbStride",
  "FuncParamAttr",
  "FPRoundingMode",
  "FPFastMathMode",
  "LinkageAttributes",
};

static std::string BuiltInStrings[] {
  "Position",
  "PointSize",
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

static std::string SelectionControlStrings[]{
  "Flatten",
  "DontFlatten",
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

static std::string LoopControlStrings[]{
  "Unroll",
  "DontUnroll",
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

static std::string FunctionControlStrings[]{
  "Inline",
  "DontInline",
  "Pure",
  "Const",
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

static std::string MemorySemanticsStrings[]{
  "Relaxed",
  "SequentiallyConsistent",
  "Acquire",
  "Release",
  "UniformMemory",
  "SubgroupMemory",
  "WorkgroupLocalMemory",
  "WorkgroupGlobalMemory",
  "AtomicCounterMemory",
  "ImageMemory",
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

static std::string MemoryAccessStrings[]{
  "Volatile",
  "Aligned",
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

static std::string ScopeStrings[] {
  "CrossDevice",
  "Device",
  "Workgroup",
  "Subgroup",
  "Invocation",
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

static std::string KernelProfilingInfoStrings[]{
  "CmdExecTime",
};

static std::string KernelProfilingInfoShiftStrings[] {
  "CmdExecTimeShift",
};

static std::string KernelProfilingInfoMaskStrings[] {
  "MaskNone",
  "CmdExecTimeMask",
};

static std::string CapabilityStrings[] {
  "Matrix",
  "Shader",
  "Geometry",
  "Tessellation",
  "Addresses",
  "Linkage",
  "Kernel",
  "Vector16",
  "Float16Buffer",
  "Float16",
  "Float64",
  "Int64",
  "Int64Atomics",
  "ImageBasic",
  "ImageReadWrite",
  "ImageMipmap",
  "ImageSRGBWrite",
  "Pipes",
  "Groups",
  "DeviceEnqueue",
  "LiteralSampler",
  "AtomicStorage",
  "Int16",
  "TessellationPointSize",
  "GeometryPointSize",
  "ImageGatherExtended",
  "StorageImageExtendedFormats",
  "StorageImageMultisample",
  "UniformBufferArrayDynamicIndexing",
  "SampledImageArrayDynamicIndexing",
  "StorageBufferArrayDynamicIndexing",
  "StorageImageArrayDynamicIndexing",
  "ClipDistance",
  "CullDistance",
  "ImageCubeArray",
  "SampleRateShading",
};

static std::string OpStrings[(int)spv::Op::COUNT+1]{
  "Nop",
  "Undef",
  "",
  "Source",
  "SourceExtension",
  "Name",
  "MemberName",
  "String",
  "Line",
  "",
  "Extension",
  "ExtInstImport",
  "ExtInst",
  "",
  "MemoryModel",
  "EntryPoint",
  "ExecutionMode",
  "Capability",
  "",
  "TypeVoid",
  "TypeBool",
  "TypeInt",
  "TypeFloat",
  "TypeVector",
  "TypeMatrix",
  "TypeImage",
  "TypeSampler",
  "TypeSampledImage",
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
  "",
  "",
  "ConstantTrue",
  "ConstantFalse",
  "Constant",
  "ConstantComposite",
  "ConstantSampler",
  "ConstantNull",
  "",
  "SpecConstantTrue",
  "SpecConstantFalse",
  "SpecConstant",
  "SpecConstantComposite",
  "SpecConstantOp",
  "",
  "Function",
  "FunctionParameter",
  "FunctionEnd",
  "FunctionCall",
  "",
  "Variable",
  "ImageTexelPointer",
  "Load",
  "Store",
  "CopyMemory",
  "CopyMemorySized",
  "AccessChain",
  "InBoundsAccessChain",
  "PtrAccessChain",
  "ArrayLength",
  "GenericPtrMemSemantics",
  "",
  "Decorate",
  "MemberDecorate",
  "DecorationGroup",
  "GroupDecorate",
  "GroupMemberDecorate",
  "",
  "VectorExtractDynamic",
  "VectorInsertDynamic",
  "VectorShuffle",
  "CompositeConstruct",
  "CompositeExtract",
  "CompositeInsert",
  "CopyObject",
  "Transpose",
  "",
  "SampledImage",
  "ImageSampleImplicitLod",
  "ImageSampleExplicitLod",
  "ImageSampleDrefImplicitLod",
  "ImageSampleDrefExplicitLod",
  "ImageSampleProjImplicitLod",
  "ImageSampleProjExplicitLod",
  "ImageSampleProjDrefImplicitLod",
  "ImageSampleProjDrefExplicitLod",
  "ImageFetch",
  "ImageGather",
  "ImageDrefGather",
  "ImageRead",
  "ImageWrite",
  "ImageQueryDim",
  "ImageQueryFormat",
  "ImageQueryOrder",
  "ImageQuerySizeLod",
  "ImageQuerySize",
  "ImageQueryLod",
  "ImageQueryLevels",
  "ImageQuerySamples",
  "",
  "ConvertFToU",
  "ConvertFToS",
  "ConvertSToF",
  "ConvertUToF",
  "UConvert",
  "SConvert",
  "FConvert",
  "QuantizeToF16",
  "ConvertPtrToU",
  "SatConvertSToU",
  "SatConvertUToS",
  "ConvertUToPtr",
  "PtrCastToGeneric",
  "GenericCastToPtr",
  "GenericCastToPtrExplicit",
  "Bitcast",
  "",
  "SNegate",
  "FNegate",
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
  "IAddCarry",
  "ISubBorrow",
  "IMulExtended",
  "",
  "",
  "Any",
  "All",
  "IsNan",
  "IsInf",
  "IsFinite",
  "IsNormal",
  "SignBitSet",
  "LessOrGreater",
  "Ordered",
  "Unordered",
  "LogicalEqual",
  "LogicalNotEqual",
  "LogicalOr",
  "LogicalAnd",
  "LogicalNot",
  "Select",
  "IEqual",
  "INotEqual",
  "UGreaterThan",
  "SGreaterThan",
  "UGreaterThanEqual",
  "SGreaterThanEqual",
  "ULessThan",
  "SLessThan",
  "ULessThanEqual",
  "SLessThanEqual",
  "FOrdEqual",
  "FUnordEqual",
  "FOrdNotEqual",
  "FUnordNotEqual",
  "FOrdLessThan",
  "FUnordLessThan",
  "FOrdGreaterThan",
  "FUnordGreaterThan",
  "FOrdLessThanEqual",
  "FUnordLessThanEqual",
  "FOrdGreaterThanEqual",
  "FUnordGreaterThanEqual",
  "",
  "",
  "ShiftRightLogical",
  "ShiftRightArithmetic",
  "ShiftLeftLogical",
  "BitwiseOr",
  "BitwiseXor",
  "BitwiseAnd",
  "Not",
  "BitFieldInsert",
  "BitFieldSExtract",
  "BitFieldUExtract",
  "BitReverse",
  "BitCount",
  "",
  "DPdx",
  "DPdy",
  "Fwidth",
  "DPdxFine",
  "DPdyFine",
  "FwidthFine",
  "DPdxCoarse",
  "DPdyCoarse",
  "FwidthCoarse",
  "",
  "",
  "EmitVertex",
  "EndPrimitive",
  "EmitStreamVertex",
  "EndStreamPrimitive",
  "",
  "",
  "ControlBarrier",
  "MemoryBarrier",
  "",
  "AtomicLoad",
  "AtomicStore",
  "AtomicExchange",
  "AtomicCompareExchange",
  "AtomicCompareExchangeWeak",
  "AtomicIIncrement",
  "AtomicIDecrement",
  "AtomicIAdd",
  "AtomicISub",
  "AtomicSMin",
  "AtomicUMin",
  "AtomicSMax",
  "AtomicUMax",
  "AtomicAnd",
  "AtomicOr",
  "AtomicXor",
  "",
  "",
  "Phi",
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
  "",
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
  "",
  "",
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
  "",
  "",
  "",  
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
};

extern void* LUTPointers[];