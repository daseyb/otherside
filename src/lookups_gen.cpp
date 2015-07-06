#include "lookups_gen.h"
#include "parser_definitions.h"


void HandleNop(void* op, Program* prog) {
  SNop* opNop = (SNop*)op;
  assert(false);
}

void HandleSource(void* op, Program* prog) {
  SSource* opSource = (SSource*)op;
  prog->SourceLanguage = *opSource;
}

void HandleSourceExtension(void* op, Program* prog) {
  SSourceExtension* opSourceExtension = (SSourceExtension*)op;
  prog->SourceExtensions.push_back(opSourceExtension->Extension);
}

void HandleExtension(void* op, Program* prog) {
  SExtension* opExtension = (SExtension*)op;
  prog->SPIRVExtensions.push_back(opExtension->Name);
}

void HandleExtInstImport(void* op, Program* prog) {
  SExtInstImport* opExtInstImport = (SExtInstImport*)op;
  prog->ExtensionImports.insert(std::pair<uint32, SExtInstImport>(opExtInstImport->ResultId, *opExtInstImport));
}

void HandleMemoryModel(void* op, Program* prog) {
  SMemoryModel* opMemoryModel = (SMemoryModel*)op;
  prog->MemoryModel = *opMemoryModel;
}

void HandleEntryPoint(void* op, Program* prog) {
  SEntryPoint* opEntryPoint = (SEntryPoint*)op;
  prog->EntryPoints.insert(std::pair<uint32, SEntryPoint>(opEntryPoint->EntryPointId, *opEntryPoint));
}

void HandleExecutionMode(void* op, Program* prog) {
  SExecutionMode* opExecutionMode = (SExecutionMode*)op;
  prog->ExecutionModes.insert(std::pair<uint32, SExecutionMode>(opExecutionMode->EntryPointId, *opExecutionMode));
}

void HandleTypeVoid(void* op, Program* prog) {
  STypeVoid* opTypeVoid = (STypeVoid*)op;
  prog->DefinedTypes.insert(std::pair<uint32, SOp>(opTypeVoid->ResultId, SOp{ Op::OpTypeVoid, op }));
}

void HandleTypeBool(void* op, Program* prog) {
  STypeBool* opTypeBool = (STypeBool*)op;
  prog->DefinedTypes.insert(std::pair<uint32, SOp>(opTypeBool->ResultId, SOp{ Op::OpTypeBool, op }));
}

void HandleTypeInt(void* op, Program* prog) {
  STypeInt* opTypeInt = (STypeInt*)op;
  prog->DefinedTypes.insert(std::pair<uint32, SOp>(opTypeInt->ResultId, SOp{ Op::OpTypeInt, op }));
}

void HandleTypeFloat(void* op, Program* prog) {
  STypeFloat* opTypeFloat = (STypeFloat*)op;
  prog->DefinedTypes.insert(std::pair<uint32, SOp>(opTypeFloat->ResultId, SOp{ Op::OpTypeFloat, op }));
}

void HandleTypeVector(void* op, Program* prog) {
  STypeVector* opTypeVector = (STypeVector*)op;
  prog->DefinedTypes.insert(std::pair<uint32, SOp>(opTypeVector->ResultId, SOp{ Op::OpTypeVector, op }));
}

void HandleTypeMatrix(void* op, Program* prog) {
  STypeMatrix* opTypeMatrix = (STypeMatrix*)op;
  prog->DefinedTypes.insert(std::pair<uint32, SOp>(opTypeMatrix->ResultId, SOp{ Op::OpTypeMatrix, op }));
}

void HandleTypeSampler(void* op, Program* prog) {
  STypeSampler* opTypeSampler = (STypeSampler*)op;
  prog->DefinedTypes.insert(std::pair<uint32, SOp>(opTypeSampler->ResultId, SOp{ Op::OpTypeSampler, op }));
}

void HandleTypeFilter(void* op, Program* prog) {
  STypeFilter* opTypeFilter = (STypeFilter*)op;
  prog->DefinedTypes.insert(std::pair<uint32, SOp>(opTypeFilter->ResultId, SOp{ Op::OpTypeFilter, op }));
}

void HandleTypeArray(void* op, Program* prog) {
  STypeArray* opTypeArray = (STypeArray*)op;
  prog->DefinedTypes.insert(std::pair<uint32, SOp>(opTypeArray->ResultId, SOp{ Op::OpTypeArray, op }));
}

void HandleTypeRuntimeArray(void* op, Program* prog) {
  STypeRuntimeArray* opTypeRuntimeArray = (STypeRuntimeArray*)op;
  prog->DefinedTypes.insert(std::pair<uint32, SOp>(opTypeRuntimeArray->ResultId, SOp{ Op::OpTypeRuntimeArray, op }));
}

void HandleTypeStruct(void* op, Program* prog) {
  STypeStruct* opTypeStruct = (STypeStruct*)op;
  prog->DefinedTypes.insert(std::pair<uint32, SOp>(opTypeStruct->ResultId, SOp{ Op::OpTypeStruct, op }));
}

void HandleTypeOpaque(void* op, Program* prog) {
  STypeOpaque* opTypeOpaque = (STypeOpaque*)op;
  prog->DefinedTypes.insert(std::pair<uint32, SOp>(opTypeOpaque->ResultId, SOp{ Op::OpTypeOpaque, op }));
}

void HandleTypePointer(void* op, Program* prog) {
  STypePointer* opTypePointer = (STypePointer*)op;
  prog->DefinedTypes.insert(std::pair<uint32, SOp>(opTypePointer->ResultId, SOp{ Op::OpTypePointer, op }));
}

void HandleTypeFunction(void* op, Program* prog) {
  STypeFunction* opTypeFunction = (STypeFunction*)op;
  prog->DefinedTypes.insert(std::pair<uint32, SOp>(opTypeFunction->ResultId, SOp{ Op::OpTypeFunction, op }));
}

void HandleTypeEvent(void* op, Program* prog) {
  STypeEvent* opTypeEvent = (STypeEvent*)op;
  prog->DefinedTypes.insert(std::pair<uint32, SOp>(opTypeEvent->ResultId, SOp{ Op::OpTypeEvent, op }));
}

void HandleTypeDeviceEvent(void* op, Program* prog) {
  STypeDeviceEvent* opTypeDeviceEvent = (STypeDeviceEvent*)op;
  prog->DefinedTypes.insert(std::pair<uint32, SOp>(opTypeDeviceEvent->ResultId, SOp{ Op::OpTypeDeviceEvent, op }));
}

void HandleTypeReserveId(void* op, Program* prog) {
  STypeReserveId* opTypeReserveId = (STypeReserveId*)op;
  prog->DefinedTypes.insert(std::pair<uint32, SOp>(opTypeReserveId->ResultId, SOp{ Op::OpTypeReserveId, op }));
}

void HandleTypeQueue(void* op, Program* prog) {
  STypeQueue* opTypeQueue = (STypeQueue*)op;
  prog->DefinedTypes.insert(std::pair<uint32, SOp>(opTypeQueue->ResultId, SOp{ Op::OpTypeQueue, op }));
}

void HandleTypePipe(void* op, Program* prog) {
  STypePipe* opTypePipe = (STypePipe*)op;
  prog->DefinedTypes.insert(std::pair<uint32, SOp>(opTypePipe->ResultId, SOp{ Op::OpTypePipe, op }));
}

void HandleConstantTrue(void* op, Program* prog) {
  SConstantTrue* opConstantTrue = (SConstantTrue*)op;
  prog->Constants.insert(std::pair<uint32, SOp>(opConstantTrue->ResultId, SOp{ Op::OpConstantTrue, op }));
}

void HandleConstantFalse(void* op, Program* prog) {
  SConstantFalse* opConstantFalse = (SConstantFalse*)op;
  prog->Constants.insert(std::pair<uint32, SOp>(opConstantFalse->ResultId, SOp{ Op::OpConstantFalse, op }));
}

void HandleConstant(void* op, Program* prog) {
  SConstant* opConstant = (SConstant*)op;
  prog->Constants.insert(std::pair<uint32, SOp>(opConstant->ResultId, SOp{ Op::OpConstant, op }));
}

void HandleConstantComposite(void* op, Program* prog) {
  SConstantComposite* opConstantComposite = (SConstantComposite*)op;
  prog->Constants.insert(std::pair<uint32, SOp>(opConstantComposite->ResultId, SOp{ Op::OpConstantComposite, op }));
}

void HandleConstantSampler(void* op, Program* prog) {
  SConstantSampler* opConstantSampler = (SConstantSampler*)op;
  prog->Constants.insert(std::pair<uint32, SOp>(opConstantSampler->ResultId, SOp{ Op::OpConstantSampler, op }));
}

void HandleConstantNullPointer(void* op, Program* prog) {
  SConstantNullPointer* opConstantNullPointer = (SConstantNullPointer*)op;
  prog->Constants.insert(std::pair<uint32, SOp>(opConstantNullPointer->ResultId, SOp{ Op::OpConstantNullPointer, op }));
}

void HandleConstantNullObject(void* op, Program* prog) {
  SConstantNullObject* opConstantNullObject = (SConstantNullObject*)op;
  prog->Constants.insert(std::pair<uint32, SOp>(opConstantNullObject->ResultId, SOp{ Op::OpConstantNullObject, op }));
}

void HandleSpecConstantTrue(void* op, Program* prog) {
  SSpecConstantTrue* opSpecConstantTrue = (SSpecConstantTrue*)op;
}

void HandleSpecConstantFalse(void* op, Program* prog) {
  SSpecConstantFalse* opSpecConstantFalse = (SSpecConstantFalse*)op;
}

void HandleSpecConstant(void* op, Program* prog) {
  SSpecConstant* opSpecConstant = (SSpecConstant*)op;
}

void HandleSpecConstantComposite(void* op, Program* prog) {
  SSpecConstantComposite* opSpecConstantComposite = (SSpecConstantComposite*)op;
}

void HandleVariable(void* op, Program* prog) {
  SVariable* opVariable = (SVariable*)op;
  addVariable(prog, *opVariable);
}

void HandleVariableArray(void* op, Program* prog) {
  SVariableArray* opVariableArray = (SVariableArray*)op;
  addArray(prog, *opVariableArray);
}

void HandleFunction(void* op, Program* prog) {
  SFunction* opFunction = (SFunction*)op;
  startFunction(prog, *opFunction);
}

void HandleFunctionParameter(void* op, Program* prog) {
  SFunctionParameter* opFunctionParameter = (SFunctionParameter*)op;
  prog->CurrentFunction.Parameters.push_back(*opFunctionParameter);
}

void HandleFunctionEnd(void* op, Program* prog) {
  SFunctionEnd* opFunctionEnd = (SFunctionEnd*)op;
  endFunction(prog);
}

void HandleFunctionCall(void* op, Program* prog) {
  SFunctionCall* opFunctionCall = (SFunctionCall*)op;
}

void HandleExtInst(void* op, Program* prog) {
  SExtInst* opExtInst = (SExtInst*)op;
}

void HandleUndef(void* op, Program* prog) {
  SUndef* opUndef = (SUndef*)op;
}

void HandleLoad(void* op, Program* prog) {
  SLoad* opLoad = (SLoad*)op;
}

void HandleStore(void* op, Program* prog) {
  SStore* opStore = (SStore*)op;
}

void HandlePhi(void* op, Program* prog) {
  SPhi* opPhi = (SPhi*)op;
}

void HandleDecorationGroup(void* op, Program* prog) {
  SDecorationGroup* opDecorationGroup = (SDecorationGroup*)op;
}

void HandleDecorate(void* op, Program* prog) {
  SDecorate* opDecorate = (SDecorate*)op;
}

void HandleMemberDecorate(void* op, Program* prog) {
  SMemberDecorate* opMemberDecorate = (SMemberDecorate*)op;
}

void HandleGroupDecorate(void* op, Program* prog) {
  SGroupDecorate* opGroupDecorate = (SGroupDecorate*)op;
}

void HandleGroupMemberDecorate(void* op, Program* prog) {
  SGroupMemberDecorate* opGroupMemberDecorate = (SGroupMemberDecorate*)op;
}

void HandleName(void* op, Program* prog) {
  SName* opName = (SName*)op;
  prog->Names.insert(std::pair<uint32, SName>(opName->TargetId, *opName));
}

void HandleMemberName(void* op, Program* prog) {
  SMemberName* opMemberName = (SMemberName*)op;
  uint32 key = (opMemberName->TypeId << 16) & opMemberName->TypeId;

  prog->MemberNames.insert(std::pair<uint32, SMemberName>(key, *opMemberName));
}

void HandleString(void* op, Program* prog) {
  SString* opString = (SString*)op;
  prog->Strings.insert(std::pair<uint32, SString>(opString->ResultId, *opString));
}

void HandleLine(void* op, Program* prog) {
  SLine* opLine = (SLine*)op;
  prog->Lines.insert(std::pair<uint32, SLine>(opLine->TargetId, *opLine));
}

void HandleVectorExtractDynamic(void* op, Program* prog) {
  SVectorExtractDynamic* opVectorExtractDynamic = (SVectorExtractDynamic*)op;
}

void HandleVectorInsertDynamic(void* op, Program* prog) {
  SVectorInsertDynamic* opVectorInsertDynamic = (SVectorInsertDynamic*)op;
}

void HandleVectorShuffle(void* op, Program* prog) {
  SVectorShuffle* opVectorShuffle = (SVectorShuffle*)op;
}

void HandleCompositeConstruct(void* op, Program* prog) {
  SCompositeConstruct* opCompositeConstruct = (SCompositeConstruct*)op;
}

void HandleCompositeExtract(void* op, Program* prog) {
  SCompositeExtract* opCompositeExtract = (SCompositeExtract*)op;
}

void HandleCompositeInsert(void* op, Program* prog) {
  SCompositeInsert* opCompositeInsert = (SCompositeInsert*)op;
}

void HandleCopyObject(void* op, Program* prog) {
  SCopyObject* opCopyObject = (SCopyObject*)op;
}

void HandleCopyMemory(void* op, Program* prog) {
  SCopyMemory* opCopyMemory = (SCopyMemory*)op;
}

void HandleCopyMemorySized(void* op, Program* prog) {
  SCopyMemorySized* opCopyMemorySized = (SCopyMemorySized*)op;
}

void HandleSampler(void* op, Program* prog) {
  SSampler* opSampler = (SSampler*)op;
}

void HandleTextureSample(void* op, Program* prog) {
  STextureSample* opTextureSample = (STextureSample*)op;
}

void HandleTextureSampleDref(void* op, Program* prog) {
  STextureSampleDref* opTextureSampleDref = (STextureSampleDref*)op;
}

void HandleTextureSampleLod(void* op, Program* prog) {
  STextureSampleLod* opTextureSampleLod = (STextureSampleLod*)op;
}

void HandleTextureSampleProj(void* op, Program* prog) {
  STextureSampleProj* opTextureSampleProj = (STextureSampleProj*)op;
}

void HandleTextureSampleGrad(void* op, Program* prog) {
  STextureSampleGrad* opTextureSampleGrad = (STextureSampleGrad*)op;
}

void HandleTextureSampleOffset(void* op, Program* prog) {
  STextureSampleOffset* opTextureSampleOffset = (STextureSampleOffset*)op;
}

void HandleTextureSampleProjLod(void* op, Program* prog) {
  STextureSampleProjLod* opTextureSampleProjLod = (STextureSampleProjLod*)op;
}

void HandleTextureSampleProjGrad(void* op, Program* prog) {
  STextureSampleProjGrad* opTextureSampleProjGrad = (STextureSampleProjGrad*)op;
}

void HandleTextureSampleLodOffset(void* op, Program* prog) {
  STextureSampleLodOffset* opTextureSampleLodOffset = (STextureSampleLodOffset*)op;
}

void HandleTextureSampleProjOffset(void* op, Program* prog) {
  STextureSampleProjOffset* opTextureSampleProjOffset = (STextureSampleProjOffset*)op;
}

void HandleTextureSampleGradOffset(void* op, Program* prog) {
  STextureSampleGradOffset* opTextureSampleGradOffset = (STextureSampleGradOffset*)op;
}

void HandleTextureSampleProjLodOffset(void* op, Program* prog) {
  STextureSampleProjLodOffset* opTextureSampleProjLodOffset = (STextureSampleProjLodOffset*)op;
}

void HandleTextureSampleProjGradOffset(void* op, Program* prog) {
  STextureSampleProjGradOffset* opTextureSampleProjGradOffset = (STextureSampleProjGradOffset*)op;
}

void HandleTextureFetchTexelLod(void* op, Program* prog) {
  STextureFetchTexelLod* opTextureFetchTexelLod = (STextureFetchTexelLod*)op;
}

void HandleTextureFetchTexelOffset(void* op, Program* prog) {
  STextureFetchTexelOffset* opTextureFetchTexelOffset = (STextureFetchTexelOffset*)op;
}

void HandleTextureFetchSample(void* op, Program* prog) {
  STextureFetchSample* opTextureFetchSample = (STextureFetchSample*)op;
}

void HandleTextureFetchTexel(void* op, Program* prog) {
  STextureFetchTexel* opTextureFetchTexel = (STextureFetchTexel*)op;
}

void HandleTextureGather(void* op, Program* prog) {
  STextureGather* opTextureGather = (STextureGather*)op;
}

void HandleTextureGatherOffset(void* op, Program* prog) {
  STextureGatherOffset* opTextureGatherOffset = (STextureGatherOffset*)op;
}

void HandleTextureGatherOffsets(void* op, Program* prog) {
  STextureGatherOffsets* opTextureGatherOffsets = (STextureGatherOffsets*)op;
}

void HandleTextureQuerySizeLod(void* op, Program* prog) {
  STextureQuerySizeLod* opTextureQuerySizeLod = (STextureQuerySizeLod*)op;
}

void HandleTextureQuerySize(void* op, Program* prog) {
  STextureQuerySize* opTextureQuerySize = (STextureQuerySize*)op;
}

void HandleTextureQueryLod(void* op, Program* prog) {
  STextureQueryLod* opTextureQueryLod = (STextureQueryLod*)op;
}

void HandleTextureQueryLevels(void* op, Program* prog) {
  STextureQueryLevels* opTextureQueryLevels = (STextureQueryLevels*)op;
}

void HandleTextureQuerySamples(void* op, Program* prog) {
  STextureQuerySamples* opTextureQuerySamples = (STextureQuerySamples*)op;
}

void HandleAccessChain(void* op, Program* prog) {
  SAccessChain* opAccessChain = (SAccessChain*)op;
}

void HandleInBoundsAccessChain(void* op, Program* prog) {
  SInBoundsAccessChain* opInBoundsAccessChain = (SInBoundsAccessChain*)op;
}

void HandleSNegate(void* op, Program* prog) {
  SSNegate* opSNegate = (SSNegate*)op;
}

void HandleFNegate(void* op, Program* prog) {
  SFNegate* opFNegate = (SFNegate*)op;
}

void HandleNot(void* op, Program* prog) {
  SNot* opNot = (SNot*)op;
}

void HandleAny(void* op, Program* prog) {
  SAny* opAny = (SAny*)op;
}

void HandleAll(void* op, Program* prog) {
  SAll* opAll = (SAll*)op;
}

void HandleConvertFToU(void* op, Program* prog) {
  SConvertFToU* opConvertFToU = (SConvertFToU*)op;
}

void HandleConvertFToS(void* op, Program* prog) {
  SConvertFToS* opConvertFToS = (SConvertFToS*)op;
}

void HandleConvertSToF(void* op, Program* prog) {
  SConvertSToF* opConvertSToF = (SConvertSToF*)op;
}

void HandleConvertUToF(void* op, Program* prog) {
  SConvertUToF* opConvertUToF = (SConvertUToF*)op;
}

void HandleUConvert(void* op, Program* prog) {
  SUConvert* opUConvert = (SUConvert*)op;
}

void HandleSConvert(void* op, Program* prog) {
  SSConvert* opSConvert = (SSConvert*)op;
}

void HandleFConvert(void* op, Program* prog) {
  SFConvert* opFConvert = (SFConvert*)op;
}

void HandleConvertPtrToU(void* op, Program* prog) {
  SConvertPtrToU* opConvertPtrToU = (SConvertPtrToU*)op;
}

void HandleConvertUToPtr(void* op, Program* prog) {
  SConvertUToPtr* opConvertUToPtr = (SConvertUToPtr*)op;
}

void HandlePtrCastToGeneric(void* op, Program* prog) {
  SPtrCastToGeneric* opPtrCastToGeneric = (SPtrCastToGeneric*)op;
}

void HandleGenericCastToPtr(void* op, Program* prog) {
  SGenericCastToPtr* opGenericCastToPtr = (SGenericCastToPtr*)op;
}

void HandleBitcast(void* op, Program* prog) {
  SBitcast* opBitcast = (SBitcast*)op;
}

void HandleTranspose(void* op, Program* prog) {
  STranspose* opTranspose = (STranspose*)op;
}

void HandleIsNan(void* op, Program* prog) {
  SIsNan* opIsNan = (SIsNan*)op;
}

void HandleIsInf(void* op, Program* prog) {
  SIsInf* opIsInf = (SIsInf*)op;
}

void HandleIsFinite(void* op, Program* prog) {
  SIsFinite* opIsFinite = (SIsFinite*)op;
}

void HandleIsNormal(void* op, Program* prog) {
  SIsNormal* opIsNormal = (SIsNormal*)op;
}

void HandleSignBitSet(void* op, Program* prog) {
  SSignBitSet* opSignBitSet = (SSignBitSet*)op;
}

void HandleLessOrGreater(void* op, Program* prog) {
  SLessOrGreater* opLessOrGreater = (SLessOrGreater*)op;
}

void HandleOrdered(void* op, Program* prog) {
  SOrdered* opOrdered = (SOrdered*)op;
}

void HandleUnordered(void* op, Program* prog) {
  SUnordered* opUnordered = (SUnordered*)op;
}

void HandleArrayLength(void* op, Program* prog) {
  SArrayLength* opArrayLength = (SArrayLength*)op;
}

void HandleIAdd(void* op, Program* prog) {
  SIAdd* opIAdd = (SIAdd*)op;
}

void HandleFAdd(void* op, Program* prog) {
  SFAdd* opFAdd = (SFAdd*)op;
}

void HandleISub(void* op, Program* prog) {
  SISub* opISub = (SISub*)op;
}

void HandleFSub(void* op, Program* prog) {
  SFSub* opFSub = (SFSub*)op;
}

void HandleIMul(void* op, Program* prog) {
  SIMul* opIMul = (SIMul*)op;
}

void HandleFMul(void* op, Program* prog) {
  SFMul* opFMul = (SFMul*)op;
}

void HandleUDiv(void* op, Program* prog) {
  SUDiv* opUDiv = (SUDiv*)op;
}

void HandleSDiv(void* op, Program* prog) {
  SSDiv* opSDiv = (SSDiv*)op;
}

void HandleFDiv(void* op, Program* prog) {
  SFDiv* opFDiv = (SFDiv*)op;
}

void HandleUMod(void* op, Program* prog) {
  SUMod* opUMod = (SUMod*)op;
}

void HandleSRem(void* op, Program* prog) {
  SSRem* opSRem = (SSRem*)op;
}

void HandleSMod(void* op, Program* prog) {
  SSMod* opSMod = (SSMod*)op;
}

void HandleFRem(void* op, Program* prog) {
  SFRem* opFRem = (SFRem*)op;
}

void HandleFMod(void* op, Program* prog) {
  SFMod* opFMod = (SFMod*)op;
}

void HandleVectorTimesScalar(void* op, Program* prog) {
  SVectorTimesScalar* opVectorTimesScalar = (SVectorTimesScalar*)op;
}

void HandleMatrixTimesScalar(void* op, Program* prog) {
  SMatrixTimesScalar* opMatrixTimesScalar = (SMatrixTimesScalar*)op;
}

void HandleVectorTimesMatrix(void* op, Program* prog) {
  SVectorTimesMatrix* opVectorTimesMatrix = (SVectorTimesMatrix*)op;
}

void HandleMatrixTimesVector(void* op, Program* prog) {
  SMatrixTimesVector* opMatrixTimesVector = (SMatrixTimesVector*)op;
}

void HandleMatrixTimesMatrix(void* op, Program* prog) {
  SMatrixTimesMatrix* opMatrixTimesMatrix = (SMatrixTimesMatrix*)op;
}

void HandleOuterProduct(void* op, Program* prog) {
  SOuterProduct* opOuterProduct = (SOuterProduct*)op;
}

void HandleDot(void* op, Program* prog) {
  SDot* opDot = (SDot*)op;
}

void HandleShiftRightLogical(void* op, Program* prog) {
  SShiftRightLogical* opShiftRightLogical = (SShiftRightLogical*)op;
}

void HandleShiftRightArithmetic(void* op, Program* prog) {
  SShiftRightArithmetic* opShiftRightArithmetic = (SShiftRightArithmetic*)op;
}

void HandleShiftLeftLogical(void* op, Program* prog) {
  SShiftLeftLogical* opShiftLeftLogical = (SShiftLeftLogical*)op;
}

void HandleLogicalOr(void* op, Program* prog) {
  SLogicalOr* opLogicalOr = (SLogicalOr*)op;
}

void HandleLogicalXor(void* op, Program* prog) {
  SLogicalXor* opLogicalXor = (SLogicalXor*)op;
}

void HandleLogicalAnd(void* op, Program* prog) {
  SLogicalAnd* opLogicalAnd = (SLogicalAnd*)op;
}

void HandleBitwiseOr(void* op, Program* prog) {
  SBitwiseOr* opBitwiseOr = (SBitwiseOr*)op;
}

void HandleBitwiseXor(void* op, Program* prog) {
  SBitwiseXor* opBitwiseXor = (SBitwiseXor*)op;
}

void HandleBitwiseAnd(void* op, Program* prog) {
  SBitwiseAnd* opBitwiseAnd = (SBitwiseAnd*)op;
}

void HandleSelect(void* op, Program* prog) {
  SSelect* opSelect = (SSelect*)op;
}

void HandleIEqual(void* op, Program* prog) {
  SIEqual* opIEqual = (SIEqual*)op;
}

void HandleFOrdEqual(void* op, Program* prog) {
  SFOrdEqual* opFOrdEqual = (SFOrdEqual*)op;
}

void HandleFUnordEqual(void* op, Program* prog) {
  SFUnordEqual* opFUnordEqual = (SFUnordEqual*)op;
}

void HandleINotEqual(void* op, Program* prog) {
  SINotEqual* opINotEqual = (SINotEqual*)op;
}

void HandleFOrdNotEqual(void* op, Program* prog) {
  SFOrdNotEqual* opFOrdNotEqual = (SFOrdNotEqual*)op;
}

void HandleFUnordNotEqual(void* op, Program* prog) {
  SFUnordNotEqual* opFUnordNotEqual = (SFUnordNotEqual*)op;
}

void HandleULessThan(void* op, Program* prog) {
  SULessThan* opULessThan = (SULessThan*)op;
}

void HandleSLessThan(void* op, Program* prog) {
  SSLessThan* opSLessThan = (SSLessThan*)op;
}

void HandleFOrdLessThan(void* op, Program* prog) {
  SFOrdLessThan* opFOrdLessThan = (SFOrdLessThan*)op;
}

void HandleFUnordLessThan(void* op, Program* prog) {
  SFUnordLessThan* opFUnordLessThan = (SFUnordLessThan*)op;
}

void HandleUGreaterThan(void* op, Program* prog) {
  SUGreaterThan* opUGreaterThan = (SUGreaterThan*)op;
}

void HandleSGreaterThan(void* op, Program* prog) {
  SSGreaterThan* opSGreaterThan = (SSGreaterThan*)op;
}

void HandleFOrdGreaterThan(void* op, Program* prog) {
  SFOrdGreaterThan* opFOrdGreaterThan = (SFOrdGreaterThan*)op;
}

void HandleFUnordGreaterThan(void* op, Program* prog) {
  SFUnordGreaterThan* opFUnordGreaterThan = (SFUnordGreaterThan*)op;
}

void HandleULessThanEqual(void* op, Program* prog) {
  SULessThanEqual* opULessThanEqual = (SULessThanEqual*)op;
}

void HandleSLessThanEqual(void* op, Program* prog) {
  SSLessThanEqual* opSLessThanEqual = (SSLessThanEqual*)op;
}

void HandleFOrdLessThanEqual(void* op, Program* prog) {
  SFOrdLessThanEqual* opFOrdLessThanEqual = (SFOrdLessThanEqual*)op;
}

void HandleFUnordLessThanEqual(void* op, Program* prog) {
  SFUnordLessThanEqual* opFUnordLessThanEqual = (SFUnordLessThanEqual*)op;
}

void HandleUGreaterThanEqual(void* op, Program* prog) {
  SUGreaterThanEqual* opUGreaterThanEqual = (SUGreaterThanEqual*)op;
}

void HandleSGreaterThanEqual(void* op, Program* prog) {
  SSGreaterThanEqual* opSGreaterThanEqual = (SSGreaterThanEqual*)op;
}

void HandleFOrdGreaterThanEqual(void* op, Program* prog) {
  SFOrdGreaterThanEqual* opFOrdGreaterThanEqual = (SFOrdGreaterThanEqual*)op;
}

void HandleFUnordGreaterThanEqual(void* op, Program* prog) {
  SFUnordGreaterThanEqual* opFUnordGreaterThanEqual = (SFUnordGreaterThanEqual*)op;
}

void HandleDPdx(void* op, Program* prog) {
  SDPdx* opDPdx = (SDPdx*)op;
}

void HandleDPdy(void* op, Program* prog) {
  SDPdy* opDPdy = (SDPdy*)op;
}

void HandleFwidth(void* op, Program* prog) {
  SFwidth* opFwidth = (SFwidth*)op;
}

void HandleDPdxFine(void* op, Program* prog) {
  SDPdxFine* opDPdxFine = (SDPdxFine*)op;
}

void HandleDPdyFine(void* op, Program* prog) {
  SDPdyFine* opDPdyFine = (SDPdyFine*)op;
}

void HandleFwidthFine(void* op, Program* prog) {
  SFwidthFine* opFwidthFine = (SFwidthFine*)op;
}

void HandleDPdxCoarse(void* op, Program* prog) {
  SDPdxCoarse* opDPdxCoarse = (SDPdxCoarse*)op;
}

void HandleDPdyCoarse(void* op, Program* prog) {
  SDPdyCoarse* opDPdyCoarse = (SDPdyCoarse*)op;
}

void HandleFwidthCoarse(void* op, Program* prog) {
  SFwidthCoarse* opFwidthCoarse = (SFwidthCoarse*)op;
}

void HandleEmitVertex(void* op, Program* prog) {
  SEmitVertex* opEmitVertex = (SEmitVertex*)op;
}

void HandleEndPrimitive(void* op, Program* prog) {
  SEndPrimitive* opEndPrimitive = (SEndPrimitive*)op;
}

void HandleEmitStreamVertex(void* op, Program* prog) {
  SEmitStreamVertex* opEmitStreamVertex = (SEmitStreamVertex*)op;
}

void HandleEndStreamPrimitive(void* op, Program* prog) {
  SEndStreamPrimitive* opEndStreamPrimitive = (SEndStreamPrimitive*)op;
}

void HandleControlBarrier(void* op, Program* prog) {
  SControlBarrier* opControlBarrier = (SControlBarrier*)op;
}

void HandleMemoryBarrier(void* op, Program* prog) {
  SMemoryBarrier* opMemoryBarrier = (SMemoryBarrier*)op;
}

void HandleImagePointer(void* op, Program* prog) {
  SImagePointer* opImagePointer = (SImagePointer*)op;
}

void HandleAtomicInit(void* op, Program* prog) {
  SAtomicInit* opAtomicInit = (SAtomicInit*)op;
}

void HandleAtomicLoad(void* op, Program* prog) {
  SAtomicLoad* opAtomicLoad = (SAtomicLoad*)op;
}

void HandleAtomicStore(void* op, Program* prog) {
  SAtomicStore* opAtomicStore = (SAtomicStore*)op;
}

void HandleAtomicExchange(void* op, Program* prog) {
  SAtomicExchange* opAtomicExchange = (SAtomicExchange*)op;
}

void HandleAtomicCompareExchange(void* op, Program* prog) {
  SAtomicCompareExchange* opAtomicCompareExchange = (SAtomicCompareExchange*)op;
}

void HandleAtomicCompareExchangeWeak(void* op, Program* prog) {
  SAtomicCompareExchangeWeak* opAtomicCompareExchangeWeak = (SAtomicCompareExchangeWeak*)op;
}

void HandleAtomicIIncrement(void* op, Program* prog) {
  SAtomicIIncrement* opAtomicIIncrement = (SAtomicIIncrement*)op;
}

void HandleAtomicIDecrement(void* op, Program* prog) {
  SAtomicIDecrement* opAtomicIDecrement = (SAtomicIDecrement*)op;
}

void HandleAtomicIAdd(void* op, Program* prog) {
  SAtomicIAdd* opAtomicIAdd = (SAtomicIAdd*)op;
}

void HandleAtomicISub(void* op, Program* prog) {
  SAtomicISub* opAtomicISub = (SAtomicISub*)op;
}

void HandleAtomicUMin(void* op, Program* prog) {
  SAtomicUMin* opAtomicUMin = (SAtomicUMin*)op;
}

void HandleAtomicUMax(void* op, Program* prog) {
  SAtomicUMax* opAtomicUMax = (SAtomicUMax*)op;
}

void HandleAtomicAnd(void* op, Program* prog) {
  SAtomicAnd* opAtomicAnd = (SAtomicAnd*)op;
}

void HandleAtomicOr(void* op, Program* prog) {
  SAtomicOr* opAtomicOr = (SAtomicOr*)op;
}

void HandleAtomicXor(void* op, Program* prog) {
  SAtomicXor* opAtomicXor = (SAtomicXor*)op;
}

void HandleLoopMerge(void* op, Program* prog) {
  SLoopMerge* opLoopMerge = (SLoopMerge*)op;
  startLoop(prog, opLoopMerge);
}

void HandleSelectionMerge(void* op, Program* prog) {
  SSelectionMerge* opSelectionMerge = (SSelectionMerge*)op;
  startSelection(prog, opSelectionMerge);
}

void HandleLabel(void* op, Program* prog) {
  SLabel* opLabel = (SLabel*)op;
  startNewBlock(prog, *opLabel);
}

void HandleBranch(void* op, Program* prog) {
  SBranch* opBranch = (SBranch*)op;
  addOp(prog, SOp{ Op::OpBranch, opBranch });
  endBlock(prog, SOp{ Op::OpBranch, opBranch });
}

void HandleBranchConditional(void* op, Program* prog) {
  SBranchConditional* opBranchConditional = (SBranchConditional*)op;
  addOp(prog, SOp{ Op::OpBranchConditional, opBranchConditional });
  endBlock(prog, SOp{ Op::OpBranchConditional, opBranchConditional });
}

void HandleSwitch(void* op, Program* prog) {
  SSwitch* opSwitch = (SSwitch*)op;
  addOp(prog, SOp{ Op::OpSwitch, opSwitch });
  endBlock(prog, SOp{ Op::OpSwitch, opSwitch });
}

void HandleKill(void* op, Program* prog) {
  SKill* opKill = (SKill*)op;
  addOp(prog, SOp{ Op::OpKill, opKill });
  endBlock(prog, SOp{ Op::OpKill, opKill });
}

void HandleReturn(void* op, Program* prog) {
  SReturn* opReturn = (SReturn*)op;
  addOp(prog, SOp{ Op::OpReturn, opReturn });
  endBlock(prog, SOp{ Op::OpReturn, opReturn });
}

void HandleReturnValue(void* op, Program* prog) {
  SReturnValue* opReturnValue = (SReturnValue*)op;
  addOp(prog, SOp{ Op::OpReturnValue, opReturnValue });
  endBlock(prog, SOp{ Op::OpReturnValue, opReturnValue });
}

void HandleUnreachable(void* op, Program* prog) {
  SUnreachable* opUnreachable = (SUnreachable*)op;
  addOp(prog, SOp{ Op::OpUnreachable, opUnreachable });
  endBlock(prog, SOp{ Op::OpUnreachable, opUnreachable });
}

void HandleLifetimeStart(void* op, Program* prog) {
  SLifetimeStart* opLifetimeStart = (SLifetimeStart*)op;
}

void HandleLifetimeStop(void* op, Program* prog) {
  SLifetimeStop* opLifetimeStop = (SLifetimeStop*)op;
}

void HandleCompileFlag(void* op, Program* prog) {
  SCompileFlag* opCompileFlag = (SCompileFlag*)op;
  prog->CompileFlags.push_back(opCompileFlag->Flag);
}

void HandleAsyncGroupCopy(void* op, Program* prog) {
  SAsyncGroupCopy* opAsyncGroupCopy = (SAsyncGroupCopy*)op;
}

void HandleWaitGroupEvents(void* op, Program* prog) {
  SWaitGroupEvents* opWaitGroupEvents = (SWaitGroupEvents*)op;
}

void HandleGroupAll(void* op, Program* prog) {
  SGroupAll* opGroupAll = (SGroupAll*)op;
}

void HandleGroupAny(void* op, Program* prog) {
  SGroupAny* opGroupAny = (SGroupAny*)op;
}

void HandleGroupBroadcast(void* op, Program* prog) {
  SGroupBroadcast* opGroupBroadcast = (SGroupBroadcast*)op;
}

void HandleGroupIAdd(void* op, Program* prog) {
  SGroupIAdd* opGroupIAdd = (SGroupIAdd*)op;
}

void HandleGroupFAdd(void* op, Program* prog) {
  SGroupFAdd* opGroupFAdd = (SGroupFAdd*)op;
}

void HandleGroupFMin(void* op, Program* prog) {
  SGroupFMin* opGroupFMin = (SGroupFMin*)op;
}

void HandleGroupUMin(void* op, Program* prog) {
  SGroupUMin* opGroupUMin = (SGroupUMin*)op;
}

void HandleGroupSMin(void* op, Program* prog) {
  SGroupSMin* opGroupSMin = (SGroupSMin*)op;
}

void HandleGroupFMax(void* op, Program* prog) {
  SGroupFMax* opGroupFMax = (SGroupFMax*)op;
}

void HandleGroupUMax(void* op, Program* prog) {
  SGroupUMax* opGroupUMax = (SGroupUMax*)op;
}

void HandleGroupSMax(void* op, Program* prog) {
  SGroupSMax* opGroupSMax = (SGroupSMax*)op;
}

void HandleGenericCastToPtrExplicit(void* op, Program* prog) {
  SGenericCastToPtrExplicit* opGenericCastToPtrExplicit = (SGenericCastToPtrExplicit*)op;
}

void HandleGenericPtrMemSemantics(void* op, Program* prog) {
  SGenericPtrMemSemantics* opGenericPtrMemSemantics = (SGenericPtrMemSemantics*)op;
}

void HandleReadPipe(void* op, Program* prog) {
  SReadPipe* opReadPipe = (SReadPipe*)op;
}

void HandleWritePipe(void* op, Program* prog) {
  SWritePipe* opWritePipe = (SWritePipe*)op;
}

void HandleReservedReadPipe(void* op, Program* prog) {
  SReservedReadPipe* opReservedReadPipe = (SReservedReadPipe*)op;
}

void HandleReservedWritePipe(void* op, Program* prog) {
  SReservedWritePipe* opReservedWritePipe = (SReservedWritePipe*)op;
}

void HandleReserveReadPipePackets(void* op, Program* prog) {
  SReserveReadPipePackets* opReserveReadPipePackets = (SReserveReadPipePackets*)op;
}

void HandleReserveWritePipePackets(void* op, Program* prog) {
  SReserveWritePipePackets* opReserveWritePipePackets = (SReserveWritePipePackets*)op;
}

void HandleCommitReadPipe(void* op, Program* prog) {
  SCommitReadPipe* opCommitReadPipe = (SCommitReadPipe*)op;
}

void HandleCommitWritePipe(void* op, Program* prog) {
  SCommitWritePipe* opCommitWritePipe = (SCommitWritePipe*)op;
}

void HandleIsValidReserveId(void* op, Program* prog) {
  SIsValidReserveId* opIsValidReserveId = (SIsValidReserveId*)op;
}

void HandleGetNumPipePackets(void* op, Program* prog) {
  SGetNumPipePackets* opGetNumPipePackets = (SGetNumPipePackets*)op;
}

void HandleGetMaxPipePackets(void* op, Program* prog) {
  SGetMaxPipePackets* opGetMaxPipePackets = (SGetMaxPipePackets*)op;
}

void HandleGroupReserveReadPipePackets(void* op, Program* prog) {
  SGroupReserveReadPipePackets* opGroupReserveReadPipePackets = (SGroupReserveReadPipePackets*)op;
}

void HandleGroupReserveWritePipePackets(void* op, Program* prog) {
  SGroupReserveWritePipePackets* opGroupReserveWritePipePackets = (SGroupReserveWritePipePackets*)op;
}

void HandleGroupCommitReadPipe(void* op, Program* prog) {
  SGroupCommitReadPipe* opGroupCommitReadPipe = (SGroupCommitReadPipe*)op;
}

void HandleGroupCommitWritePipe(void* op, Program* prog) {
  SGroupCommitWritePipe* opGroupCommitWritePipe = (SGroupCommitWritePipe*)op;
}

void HandleEnqueueMarker(void* op, Program* prog) {
  SEnqueueMarker* opEnqueueMarker = (SEnqueueMarker*)op;
}

void HandleEnqueueKernel(void* op, Program* prog) {
  SEnqueueKernel* opEnqueueKernel = (SEnqueueKernel*)op;
}

void HandleGetKernelNDrangeSubGroupCount(void* op, Program* prog) {
  SGetKernelNDrangeSubGroupCount* opGetKernelNDrangeSubGroupCount = (SGetKernelNDrangeSubGroupCount*)op;
}

void HandleGetKernelNDrangeMaxSubGroupSize(void* op, Program* prog) {
  SGetKernelNDrangeMaxSubGroupSize* opGetKernelNDrangeMaxSubGroupSize = (SGetKernelNDrangeMaxSubGroupSize*)op;
}

void HandleGetKernelWorkGroupSize(void* op, Program* prog) {
  SGetKernelWorkGroupSize* opGetKernelWorkGroupSize = (SGetKernelWorkGroupSize*)op;
}

void HandleGetKernelPreferredWorkGroupSizeMultiple(void* op, Program* prog) {
  SGetKernelPreferredWorkGroupSizeMultiple* opGetKernelPreferredWorkGroupSizeMultiple = (SGetKernelPreferredWorkGroupSizeMultiple*)op;
}

void HandleRetainEvent(void* op, Program* prog) {
  SRetainEvent* opRetainEvent = (SRetainEvent*)op;
}

void HandleReleaseEvent(void* op, Program* prog) {
  SReleaseEvent* opReleaseEvent = (SReleaseEvent*)op;
}

void HandleCreateUserEvent(void* op, Program* prog) {
  SCreateUserEvent* opCreateUserEvent = (SCreateUserEvent*)op;
}

void HandleIsValidEvent(void* op, Program* prog) {
  SIsValidEvent* opIsValidEvent = (SIsValidEvent*)op;
}

void HandleSetUserEventStatus(void* op, Program* prog) {
  SSetUserEventStatus* opSetUserEventStatus = (SSetUserEventStatus*)op;
}

void HandleCaptureEventProfilingInfo(void* op, Program* prog) {
  SCaptureEventProfilingInfo* opCaptureEventProfilingInfo = (SCaptureEventProfilingInfo*)op;
}

void HandleGetDefaultQueue(void* op, Program* prog) {
  SGetDefaultQueue* opGetDefaultQueue = (SGetDefaultQueue*)op;
}

void HandleBuildNDRange(void* op, Program* prog) {
  SBuildNDRange* opBuildNDRange = (SBuildNDRange*)op;
}

void HandleSatConvertSToU(void* op, Program* prog) {
  SSatConvertSToU* opSatConvertSToU = (SSatConvertSToU*)op;
}

void HandleSatConvertUToS(void* op, Program* prog) {
  SSatConvertUToS* opSatConvertUToS = (SSatConvertUToS*)op;
}

void HandleAtomicIMin(void* op, Program* prog) {
  SAtomicIMin* opAtomicIMin = (SAtomicIMin*)op;
}

void HandleAtomicIMax(void* op, Program* prog) {
  SAtomicIMax* opAtomicIMax = (SAtomicIMax*)op;
}

void* LUTOpWordTypes[] = {
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

uint32 LUTOpWordTypesCount[] = {
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

OpHandler LUTHandlerMethods[]{
  HandleNop,
  HandleSource,
  HandleSourceExtension,
  HandleExtension,
  HandleExtInstImport,
  HandleMemoryModel,
  HandleEntryPoint,
  HandleExecutionMode,
  HandleTypeVoid,
  HandleTypeBool,
  HandleTypeInt,
  HandleTypeFloat,
  HandleTypeVector,
  HandleTypeMatrix,
  HandleTypeSampler,
  HandleTypeFilter,
  HandleTypeArray,
  HandleTypeRuntimeArray,
  HandleTypeStruct,
  HandleTypeOpaque,
  HandleTypePointer,
  HandleTypeFunction,
  HandleTypeEvent,
  HandleTypeDeviceEvent,
  HandleTypeReserveId,
  HandleTypeQueue,
  HandleTypePipe,
  HandleConstantTrue,
  HandleConstantFalse,
  HandleConstant,
  HandleConstantComposite,
  HandleConstantSampler,
  HandleConstantNullPointer,
  HandleConstantNullObject,
  HandleSpecConstantTrue,
  HandleSpecConstantFalse,
  HandleSpecConstant,
  HandleSpecConstantComposite,
  HandleVariable,
  HandleVariableArray,
  HandleFunction,
  HandleFunctionParameter,
  HandleFunctionEnd,
  HandleFunctionCall,
  HandleExtInst,
  HandleUndef,
  HandleLoad,
  HandleStore,
  HandlePhi,
  HandleDecorationGroup,
  HandleDecorate,
  HandleMemberDecorate,
  HandleGroupDecorate,
  HandleGroupMemberDecorate,
  HandleName,
  HandleMemberName,
  HandleString,
  HandleLine,
  HandleVectorExtractDynamic,
  HandleVectorInsertDynamic,
  HandleVectorShuffle,
  HandleCompositeConstruct,
  HandleCompositeExtract,
  HandleCompositeInsert,
  HandleCopyObject,
  HandleCopyMemory,
  HandleCopyMemorySized,
  HandleSampler,
  HandleTextureSample,
  HandleTextureSampleDref,
  HandleTextureSampleLod,
  HandleTextureSampleProj,
  HandleTextureSampleGrad,
  HandleTextureSampleOffset,
  HandleTextureSampleProjLod,
  HandleTextureSampleProjGrad,
  HandleTextureSampleLodOffset,
  HandleTextureSampleProjOffset,
  HandleTextureSampleGradOffset,
  HandleTextureSampleProjLodOffset,
  HandleTextureSampleProjGradOffset,
  HandleTextureFetchTexelLod,
  HandleTextureFetchTexelOffset,
  HandleTextureFetchSample,
  HandleTextureFetchTexel,
  HandleTextureGather,
  HandleTextureGatherOffset,
  HandleTextureGatherOffsets,
  HandleTextureQuerySizeLod,
  HandleTextureQuerySize,
  HandleTextureQueryLod,
  HandleTextureQueryLevels,
  HandleTextureQuerySamples,
  HandleAccessChain,
  HandleInBoundsAccessChain,
  HandleSNegate,
  HandleFNegate,
  HandleNot,
  HandleAny,
  HandleAll,
  HandleConvertFToU,
  HandleConvertFToS,
  HandleConvertSToF,
  HandleConvertUToF,
  HandleUConvert,
  HandleSConvert,
  HandleFConvert,
  HandleConvertPtrToU,
  HandleConvertUToPtr,
  HandlePtrCastToGeneric,
  HandleGenericCastToPtr,
  HandleBitcast,
  HandleTranspose,
  HandleIsNan,
  HandleIsInf,
  HandleIsFinite,
  HandleIsNormal,
  HandleSignBitSet,
  HandleLessOrGreater,
  HandleOrdered,
  HandleUnordered,
  HandleArrayLength,
  HandleIAdd,
  HandleFAdd,
  HandleISub,
  HandleFSub,
  HandleIMul,
  HandleFMul,
  HandleUDiv,
  HandleSDiv,
  HandleFDiv,
  HandleUMod,
  HandleSRem,
  HandleSMod,
  HandleFRem,
  HandleFMod,
  HandleVectorTimesScalar,
  HandleMatrixTimesScalar,
  HandleVectorTimesMatrix,
  HandleMatrixTimesVector,
  HandleMatrixTimesMatrix,
  HandleOuterProduct,
  HandleDot,
  HandleShiftRightLogical,
  HandleShiftRightArithmetic,
  HandleShiftLeftLogical,
  HandleLogicalOr,
  HandleLogicalXor,
  HandleLogicalAnd,
  HandleBitwiseOr,
  HandleBitwiseXor,
  HandleBitwiseAnd,
  HandleSelect,
  HandleIEqual,
  HandleFOrdEqual,
  HandleFUnordEqual,
  HandleINotEqual,
  HandleFOrdNotEqual,
  HandleFUnordNotEqual,
  HandleULessThan,
  HandleSLessThan,
  HandleFOrdLessThan,
  HandleFUnordLessThan,
  HandleUGreaterThan,
  HandleSGreaterThan,
  HandleFOrdGreaterThan,
  HandleFUnordGreaterThan,
  HandleULessThanEqual,
  HandleSLessThanEqual,
  HandleFOrdLessThanEqual,
  HandleFUnordLessThanEqual,
  HandleUGreaterThanEqual,
  HandleSGreaterThanEqual,
  HandleFOrdGreaterThanEqual,
  HandleFUnordGreaterThanEqual,
  HandleDPdx,
  HandleDPdy,
  HandleFwidth,
  HandleDPdxFine,
  HandleDPdyFine,
  HandleFwidthFine,
  HandleDPdxCoarse,
  HandleDPdyCoarse,
  HandleFwidthCoarse,
  HandleEmitVertex,
  HandleEndPrimitive,
  HandleEmitStreamVertex,
  HandleEndStreamPrimitive,
  HandleControlBarrier,
  HandleMemoryBarrier,
  HandleImagePointer,
  HandleAtomicInit,
  HandleAtomicLoad,
  HandleAtomicStore,
  HandleAtomicExchange,
  HandleAtomicCompareExchange,
  HandleAtomicCompareExchangeWeak,
  HandleAtomicIIncrement,
  HandleAtomicIDecrement,
  HandleAtomicIAdd,
  HandleAtomicISub,
  HandleAtomicUMin,
  HandleAtomicUMax,
  HandleAtomicAnd,
  HandleAtomicOr,
  HandleAtomicXor,
  HandleLoopMerge,
  HandleSelectionMerge,
  HandleLabel,
  HandleBranch,
  HandleBranchConditional,
  HandleSwitch,
  HandleKill,
  HandleReturn,
  HandleReturnValue,
  HandleUnreachable,
  HandleLifetimeStart,
  HandleLifetimeStop,
  HandleCompileFlag,
  HandleAsyncGroupCopy,
  HandleWaitGroupEvents,
  HandleGroupAll,
  HandleGroupAny,
  HandleGroupBroadcast,
  HandleGroupIAdd,
  HandleGroupFAdd,
  HandleGroupFMin,
  HandleGroupUMin,
  HandleGroupSMin,
  HandleGroupFMax,
  HandleGroupUMax,
  HandleGroupSMax,
  HandleGenericCastToPtrExplicit,
  HandleGenericPtrMemSemantics,
  HandleReadPipe,
  HandleWritePipe,
  HandleReservedReadPipe,
  HandleReservedWritePipe,
  HandleReserveReadPipePackets,
  HandleReserveWritePipePackets,
  HandleCommitReadPipe,
  HandleCommitWritePipe,
  HandleIsValidReserveId,
  HandleGetNumPipePackets,
  HandleGetMaxPipePackets,
  HandleGroupReserveReadPipePackets,
  HandleGroupReserveWritePipePackets,
  HandleGroupCommitReadPipe,
  HandleGroupCommitWritePipe,
  HandleEnqueueMarker,
  HandleEnqueueKernel,
  HandleGetKernelNDrangeSubGroupCount,
  HandleGetKernelNDrangeMaxSubGroupSize,
  HandleGetKernelWorkGroupSize,
  HandleGetKernelPreferredWorkGroupSizeMultiple,
  HandleRetainEvent,
  HandleReleaseEvent,
  HandleCreateUserEvent,
  HandleIsValidEvent,
  HandleSetUserEventStatus,
  HandleCaptureEventProfilingInfo,
  HandleGetDefaultQueue,
  HandleBuildNDRange,
  HandleSatConvertSToU,
  HandleSatConvertUToS,
  HandleAtomicIMin,
  HandleAtomicIMax,
};