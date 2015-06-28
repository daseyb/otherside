#include <assert.h>
#include "parser_definitions.h"
#include "lookups.h"
#include "lookups_gen.h"

static void HandleNop(void* op, Program* prog) {
  SNop* opNop = (SNop*)op;
  assert(false);
}

static void HandleSource(void* op, Program* prog) {
  SSource* opSource = (SSource*)op;
  prog->SourceLanguage = *opSource;
}

static void HandleSourceExtension(void* op, Program* prog) {
  SSourceExtension* opSourceExtension = (SSourceExtension*)op;
  prog->SourceExtensions.push_back(opSourceExtension->Extension);
}

static void HandleExtension(void* op, Program* prog) {
  SExtension* opExtension = (SExtension*)op;
  prog->SPIRVExtensions.push_back(opExtension->Name);
}

static void HandleExtInstImport(void* op, Program* prog) {
  SExtInstImport* opExtInstImport = (SExtInstImport*)op;
  prog->ExtensionImports.insert(std::pair<uint32, SExtInstImport>(opExtInstImport->ResultId, *opExtInstImport));
}

static void HandleMemoryModel(void* op, Program* prog) {
  SMemoryModel* opMemoryModel = (SMemoryModel*)op;
  prog->MemoryModel = *opMemoryModel;
}

static void HandleEntryPoint(void* op, Program* prog) {
  SEntryPoint* opEntryPoint = (SEntryPoint*)op;
  prog->EntryPoints.insert(std::pair<uint32, SEntryPoint>(opEntryPoint->EntryPointId, *opEntryPoint));
}

static void HandleExecutionMode(void* op, Program* prog) {
  SExecutionMode* opExecutionMode = (SExecutionMode*)op;
  prog->ExecutionModes.insert(std::pair<uint32, SExecutionMode>(opExecutionMode->EntryPointId, *opExecutionMode));
}

static void HandleTypeVoid(void* op, Program* prog) {
  STypeVoid* opTypeVoid = (STypeVoid*)op;
  prog->DefinedTypes.insert(std::pair<uint32, SOp>(opTypeVoid->ResultId, SOp{ Op::OpTypeVoid, op }));
}

static void HandleTypeBool(void* op, Program* prog) {
  STypeBool* opTypeBool = (STypeBool*)op;
  prog->DefinedTypes.insert(std::pair<uint32, SOp>(opTypeBool->ResultId, SOp{ Op::OpTypeBool, op }));
}

static void HandleTypeInt(void* op, Program* prog) {
  STypeInt* opTypeInt = (STypeInt*)op;
  prog->DefinedTypes.insert(std::pair<uint32, SOp>(opTypeInt->ResultId, SOp{ Op::OpTypeInt, op }));
}

static void HandleTypeFloat(void* op, Program* prog) {
  STypeFloat* opTypeFloat = (STypeFloat*)op;
  prog->DefinedTypes.insert(std::pair<uint32, SOp>(opTypeFloat->ResultId, SOp{ Op::OpTypeFloat, op }));
}

static void HandleTypeVector(void* op, Program* prog) {
  STypeVector* opTypeVector = (STypeVector*)op;
  prog->DefinedTypes.insert(std::pair<uint32, SOp>(opTypeVector->ResultId, SOp{ Op::OpTypeVector, op }));
}

static void HandleTypeMatrix(void* op, Program* prog) {
  STypeMatrix* opTypeMatrix = (STypeMatrix*)op;
  prog->DefinedTypes.insert(std::pair<uint32, SOp>(opTypeMatrix->ResultId, SOp{ Op::OpTypeMatrix, op }));
}

static void HandleTypeSampler(void* op, Program* prog) {
  STypeSampler* opTypeSampler = (STypeSampler*)op;
  prog->DefinedTypes.insert(std::pair<uint32, SOp>(opTypeSampler->ResultId, SOp{ Op::OpTypeSampler, op }));
}

static void HandleTypeFilter(void* op, Program* prog) {
  STypeFilter* opTypeFilter = (STypeFilter*)op;
  prog->DefinedTypes.insert(std::pair<uint32, SOp>(opTypeFilter->ResultId, SOp{ Op::OpTypeFilter, op }));
}

static void HandleTypeArray(void* op, Program* prog) {
  STypeArray* opTypeArray = (STypeArray*)op;
  prog->DefinedTypes.insert(std::pair<uint32, SOp>(opTypeArray->ResultId, SOp{ Op::OpTypeArray, op }));
}

static void HandleTypeRuntimeArray(void* op, Program* prog) {
  STypeRuntimeArray* opTypeRuntimeArray = (STypeRuntimeArray*)op;
  prog->DefinedTypes.insert(std::pair<uint32, SOp>(opTypeRuntimeArray->ResultId, SOp{ Op::OpTypeRuntimeArray, op }));
}

static void HandleTypeStruct(void* op, Program* prog) {
  STypeStruct* opTypeStruct = (STypeStruct*)op;
  prog->DefinedTypes.insert(std::pair<uint32, SOp>(opTypeStruct->ResultId, SOp{ Op::OpTypeStruct, op }));
}

static void HandleTypeOpaque(void* op, Program* prog) {
  STypeOpaque* opTypeOpaque = (STypeOpaque*)op;
  prog->DefinedTypes.insert(std::pair<uint32, SOp>(opTypeOpaque->ResultId, SOp{ Op::OpTypeOpaque, op }));
}

static void HandleTypePointer(void* op, Program* prog) {
  STypePointer* opTypePointer = (STypePointer*)op;
  prog->DefinedTypes.insert(std::pair<uint32, SOp>(opTypePointer->ResultId, SOp{ Op::OpTypePointer, op }));
}

static void HandleTypeFunction(void* op, Program* prog) {
  STypeFunction* opTypeFunction = (STypeFunction*)op;
  prog->DefinedTypes.insert(std::pair<uint32, SOp>(opTypeFunction->ResultId, SOp{ Op::OpTypeFunction, op }));
}

static void HandleTypeEvent(void* op, Program* prog) {
  STypeEvent* opTypeEvent = (STypeEvent*)op;
  prog->DefinedTypes.insert(std::pair<uint32, SOp>(opTypeEvent->ResultId, SOp{ Op::OpTypeEvent, op }));
}

static void HandleTypeDeviceEvent(void* op, Program* prog) {
  STypeDeviceEvent* opTypeDeviceEvent = (STypeDeviceEvent*)op;
  prog->DefinedTypes.insert(std::pair<uint32, SOp>(opTypeDeviceEvent->ResultId, SOp{ Op::OpTypeDeviceEvent, op }));
}

static void HandleTypeReserveId(void* op, Program* prog) {
  STypeReserveId* opTypeReserveId = (STypeReserveId*)op;
  prog->DefinedTypes.insert(std::pair<uint32, SOp>(opTypeReserveId->ResultId, SOp{ Op::OpTypeReserveId, op }));
}

static void HandleTypeQueue(void* op, Program* prog) {
  STypeQueue* opTypeQueue = (STypeQueue*)op;
  prog->DefinedTypes.insert(std::pair<uint32, SOp>(opTypeQueue->ResultId, SOp{ Op::OpTypeQueue, op }));
}

static void HandleTypePipe(void* op, Program* prog) {
  STypePipe* opTypePipe = (STypePipe*)op;
  prog->DefinedTypes.insert(std::pair<uint32, SOp>(opTypePipe->ResultId, SOp{ Op::OpTypePipe, op }));
}

static void HandleConstantTrue(void* op, Program* prog) {
  SConstantTrue* opConstantTrue = (SConstantTrue*)op;
}

static void HandleConstantFalse(void* op, Program* prog) {
  SConstantFalse* opConstantFalse = (SConstantFalse*)op;
}

static void HandleConstant(void* op, Program* prog) {
  SConstant* opConstant = (SConstant*)op;
}

static void HandleConstantComposite(void* op, Program* prog) {
  SConstantComposite* opConstantComposite = (SConstantComposite*)op;
}

static void HandleConstantSampler(void* op, Program* prog) {
  SConstantSampler* opConstantSampler = (SConstantSampler*)op;
}

static void HandleConstantNullPointer(void* op, Program* prog) {
  SConstantNullPointer* opConstantNullPointer = (SConstantNullPointer*)op;
}

static void HandleConstantNullObject(void* op, Program* prog) {
  SConstantNullObject* opConstantNullObject = (SConstantNullObject*)op;
}

static void HandleSpecConstantTrue(void* op, Program* prog) {
  SSpecConstantTrue* opSpecConstantTrue = (SSpecConstantTrue*)op;
}

static void HandleSpecConstantFalse(void* op, Program* prog) {
  SSpecConstantFalse* opSpecConstantFalse = (SSpecConstantFalse*)op;
}

static void HandleSpecConstant(void* op, Program* prog) {
  SSpecConstant* opSpecConstant = (SSpecConstant*)op;
}

static void HandleSpecConstantComposite(void* op, Program* prog) {
  SSpecConstantComposite* opSpecConstantComposite = (SSpecConstantComposite*)op;
}

static void HandleVariable(void* op, Program* prog) {
  SVariable* opVariable = (SVariable*)op;
}

static void HandleVariableArray(void* op, Program* prog) {
  SVariableArray* opVariableArray = (SVariableArray*)op;
}

static void HandleFunction(void* op, Program* prog) {
  SFunction* opFunction = (SFunction*)op;
  startFunction(prog, *opFunction);
}

static void HandleFunctionParameter(void* op, Program* prog) {
  SFunctionParameter* opFunctionParameter = (SFunctionParameter*)op;
  prog->CurrentFunction.Parameters.push_back(*opFunctionParameter);
}

static void HandleFunctionEnd(void* op, Program* prog) {
  SFunctionEnd* opFunctionEnd = (SFunctionEnd*)op;
  endFunction(prog);
}

static void HandleFunctionCall(void* op, Program* prog) {
  SFunctionCall* opFunctionCall = (SFunctionCall*)op;
}

static void HandleExtInst(void* op, Program* prog) {
  SExtInst* opExtInst = (SExtInst*)op;
}

static void HandleUndef(void* op, Program* prog) {
  SUndef* opUndef = (SUndef*)op;
}

static void HandleLoad(void* op, Program* prog) {
  SLoad* opLoad = (SLoad*)op;
}

static void HandleStore(void* op, Program* prog) {
  SStore* opStore = (SStore*)op;
}

static void HandlePhi(void* op, Program* prog) {
  SPhi* opPhi = (SPhi*)op;
}

static void HandleDecorationGroup(void* op, Program* prog) {
  SDecorationGroup* opDecorationGroup = (SDecorationGroup*)op;
}

static void HandleDecorate(void* op, Program* prog) {
  SDecorate* opDecorate = (SDecorate*)op;
}

static void HandleMemberDecorate(void* op, Program* prog) {
  SMemberDecorate* opMemberDecorate = (SMemberDecorate*)op;
}

static void HandleGroupDecorate(void* op, Program* prog) {
  SGroupDecorate* opGroupDecorate = (SGroupDecorate*)op;
}

static void HandleGroupMemberDecorate(void* op, Program* prog) {
  SGroupMemberDecorate* opGroupMemberDecorate = (SGroupMemberDecorate*)op;
}

static void HandleName(void* op, Program* prog) {
  SName* opName = (SName*)op;
  prog->Names.insert(std::pair<uint32, SName>(opName->TargetId, *opName));
}

static void HandleMemberName(void* op, Program* prog) {
  SMemberName* opMemberName = (SMemberName*)op;
  prog->MemberNames.insert(std::pair<uint32, SMemberName>(opMemberName->Member, *opMemberName));
}

static void HandleString(void* op, Program* prog) {
  SString* opString = (SString*)op;
  prog->Strings.insert(std::pair<uint32, SString>(opString->ResultId, *opString));
}

static void HandleLine(void* op, Program* prog) {
  SLine* opLine = (SLine*)op;
  prog->Lines.insert(std::pair<uint32, SLine>(opLine->TargetId, *opLine));
}

static void HandleVectorExtractDynamic(void* op, Program* prog) {
  SVectorExtractDynamic* opVectorExtractDynamic = (SVectorExtractDynamic*)op;
}

static void HandleVectorInsertDynamic(void* op, Program* prog) {
  SVectorInsertDynamic* opVectorInsertDynamic = (SVectorInsertDynamic*)op;
}

static void HandleVectorShuffle(void* op, Program* prog) {
  SVectorShuffle* opVectorShuffle = (SVectorShuffle*)op;
}

static void HandleCompositeConstruct(void* op, Program* prog) {
  SCompositeConstruct* opCompositeConstruct = (SCompositeConstruct*)op;
}

static void HandleCompositeExtract(void* op, Program* prog) {
  SCompositeExtract* opCompositeExtract = (SCompositeExtract*)op;
}

static void HandleCompositeInsert(void* op, Program* prog) {
  SCompositeInsert* opCompositeInsert = (SCompositeInsert*)op;
}

static void HandleCopyObject(void* op, Program* prog) {
  SCopyObject* opCopyObject = (SCopyObject*)op;
}

static void HandleCopyMemory(void* op, Program* prog) {
  SCopyMemory* opCopyMemory = (SCopyMemory*)op;
}

static void HandleCopyMemorySized(void* op, Program* prog) {
  SCopyMemorySized* opCopyMemorySized = (SCopyMemorySized*)op;
}

static void HandleSampler(void* op, Program* prog) {
  SSampler* opSampler = (SSampler*)op;
}

static void HandleTextureSample(void* op, Program* prog) {
  STextureSample* opTextureSample = (STextureSample*)op;
}

static void HandleTextureSampleDref(void* op, Program* prog) {
  STextureSampleDref* opTextureSampleDref = (STextureSampleDref*)op;
}

static void HandleTextureSampleLod(void* op, Program* prog) {
  STextureSampleLod* opTextureSampleLod = (STextureSampleLod*)op;
}

static void HandleTextureSampleProj(void* op, Program* prog) {
  STextureSampleProj* opTextureSampleProj = (STextureSampleProj*)op;
}

static void HandleTextureSampleGrad(void* op, Program* prog) {
  STextureSampleGrad* opTextureSampleGrad = (STextureSampleGrad*)op;
}

static void HandleTextureSampleOffset(void* op, Program* prog) {
  STextureSampleOffset* opTextureSampleOffset = (STextureSampleOffset*)op;
}

static void HandleTextureSampleProjLod(void* op, Program* prog) {
  STextureSampleProjLod* opTextureSampleProjLod = (STextureSampleProjLod*)op;
}

static void HandleTextureSampleProjGrad(void* op, Program* prog) {
  STextureSampleProjGrad* opTextureSampleProjGrad = (STextureSampleProjGrad*)op;
}

static void HandleTextureSampleLodOffset(void* op, Program* prog) {
  STextureSampleLodOffset* opTextureSampleLodOffset = (STextureSampleLodOffset*)op;
}

static void HandleTextureSampleProjOffset(void* op, Program* prog) {
  STextureSampleProjOffset* opTextureSampleProjOffset = (STextureSampleProjOffset*)op;
}

static void HandleTextureSampleGradOffset(void* op, Program* prog) {
  STextureSampleGradOffset* opTextureSampleGradOffset = (STextureSampleGradOffset*)op;
}

static void HandleTextureSampleProjLodOffset(void* op, Program* prog) {
  STextureSampleProjLodOffset* opTextureSampleProjLodOffset = (STextureSampleProjLodOffset*)op;
}

static void HandleTextureSampleProjGradOffset(void* op, Program* prog) {
  STextureSampleProjGradOffset* opTextureSampleProjGradOffset = (STextureSampleProjGradOffset*)op;
}

static void HandleTextureFetchTexelLod(void* op, Program* prog) {
  STextureFetchTexelLod* opTextureFetchTexelLod = (STextureFetchTexelLod*)op;
}

static void HandleTextureFetchTexelOffset(void* op, Program* prog) {
  STextureFetchTexelOffset* opTextureFetchTexelOffset = (STextureFetchTexelOffset*)op;
}

static void HandleTextureFetchSample(void* op, Program* prog) {
  STextureFetchSample* opTextureFetchSample = (STextureFetchSample*)op;
}

static void HandleTextureFetchTexel(void* op, Program* prog) {
  STextureFetchTexel* opTextureFetchTexel = (STextureFetchTexel*)op;
}

static void HandleTextureGather(void* op, Program* prog) {
  STextureGather* opTextureGather = (STextureGather*)op;
}

static void HandleTextureGatherOffset(void* op, Program* prog) {
  STextureGatherOffset* opTextureGatherOffset = (STextureGatherOffset*)op;
}

static void HandleTextureGatherOffsets(void* op, Program* prog) {
  STextureGatherOffsets* opTextureGatherOffsets = (STextureGatherOffsets*)op;
}

static void HandleTextureQuerySizeLod(void* op, Program* prog) {
  STextureQuerySizeLod* opTextureQuerySizeLod = (STextureQuerySizeLod*)op;
}

static void HandleTextureQuerySize(void* op, Program* prog) {
  STextureQuerySize* opTextureQuerySize = (STextureQuerySize*)op;
}

static void HandleTextureQueryLod(void* op, Program* prog) {
  STextureQueryLod* opTextureQueryLod = (STextureQueryLod*)op;
}

static void HandleTextureQueryLevels(void* op, Program* prog) {
  STextureQueryLevels* opTextureQueryLevels = (STextureQueryLevels*)op;
}

static void HandleTextureQuerySamples(void* op, Program* prog) {
  STextureQuerySamples* opTextureQuerySamples = (STextureQuerySamples*)op;
}

static void HandleAccessChain(void* op, Program* prog) {
  SAccessChain* opAccessChain = (SAccessChain*)op;
}

static void HandleInBoundsAccessChain(void* op, Program* prog) {
  SInBoundsAccessChain* opInBoundsAccessChain = (SInBoundsAccessChain*)op;
}

static void HandleSNegate(void* op, Program* prog) {
  SSNegate* opSNegate = (SSNegate*)op;
}

static void HandleFNegate(void* op, Program* prog) {
  SFNegate* opFNegate = (SFNegate*)op;
}

static void HandleNot(void* op, Program* prog) {
  SNot* opNot = (SNot*)op;
}

static void HandleAny(void* op, Program* prog) {
  SAny* opAny = (SAny*)op;
}

static void HandleAll(void* op, Program* prog) {
  SAll* opAll = (SAll*)op;
}

static void HandleConvertFToU(void* op, Program* prog) {
  SConvertFToU* opConvertFToU = (SConvertFToU*)op;
}

static void HandleConvertFToS(void* op, Program* prog) {
  SConvertFToS* opConvertFToS = (SConvertFToS*)op;
}

static void HandleConvertSToF(void* op, Program* prog) {
  SConvertSToF* opConvertSToF = (SConvertSToF*)op;
}

static void HandleConvertUToF(void* op, Program* prog) {
  SConvertUToF* opConvertUToF = (SConvertUToF*)op;
}

static void HandleUConvert(void* op, Program* prog) {
  SUConvert* opUConvert = (SUConvert*)op;
}

static void HandleSConvert(void* op, Program* prog) {
  SSConvert* opSConvert = (SSConvert*)op;
}

static void HandleFConvert(void* op, Program* prog) {
  SFConvert* opFConvert = (SFConvert*)op;
}

static void HandleConvertPtrToU(void* op, Program* prog) {
  SConvertPtrToU* opConvertPtrToU = (SConvertPtrToU*)op;
}

static void HandleConvertUToPtr(void* op, Program* prog) {
  SConvertUToPtr* opConvertUToPtr = (SConvertUToPtr*)op;
}

static void HandlePtrCastToGeneric(void* op, Program* prog) {
  SPtrCastToGeneric* opPtrCastToGeneric = (SPtrCastToGeneric*)op;
}

static void HandleGenericCastToPtr(void* op, Program* prog) {
  SGenericCastToPtr* opGenericCastToPtr = (SGenericCastToPtr*)op;
}

static void HandleBitcast(void* op, Program* prog) {
  SBitcast* opBitcast = (SBitcast*)op;
}

static void HandleTranspose(void* op, Program* prog) {
  STranspose* opTranspose = (STranspose*)op;
}

static void HandleIsNan(void* op, Program* prog) {
  SIsNan* opIsNan = (SIsNan*)op;
}

static void HandleIsInf(void* op, Program* prog) {
  SIsInf* opIsInf = (SIsInf*)op;
}

static void HandleIsFinite(void* op, Program* prog) {
  SIsFinite* opIsFinite = (SIsFinite*)op;
}

static void HandleIsNormal(void* op, Program* prog) {
  SIsNormal* opIsNormal = (SIsNormal*)op;
}

static void HandleSignBitSet(void* op, Program* prog) {
  SSignBitSet* opSignBitSet = (SSignBitSet*)op;
}

static void HandleLessOrGreater(void* op, Program* prog) {
  SLessOrGreater* opLessOrGreater = (SLessOrGreater*)op;
}

static void HandleOrdered(void* op, Program* prog) {
  SOrdered* opOrdered = (SOrdered*)op;
}

static void HandleUnordered(void* op, Program* prog) {
  SUnordered* opUnordered = (SUnordered*)op;
}

static void HandleArrayLength(void* op, Program* prog) {
  SArrayLength* opArrayLength = (SArrayLength*)op;
}

static void HandleIAdd(void* op, Program* prog) {
  SIAdd* opIAdd = (SIAdd*)op;
}

static void HandleFAdd(void* op, Program* prog) {
  SFAdd* opFAdd = (SFAdd*)op;
}

static void HandleISub(void* op, Program* prog) {
  SISub* opISub = (SISub*)op;
}

static void HandleFSub(void* op, Program* prog) {
  SFSub* opFSub = (SFSub*)op;
}

static void HandleIMul(void* op, Program* prog) {
  SIMul* opIMul = (SIMul*)op;
}

static void HandleFMul(void* op, Program* prog) {
  SFMul* opFMul = (SFMul*)op;
}

static void HandleUDiv(void* op, Program* prog) {
  SUDiv* opUDiv = (SUDiv*)op;
}

static void HandleSDiv(void* op, Program* prog) {
  SSDiv* opSDiv = (SSDiv*)op;
}

static void HandleFDiv(void* op, Program* prog) {
  SFDiv* opFDiv = (SFDiv*)op;
}

static void HandleUMod(void* op, Program* prog) {
  SUMod* opUMod = (SUMod*)op;
}

static void HandleSRem(void* op, Program* prog) {
  SSRem* opSRem = (SSRem*)op;
}

static void HandleSMod(void* op, Program* prog) {
  SSMod* opSMod = (SSMod*)op;
}

static void HandleFRem(void* op, Program* prog) {
  SFRem* opFRem = (SFRem*)op;
}

static void HandleFMod(void* op, Program* prog) {
  SFMod* opFMod = (SFMod*)op;
}

static void HandleVectorTimesScalar(void* op, Program* prog) {
  SVectorTimesScalar* opVectorTimesScalar = (SVectorTimesScalar*)op;
}

static void HandleMatrixTimesScalar(void* op, Program* prog) {
  SMatrixTimesScalar* opMatrixTimesScalar = (SMatrixTimesScalar*)op;
}

static void HandleVectorTimesMatrix(void* op, Program* prog) {
  SVectorTimesMatrix* opVectorTimesMatrix = (SVectorTimesMatrix*)op;
}

static void HandleMatrixTimesVector(void* op, Program* prog) {
  SMatrixTimesVector* opMatrixTimesVector = (SMatrixTimesVector*)op;
}

static void HandleMatrixTimesMatrix(void* op, Program* prog) {
  SMatrixTimesMatrix* opMatrixTimesMatrix = (SMatrixTimesMatrix*)op;
}

static void HandleOuterProduct(void* op, Program* prog) {
  SOuterProduct* opOuterProduct = (SOuterProduct*)op;
}

static void HandleDot(void* op, Program* prog) {
  SDot* opDot = (SDot*)op;
}

static void HandleShiftRightLogical(void* op, Program* prog) {
  SShiftRightLogical* opShiftRightLogical = (SShiftRightLogical*)op;
}

static void HandleShiftRightArithmetic(void* op, Program* prog) {
  SShiftRightArithmetic* opShiftRightArithmetic = (SShiftRightArithmetic*)op;
}

static void HandleShiftLeftLogical(void* op, Program* prog) {
  SShiftLeftLogical* opShiftLeftLogical = (SShiftLeftLogical*)op;
}

static void HandleLogicalOr(void* op, Program* prog) {
  SLogicalOr* opLogicalOr = (SLogicalOr*)op;
}

static void HandleLogicalXor(void* op, Program* prog) {
  SLogicalXor* opLogicalXor = (SLogicalXor*)op;
}

static void HandleLogicalAnd(void* op, Program* prog) {
  SLogicalAnd* opLogicalAnd = (SLogicalAnd*)op;
}

static void HandleBitwiseOr(void* op, Program* prog) {
  SBitwiseOr* opBitwiseOr = (SBitwiseOr*)op;
}

static void HandleBitwiseXor(void* op, Program* prog) {
  SBitwiseXor* opBitwiseXor = (SBitwiseXor*)op;
}

static void HandleBitwiseAnd(void* op, Program* prog) {
  SBitwiseAnd* opBitwiseAnd = (SBitwiseAnd*)op;
}

static void HandleSelect(void* op, Program* prog) {
  SSelect* opSelect = (SSelect*)op;
}

static void HandleIEqual(void* op, Program* prog) {
  SIEqual* opIEqual = (SIEqual*)op;
}

static void HandleFOrdEqual(void* op, Program* prog) {
  SFOrdEqual* opFOrdEqual = (SFOrdEqual*)op;
}

static void HandleFUnordEqual(void* op, Program* prog) {
  SFUnordEqual* opFUnordEqual = (SFUnordEqual*)op;
}

static void HandleINotEqual(void* op, Program* prog) {
  SINotEqual* opINotEqual = (SINotEqual*)op;
}

static void HandleFOrdNotEqual(void* op, Program* prog) {
  SFOrdNotEqual* opFOrdNotEqual = (SFOrdNotEqual*)op;
}

static void HandleFUnordNotEqual(void* op, Program* prog) {
  SFUnordNotEqual* opFUnordNotEqual = (SFUnordNotEqual*)op;
}

static void HandleULessThan(void* op, Program* prog) {
  SULessThan* opULessThan = (SULessThan*)op;
}

static void HandleSLessThan(void* op, Program* prog) {
  SSLessThan* opSLessThan = (SSLessThan*)op;
}

static void HandleFOrdLessThan(void* op, Program* prog) {
  SFOrdLessThan* opFOrdLessThan = (SFOrdLessThan*)op;
}

static void HandleFUnordLessThan(void* op, Program* prog) {
  SFUnordLessThan* opFUnordLessThan = (SFUnordLessThan*)op;
}

static void HandleUGreaterThan(void* op, Program* prog) {
  SUGreaterThan* opUGreaterThan = (SUGreaterThan*)op;
}

static void HandleSGreaterThan(void* op, Program* prog) {
  SSGreaterThan* opSGreaterThan = (SSGreaterThan*)op;
}

static void HandleFOrdGreaterThan(void* op, Program* prog) {
  SFOrdGreaterThan* opFOrdGreaterThan = (SFOrdGreaterThan*)op;
}

static void HandleFUnordGreaterThan(void* op, Program* prog) {
  SFUnordGreaterThan* opFUnordGreaterThan = (SFUnordGreaterThan*)op;
}

static void HandleULessThanEqual(void* op, Program* prog) {
  SULessThanEqual* opULessThanEqual = (SULessThanEqual*)op;
}

static void HandleSLessThanEqual(void* op, Program* prog) {
  SSLessThanEqual* opSLessThanEqual = (SSLessThanEqual*)op;
}

static void HandleFOrdLessThanEqual(void* op, Program* prog) {
  SFOrdLessThanEqual* opFOrdLessThanEqual = (SFOrdLessThanEqual*)op;
}

static void HandleFUnordLessThanEqual(void* op, Program* prog) {
  SFUnordLessThanEqual* opFUnordLessThanEqual = (SFUnordLessThanEqual*)op;
}

static void HandleUGreaterThanEqual(void* op, Program* prog) {
  SUGreaterThanEqual* opUGreaterThanEqual = (SUGreaterThanEqual*)op;
}

static void HandleSGreaterThanEqual(void* op, Program* prog) {
  SSGreaterThanEqual* opSGreaterThanEqual = (SSGreaterThanEqual*)op;
}

static void HandleFOrdGreaterThanEqual(void* op, Program* prog) {
  SFOrdGreaterThanEqual* opFOrdGreaterThanEqual = (SFOrdGreaterThanEqual*)op;
}

static void HandleFUnordGreaterThanEqual(void* op, Program* prog) {
  SFUnordGreaterThanEqual* opFUnordGreaterThanEqual = (SFUnordGreaterThanEqual*)op;
}

static void HandleDPdx(void* op, Program* prog) {
  SDPdx* opDPdx = (SDPdx*)op;
}

static void HandleDPdy(void* op, Program* prog) {
  SDPdy* opDPdy = (SDPdy*)op;
}

static void HandleFwidth(void* op, Program* prog) {
  SFwidth* opFwidth = (SFwidth*)op;
}

static void HandleDPdxFine(void* op, Program* prog) {
  SDPdxFine* opDPdxFine = (SDPdxFine*)op;
}

static void HandleDPdyFine(void* op, Program* prog) {
  SDPdyFine* opDPdyFine = (SDPdyFine*)op;
}

static void HandleFwidthFine(void* op, Program* prog) {
  SFwidthFine* opFwidthFine = (SFwidthFine*)op;
}

static void HandleDPdxCoarse(void* op, Program* prog) {
  SDPdxCoarse* opDPdxCoarse = (SDPdxCoarse*)op;
}

static void HandleDPdyCoarse(void* op, Program* prog) {
  SDPdyCoarse* opDPdyCoarse = (SDPdyCoarse*)op;
}

static void HandleFwidthCoarse(void* op, Program* prog) {
  SFwidthCoarse* opFwidthCoarse = (SFwidthCoarse*)op;
}

static void HandleEmitVertex(void* op, Program* prog) {
  SEmitVertex* opEmitVertex = (SEmitVertex*)op;
}

static void HandleEndPrimitive(void* op, Program* prog) {
  SEndPrimitive* opEndPrimitive = (SEndPrimitive*)op;
}

static void HandleEmitStreamVertex(void* op, Program* prog) {
  SEmitStreamVertex* opEmitStreamVertex = (SEmitStreamVertex*)op;
}

static void HandleEndStreamPrimitive(void* op, Program* prog) {
  SEndStreamPrimitive* opEndStreamPrimitive = (SEndStreamPrimitive*)op;
}

static void HandleControlBarrier(void* op, Program* prog) {
  SControlBarrier* opControlBarrier = (SControlBarrier*)op;
}

static void HandleMemoryBarrier(void* op, Program* prog) {
  SMemoryBarrier* opMemoryBarrier = (SMemoryBarrier*)op;
}

static void HandleImagePointer(void* op, Program* prog) {
  SImagePointer* opImagePointer = (SImagePointer*)op;
}

static void HandleAtomicInit(void* op, Program* prog) {
  SAtomicInit* opAtomicInit = (SAtomicInit*)op;
}

static void HandleAtomicLoad(void* op, Program* prog) {
  SAtomicLoad* opAtomicLoad = (SAtomicLoad*)op;
}

static void HandleAtomicStore(void* op, Program* prog) {
  SAtomicStore* opAtomicStore = (SAtomicStore*)op;
}

static void HandleAtomicExchange(void* op, Program* prog) {
  SAtomicExchange* opAtomicExchange = (SAtomicExchange*)op;
}

static void HandleAtomicCompareExchange(void* op, Program* prog) {
  SAtomicCompareExchange* opAtomicCompareExchange = (SAtomicCompareExchange*)op;
}

static void HandleAtomicCompareExchangeWeak(void* op, Program* prog) {
  SAtomicCompareExchangeWeak* opAtomicCompareExchangeWeak = (SAtomicCompareExchangeWeak*)op;
}

static void HandleAtomicIIncrement(void* op, Program* prog) {
  SAtomicIIncrement* opAtomicIIncrement = (SAtomicIIncrement*)op;
}

static void HandleAtomicIDecrement(void* op, Program* prog) {
  SAtomicIDecrement* opAtomicIDecrement = (SAtomicIDecrement*)op;
}

static void HandleAtomicIAdd(void* op, Program* prog) {
  SAtomicIAdd* opAtomicIAdd = (SAtomicIAdd*)op;
}

static void HandleAtomicISub(void* op, Program* prog) {
  SAtomicISub* opAtomicISub = (SAtomicISub*)op;
}

static void HandleAtomicUMin(void* op, Program* prog) {
  SAtomicUMin* opAtomicUMin = (SAtomicUMin*)op;
}

static void HandleAtomicUMax(void* op, Program* prog) {
  SAtomicUMax* opAtomicUMax = (SAtomicUMax*)op;
}

static void HandleAtomicAnd(void* op, Program* prog) {
  SAtomicAnd* opAtomicAnd = (SAtomicAnd*)op;
}

static void HandleAtomicOr(void* op, Program* prog) {
  SAtomicOr* opAtomicOr = (SAtomicOr*)op;
}

static void HandleAtomicXor(void* op, Program* prog) {
  SAtomicXor* opAtomicXor = (SAtomicXor*)op;
}

static void HandleLoopMerge(void* op, Program* prog) {
  SLoopMerge* opLoopMerge = (SLoopMerge*)op;
}

static void HandleSelectionMerge(void* op, Program* prog) {
  SSelectionMerge* opSelectionMerge = (SSelectionMerge*)op;
}

static void HandleLabel(void* op, Program* prog) {
  SLabel* opLabel = (SLabel*)op;
  startNewBlock(&prog->CurrentFunction);
}

static void HandleBranch(void* op, Program* prog) {
  SBranch* opBranch = (SBranch*)op;
  addOp(prog, SOp{ Op::OpBranch, opBranch });
  endBlock(&prog->CurrentFunction);
}

static void HandleBranchConditional(void* op, Program* prog) {
  SBranchConditional* opBranchConditional = (SBranchConditional*)op;
}

static void HandleSwitch(void* op, Program* prog) {
  SSwitch* opSwitch = (SSwitch*)op;
}

static void HandleKill(void* op, Program* prog) {
  SKill* opKill = (SKill*)op;
}

static void HandleReturn(void* op, Program* prog) {
  SReturn* opReturn = (SReturn*)op;
}

static void HandleReturnValue(void* op, Program* prog) {
  SReturnValue* opReturnValue = (SReturnValue*)op;
}

static void HandleUnreachable(void* op, Program* prog) {
  SUnreachable* opUnreachable = (SUnreachable*)op;
}

static void HandleLifetimeStart(void* op, Program* prog) {
  SLifetimeStart* opLifetimeStart = (SLifetimeStart*)op;
}

static void HandleLifetimeStop(void* op, Program* prog) {
  SLifetimeStop* opLifetimeStop = (SLifetimeStop*)op;
}

static void HandleCompileFlag(void* op, Program* prog) {
  SCompileFlag* opCompileFlag = (SCompileFlag*)op;
}

static void HandleAsyncGroupCopy(void* op, Program* prog) {
  SAsyncGroupCopy* opAsyncGroupCopy = (SAsyncGroupCopy*)op;
}

static void HandleWaitGroupEvents(void* op, Program* prog) {
  SWaitGroupEvents* opWaitGroupEvents = (SWaitGroupEvents*)op;
}

static void HandleGroupAll(void* op, Program* prog) {
  SGroupAll* opGroupAll = (SGroupAll*)op;
}

static void HandleGroupAny(void* op, Program* prog) {
  SGroupAny* opGroupAny = (SGroupAny*)op;
}

static void HandleGroupBroadcast(void* op, Program* prog) {
  SGroupBroadcast* opGroupBroadcast = (SGroupBroadcast*)op;
}

static void HandleGroupIAdd(void* op, Program* prog) {
  SGroupIAdd* opGroupIAdd = (SGroupIAdd*)op;
}

static void HandleGroupFAdd(void* op, Program* prog) {
  SGroupFAdd* opGroupFAdd = (SGroupFAdd*)op;
}

static void HandleGroupFMin(void* op, Program* prog) {
  SGroupFMin* opGroupFMin = (SGroupFMin*)op;
}

static void HandleGroupUMin(void* op, Program* prog) {
  SGroupUMin* opGroupUMin = (SGroupUMin*)op;
}

static void HandleGroupSMin(void* op, Program* prog) {
  SGroupSMin* opGroupSMin = (SGroupSMin*)op;
}

static void HandleGroupFMax(void* op, Program* prog) {
  SGroupFMax* opGroupFMax = (SGroupFMax*)op;
}

static void HandleGroupUMax(void* op, Program* prog) {
  SGroupUMax* opGroupUMax = (SGroupUMax*)op;
}

static void HandleGroupSMax(void* op, Program* prog) {
  SGroupSMax* opGroupSMax = (SGroupSMax*)op;
}

static void HandleGenericCastToPtrExplicit(void* op, Program* prog) {
  SGenericCastToPtrExplicit* opGenericCastToPtrExplicit = (SGenericCastToPtrExplicit*)op;
}

static void HandleGenericPtrMemSemantics(void* op, Program* prog) {
  SGenericPtrMemSemantics* opGenericPtrMemSemantics = (SGenericPtrMemSemantics*)op;
}

static void HandleReadPipe(void* op, Program* prog) {
  SReadPipe* opReadPipe = (SReadPipe*)op;
}

static void HandleWritePipe(void* op, Program* prog) {
  SWritePipe* opWritePipe = (SWritePipe*)op;
}

static void HandleReservedReadPipe(void* op, Program* prog) {
  SReservedReadPipe* opReservedReadPipe = (SReservedReadPipe*)op;
}

static void HandleReservedWritePipe(void* op, Program* prog) {
  SReservedWritePipe* opReservedWritePipe = (SReservedWritePipe*)op;
}

static void HandleReserveReadPipePackets(void* op, Program* prog) {
  SReserveReadPipePackets* opReserveReadPipePackets = (SReserveReadPipePackets*)op;
}

static void HandleReserveWritePipePackets(void* op, Program* prog) {
  SReserveWritePipePackets* opReserveWritePipePackets = (SReserveWritePipePackets*)op;
}

static void HandleCommitReadPipe(void* op, Program* prog) {
  SCommitReadPipe* opCommitReadPipe = (SCommitReadPipe*)op;
}

static void HandleCommitWritePipe(void* op, Program* prog) {
  SCommitWritePipe* opCommitWritePipe = (SCommitWritePipe*)op;
}

static void HandleIsValidReserveId(void* op, Program* prog) {
  SIsValidReserveId* opIsValidReserveId = (SIsValidReserveId*)op;
}

static void HandleGetNumPipePackets(void* op, Program* prog) {
  SGetNumPipePackets* opGetNumPipePackets = (SGetNumPipePackets*)op;
}

static void HandleGetMaxPipePackets(void* op, Program* prog) {
  SGetMaxPipePackets* opGetMaxPipePackets = (SGetMaxPipePackets*)op;
}

static void HandleGroupReserveReadPipePackets(void* op, Program* prog) {
  SGroupReserveReadPipePackets* opGroupReserveReadPipePackets = (SGroupReserveReadPipePackets*)op;
}

static void HandleGroupReserveWritePipePackets(void* op, Program* prog) {
  SGroupReserveWritePipePackets* opGroupReserveWritePipePackets = (SGroupReserveWritePipePackets*)op;
}

static void HandleGroupCommitReadPipe(void* op, Program* prog) {
  SGroupCommitReadPipe* opGroupCommitReadPipe = (SGroupCommitReadPipe*)op;
}

static void HandleGroupCommitWritePipe(void* op, Program* prog) {
  SGroupCommitWritePipe* opGroupCommitWritePipe = (SGroupCommitWritePipe*)op;
}

static void HandleEnqueueMarker(void* op, Program* prog) {
  SEnqueueMarker* opEnqueueMarker = (SEnqueueMarker*)op;
}

static void HandleEnqueueKernel(void* op, Program* prog) {
  SEnqueueKernel* opEnqueueKernel = (SEnqueueKernel*)op;
}

static void HandleGetKernelNDrangeSubGroupCount(void* op, Program* prog) {
  SGetKernelNDrangeSubGroupCount* opGetKernelNDrangeSubGroupCount = (SGetKernelNDrangeSubGroupCount*)op;
}

static void HandleGetKernelNDrangeMaxSubGroupSize(void* op, Program* prog) {
  SGetKernelNDrangeMaxSubGroupSize* opGetKernelNDrangeMaxSubGroupSize = (SGetKernelNDrangeMaxSubGroupSize*)op;
}

static void HandleGetKernelWorkGroupSize(void* op, Program* prog) {
  SGetKernelWorkGroupSize* opGetKernelWorkGroupSize = (SGetKernelWorkGroupSize*)op;
}

static void HandleGetKernelPreferredWorkGroupSizeMultiple(void* op, Program* prog) {
  SGetKernelPreferredWorkGroupSizeMultiple* opGetKernelPreferredWorkGroupSizeMultiple = (SGetKernelPreferredWorkGroupSizeMultiple*)op;
}

static void HandleRetainEvent(void* op, Program* prog) {
  SRetainEvent* opRetainEvent = (SRetainEvent*)op;
}

static void HandleReleaseEvent(void* op, Program* prog) {
  SReleaseEvent* opReleaseEvent = (SReleaseEvent*)op;
}

static void HandleCreateUserEvent(void* op, Program* prog) {
  SCreateUserEvent* opCreateUserEvent = (SCreateUserEvent*)op;
}

static void HandleIsValidEvent(void* op, Program* prog) {
  SIsValidEvent* opIsValidEvent = (SIsValidEvent*)op;
}

static void HandleSetUserEventStatus(void* op, Program* prog) {
  SSetUserEventStatus* opSetUserEventStatus = (SSetUserEventStatus*)op;
}

static void HandleCaptureEventProfilingInfo(void* op, Program* prog) {
  SCaptureEventProfilingInfo* opCaptureEventProfilingInfo = (SCaptureEventProfilingInfo*)op;
}

static void HandleGetDefaultQueue(void* op, Program* prog) {
  SGetDefaultQueue* opGetDefaultQueue = (SGetDefaultQueue*)op;
}

static void HandleBuildNDRange(void* op, Program* prog) {
  SBuildNDRange* opBuildNDRange = (SBuildNDRange*)op;
}

static void HandleSatConvertSToU(void* op, Program* prog) {
  SSatConvertSToU* opSatConvertSToU = (SSatConvertSToU*)op;
}

static void HandleSatConvertUToS(void* op, Program* prog) {
  SSatConvertUToS* opSatConvertUToS = (SSatConvertUToS*)op;
}

static void HandleAtomicIMin(void* op, Program* prog) {
  SAtomicIMin* opAtomicIMin = (SAtomicIMin*)op;
}

static void HandleAtomicIMax(void* op, Program* prog) {
  SAtomicIMax* opAtomicIMax = (SAtomicIMax*)op;
}