#include "lookups_gen.h"
#include "parser_definitions.h"


void HandleNop(void* op, Program* prog) {
  SNop* opNop = (SNop*)op;
  assert(false);
}

void HandleUndef(void* op, Program* prog) {
  SUndef* opUndef = (SUndef*)op;
}

void HandleSource(void* op, Program* prog) {
  SSource* opSource = (SSource*)op;
  prog->SourceLanguage = *opSource;
}

void HandleSourceExtension(void* op, Program* prog) {
  SSourceExtension* opSourceExtension = (SSourceExtension*)op;
  prog->SourceExtensions.push_back(opSourceExtension->Extension);
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

void HandleExtension(void* op, Program* prog) {
  SExtension* opExtension = (SExtension*)op;
  prog->SPIRVExtensions.push_back(opExtension->Name);
}

void HandleExtInstImport(void* op, Program* prog) {
  SExtInstImport* opExtInstImport = (SExtInstImport*)op;
  prog->ExtensionImports.insert(std::pair<uint32, SExtInstImport>(opExtInstImport->ResultId, *opExtInstImport));
}

void HandleExtInst(void* op, Program* prog) {
  SExtInst* opExtInst = (SExtInst*)op;
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

void HandleCapability(void* op, Program* prog) {
  SCapability* opCapability = (SCapability*)op;
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

void HandleTypeImage(void* op, Program* prog) {
  STypeImage* opTypeImage = (STypeImage*)op;
  prog->DefinedTypes.insert(std::pair<uint32, SOp>(opTypeImage->ResultId, SOp{ Op::OpTypeImage, op }));
}

void HandleTypeSampler(void* op, Program* prog) {
  STypeSampler* opTypeSampler = (STypeSampler*)op;
  prog->DefinedTypes.insert(std::pair<uint32, SOp>(opTypeSampler->ResultId, SOp{ Op::OpTypeSampler, op }));
}

void HandleTypeSampledImage(void* op, Program* prog) {
  STypeSampledImage* opTypeSampledImage = (STypeSampledImage*)op;
  prog->DefinedTypes.insert(std::pair<uint32, SOp>(opTypeSampledImage->ResultId, SOp{ Op::OpTypeSampledImage, op }));
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

void HandleConstantNull(void* op, Program* prog) {
  SConstantNull* opConstantNull = (SConstantNull*)op;
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

void HandleSpecConstantOp(void* op, Program* prog) {
  SSpecConstantOp* opSpecConstantOp = (SSpecConstantOp*)op;
}

void HandleFunction(void* op, Program* prog) {
  SFunction* opFunction = (SFunction*)op;
  startFunction(prog, *opFunction);
}

void HandleFunctionParameter(void* op, Program* prog) {
  SFunctionParameter* opFunctionParameter = (SFunctionParameter*)op;
  prog->CurrentFunction->Parameters.push_back(*opFunctionParameter);
}

void HandleFunctionEnd(void* op, Program* prog) {
  SFunctionEnd* opFunctionEnd = (SFunctionEnd*)op;
  endFunction(prog);
}

void HandleFunctionCall(void* op, Program* prog) {
  SFunctionCall* opFunctionCall = (SFunctionCall*)op;
}

void HandleVariable(void* op, Program* prog) {
  SVariable* opVariable = (SVariable*)op;
}

void HandleImageTexelPointer(void* op, Program* prog) {
  SImageTexelPointer* opImageTexelPointer = (SImageTexelPointer*)op;
}

void HandleLoad(void* op, Program* prog) {
  SLoad* opLoad = (SLoad*)op;
}

void HandleStore(void* op, Program* prog) {
  SStore* opStore = (SStore*)op;
}

void HandleCopyMemory(void* op, Program* prog) {
  SCopyMemory* opCopyMemory = (SCopyMemory*)op;
}

void HandleCopyMemorySized(void* op, Program* prog) {
  SCopyMemorySized* opCopyMemorySized = (SCopyMemorySized*)op;
}

void HandleAccessChain(void* op, Program* prog) {
  SAccessChain* opAccessChain = (SAccessChain*)op;
}

void HandleInBoundsAccessChain(void* op, Program* prog) {
  SInBoundsAccessChain* opInBoundsAccessChain = (SInBoundsAccessChain*)op;
}

void HandlePtrAccessChain(void* op, Program* prog) {
  SPtrAccessChain* opPtrAccessChain = (SPtrAccessChain*)op;
}

void HandleArrayLength(void* op, Program* prog) {
  SArrayLength* opArrayLength = (SArrayLength*)op;
}

void HandleGenericPtrMemSemantics(void* op, Program* prog) {
  SGenericPtrMemSemantics* opGenericPtrMemSemantics = (SGenericPtrMemSemantics*)op;
}

void HandleDecorate(void* op, Program* prog) {
  SDecorate* opDecorate = (SDecorate*)op;
}

void HandleMemberDecorate(void* op, Program* prog) {
  SMemberDecorate* opMemberDecorate = (SMemberDecorate*)op;
}

void HandleDecorationGroup(void* op, Program* prog) {
  SDecorationGroup* opDecorationGroup = (SDecorationGroup*)op;
}

void HandleGroupDecorate(void* op, Program* prog) {
  SGroupDecorate* opGroupDecorate = (SGroupDecorate*)op;
}

void HandleGroupMemberDecorate(void* op, Program* prog) {
  SGroupMemberDecorate* opGroupMemberDecorate = (SGroupMemberDecorate*)op;
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

void HandleTranspose(void* op, Program* prog) {
  STranspose* opTranspose = (STranspose*)op;
}

void HandleSampledImage(void* op, Program* prog) {
  SSampledImage* opSampledImage = (SSampledImage*)op;
}

void HandleImageSampleImplicitLod(void* op, Program* prog) {
  SImageSampleImplicitLod* opImageSampleImplicitLod = (SImageSampleImplicitLod*)op;
}

void HandleImageSampleExplicitLod(void* op, Program* prog) {
  SImageSampleExplicitLod* opImageSampleExplicitLod = (SImageSampleExplicitLod*)op;
}

void HandleImageSampleDrefImplicitLod(void* op, Program* prog) {
  SImageSampleDrefImplicitLod* opImageSampleDrefImplicitLod = (SImageSampleDrefImplicitLod*)op;
}

void HandleImageSampleDrefExplicitLod(void* op, Program* prog) {
  SImageSampleDrefExplicitLod* opImageSampleDrefExplicitLod = (SImageSampleDrefExplicitLod*)op;
}

void HandleImageSampleProjImplicitLod(void* op, Program* prog) {
  SImageSampleProjImplicitLod* opImageSampleProjImplicitLod = (SImageSampleProjImplicitLod*)op;
}

void HandleImageSampleProjExplicitLod(void* op, Program* prog) {
  SImageSampleProjExplicitLod* opImageSampleProjExplicitLod = (SImageSampleProjExplicitLod*)op;
}

void HandleImageSampleProjDrefImplicitLod(void* op, Program* prog) {
  SImageSampleProjDrefImplicitLod* opImageSampleProjDrefImplicitLod = (SImageSampleProjDrefImplicitLod*)op;
}

void HandleImageSampleProjDrefExplicitLod(void* op, Program* prog) {
  SImageSampleProjDrefExplicitLod* opImageSampleProjDrefExplicitLod = (SImageSampleProjDrefExplicitLod*)op;
}

void HandleImageFetch(void* op, Program* prog) {
  SImageFetch* opImageFetch = (SImageFetch*)op;
}

void HandleImageGather(void* op, Program* prog) {
  SImageGather* opImageGather = (SImageGather*)op;
}

void HandleImageDrefGather(void* op, Program* prog) {
  SImageDrefGather* opImageDrefGather = (SImageDrefGather*)op;
}

void HandleImageRead(void* op, Program* prog) {
  SImageRead* opImageRead = (SImageRead*)op;
}

void HandleImageWrite(void* op, Program* prog) {
  SImageWrite* opImageWrite = (SImageWrite*)op;
}

void HandleImageQueryDim(void* op, Program* prog) {
  SImageQueryDim* opImageQueryDim = (SImageQueryDim*)op;
}

void HandleImageQueryFormat(void* op, Program* prog) {
  SImageQueryFormat* opImageQueryFormat = (SImageQueryFormat*)op;
}

void HandleImageQueryOrder(void* op, Program* prog) {
  SImageQueryOrder* opImageQueryOrder = (SImageQueryOrder*)op;
}

void HandleImageQuerySizeLod(void* op, Program* prog) {
  SImageQuerySizeLod* opImageQuerySizeLod = (SImageQuerySizeLod*)op;
}

void HandleImageQuerySize(void* op, Program* prog) {
  SImageQuerySize* opImageQuerySize = (SImageQuerySize*)op;
}

void HandleImageQueryLod(void* op, Program* prog) {
  SImageQueryLod* opImageQueryLod = (SImageQueryLod*)op;
}

void HandleImageQueryLevels(void* op, Program* prog) {
  SImageQueryLevels* opImageQueryLevels = (SImageQueryLevels*)op;
}

void HandleImageQuerySamples(void* op, Program* prog) {
  SImageQuerySamples* opImageQuerySamples = (SImageQuerySamples*)op;
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

void HandleQuantizeToF16(void* op, Program* prog) {
  SQuantizeToF16* opQuantizeToF16 = (SQuantizeToF16*)op;
}

void HandleConvertPtrToU(void* op, Program* prog) {
  SConvertPtrToU* opConvertPtrToU = (SConvertPtrToU*)op;
}

void HandleSatConvertSToU(void* op, Program* prog) {
  SSatConvertSToU* opSatConvertSToU = (SSatConvertSToU*)op;
}

void HandleSatConvertUToS(void* op, Program* prog) {
  SSatConvertUToS* opSatConvertUToS = (SSatConvertUToS*)op;
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

void HandleGenericCastToPtrExplicit(void* op, Program* prog) {
  SGenericCastToPtrExplicit* opGenericCastToPtrExplicit = (SGenericCastToPtrExplicit*)op;
}

void HandleBitcast(void* op, Program* prog) {
  SBitcast* opBitcast = (SBitcast*)op;
}

void HandleSNegate(void* op, Program* prog) {
  SSNegate* opSNegate = (SSNegate*)op;
}

void HandleFNegate(void* op, Program* prog) {
  SFNegate* opFNegate = (SFNegate*)op;
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

void HandleIAddCarry(void* op, Program* prog) {
  SIAddCarry* opIAddCarry = (SIAddCarry*)op;
}

void HandleISubBorrow(void* op, Program* prog) {
  SISubBorrow* opISubBorrow = (SISubBorrow*)op;
}

void HandleIMulExtended(void* op, Program* prog) {
  SIMulExtended* opIMulExtended = (SIMulExtended*)op;
}

void HandleAny(void* op, Program* prog) {
  SAny* opAny = (SAny*)op;
}

void HandleAll(void* op, Program* prog) {
  SAll* opAll = (SAll*)op;
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

void HandleLogicalEqual(void* op, Program* prog) {
  SLogicalEqual* opLogicalEqual = (SLogicalEqual*)op;
}

void HandleLogicalNotEqual(void* op, Program* prog) {
  SLogicalNotEqual* opLogicalNotEqual = (SLogicalNotEqual*)op;
}

void HandleLogicalOr(void* op, Program* prog) {
  SLogicalOr* opLogicalOr = (SLogicalOr*)op;
}

void HandleLogicalAnd(void* op, Program* prog) {
  SLogicalAnd* opLogicalAnd = (SLogicalAnd*)op;
}

void HandleLogicalNot(void* op, Program* prog) {
  SLogicalNot* opLogicalNot = (SLogicalNot*)op;
}

void HandleSelect(void* op, Program* prog) {
  SSelect* opSelect = (SSelect*)op;
}

void HandleIEqual(void* op, Program* prog) {
  SIEqual* opIEqual = (SIEqual*)op;
}

void HandleINotEqual(void* op, Program* prog) {
  SINotEqual* opINotEqual = (SINotEqual*)op;
}

void HandleUGreaterThan(void* op, Program* prog) {
  SUGreaterThan* opUGreaterThan = (SUGreaterThan*)op;
}

void HandleSGreaterThan(void* op, Program* prog) {
  SSGreaterThan* opSGreaterThan = (SSGreaterThan*)op;
}

void HandleUGreaterThanEqual(void* op, Program* prog) {
  SUGreaterThanEqual* opUGreaterThanEqual = (SUGreaterThanEqual*)op;
}

void HandleSGreaterThanEqual(void* op, Program* prog) {
  SSGreaterThanEqual* opSGreaterThanEqual = (SSGreaterThanEqual*)op;
}

void HandleULessThan(void* op, Program* prog) {
  SULessThan* opULessThan = (SULessThan*)op;
}

void HandleSLessThan(void* op, Program* prog) {
  SSLessThan* opSLessThan = (SSLessThan*)op;
}

void HandleULessThanEqual(void* op, Program* prog) {
  SULessThanEqual* opULessThanEqual = (SULessThanEqual*)op;
}

void HandleSLessThanEqual(void* op, Program* prog) {
  SSLessThanEqual* opSLessThanEqual = (SSLessThanEqual*)op;
}

void HandleFOrdEqual(void* op, Program* prog) {
  SFOrdEqual* opFOrdEqual = (SFOrdEqual*)op;
}

void HandleFUnordEqual(void* op, Program* prog) {
  SFUnordEqual* opFUnordEqual = (SFUnordEqual*)op;
}

void HandleFOrdNotEqual(void* op, Program* prog) {
  SFOrdNotEqual* opFOrdNotEqual = (SFOrdNotEqual*)op;
}

void HandleFUnordNotEqual(void* op, Program* prog) {
  SFUnordNotEqual* opFUnordNotEqual = (SFUnordNotEqual*)op;
}

void HandleFOrdLessThan(void* op, Program* prog) {
  SFOrdLessThan* opFOrdLessThan = (SFOrdLessThan*)op;
}

void HandleFUnordLessThan(void* op, Program* prog) {
  SFUnordLessThan* opFUnordLessThan = (SFUnordLessThan*)op;
}

void HandleFOrdGreaterThan(void* op, Program* prog) {
  SFOrdGreaterThan* opFOrdGreaterThan = (SFOrdGreaterThan*)op;
}

void HandleFUnordGreaterThan(void* op, Program* prog) {
  SFUnordGreaterThan* opFUnordGreaterThan = (SFUnordGreaterThan*)op;
}

void HandleFOrdLessThanEqual(void* op, Program* prog) {
  SFOrdLessThanEqual* opFOrdLessThanEqual = (SFOrdLessThanEqual*)op;
}

void HandleFUnordLessThanEqual(void* op, Program* prog) {
  SFUnordLessThanEqual* opFUnordLessThanEqual = (SFUnordLessThanEqual*)op;
}

void HandleFOrdGreaterThanEqual(void* op, Program* prog) {
  SFOrdGreaterThanEqual* opFOrdGreaterThanEqual = (SFOrdGreaterThanEqual*)op;
}

void HandleFUnordGreaterThanEqual(void* op, Program* prog) {
  SFUnordGreaterThanEqual* opFUnordGreaterThanEqual = (SFUnordGreaterThanEqual*)op;
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

void HandleBitwiseOr(void* op, Program* prog) {
  SBitwiseOr* opBitwiseOr = (SBitwiseOr*)op;
}

void HandleBitwiseXor(void* op, Program* prog) {
  SBitwiseXor* opBitwiseXor = (SBitwiseXor*)op;
}

void HandleBitwiseAnd(void* op, Program* prog) {
  SBitwiseAnd* opBitwiseAnd = (SBitwiseAnd*)op;
}

void HandleNot(void* op, Program* prog) {
  SNot* opNot = (SNot*)op;
}

void HandleBitFieldInsert(void* op, Program* prog) {
  SBitFieldInsert* opBitFieldInsert = (SBitFieldInsert*)op;
}

void HandleBitFieldSExtract(void* op, Program* prog) {
  SBitFieldSExtract* opBitFieldSExtract = (SBitFieldSExtract*)op;
}

void HandleBitFieldUExtract(void* op, Program* prog) {
  SBitFieldUExtract* opBitFieldUExtract = (SBitFieldUExtract*)op;
}

void HandleBitReverse(void* op, Program* prog) {
  SBitReverse* opBitReverse = (SBitReverse*)op;
}

void HandleBitCount(void* op, Program* prog) {
  SBitCount* opBitCount = (SBitCount*)op;
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

void HandleAtomicSMin(void* op, Program* prog) {
  SAtomicSMin* opAtomicSMin = (SAtomicSMin*)op;
}

void HandleAtomicUMin(void* op, Program* prog) {
  SAtomicUMin* opAtomicUMin = (SAtomicUMin*)op;
}

void HandleAtomicSMax(void* op, Program* prog) {
  SAtomicSMax* opAtomicSMax = (SAtomicSMax*)op;
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

void HandlePhi(void* op, Program* prog) {
  SPhi* opPhi = (SPhi*)op;
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
  addLabel(prog, opLabel);
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

WordType NopWordTypes[]{
  WordType::TOp,
};
uint32 NopWordTypesCount = 1;

WordType UndefWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
};
uint32 UndefWordTypesCount = 3;

WordType SourceWordTypes[]{
  WordType::TOp,
  WordType::TSourceLanguage,
  WordType::TLiteralNumber,
};
uint32 SourceWordTypesCount = 3;

WordType SourceExtensionWordTypes[]{
  WordType::TOp,
  WordType::TLiteralString,
};
uint32 SourceExtensionWordTypesCount = 2;

WordType NameWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TLiteralString,
};
uint32 NameWordTypesCount = 3;

WordType MemberNameWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TLiteralNumber,
  WordType::TLiteralString,
};
uint32 MemberNameWordTypesCount = 4;

WordType StringWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TLiteralString,
};
uint32 StringWordTypesCount = 3;

WordType LineWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TLiteralNumber,
  WordType::TLiteralNumber,
};
uint32 LineWordTypesCount = 5;

WordType ExtensionWordTypes[]{
  WordType::TOp,
  WordType::TLiteralString,
};
uint32 ExtensionWordTypesCount = 2;

WordType ExtInstImportWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TLiteralString,
};
uint32 ExtInstImportWordTypesCount = 3;

WordType ExtInstWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TLiteralNumber,
  WordType::TIdList,
};
uint32 ExtInstWordTypesCount = 6;

WordType MemoryModelWordTypes[]{
  WordType::TOp,
  WordType::TAddressingModel,
  WordType::TMemoryModel,
};
uint32 MemoryModelWordTypesCount = 3;

WordType EntryPointWordTypes[]{
  WordType::TOp,
  WordType::TExecutionModel,
  WordType::TId,
  WordType::TLiteralString,
};
uint32 EntryPointWordTypesCount = 4;

WordType ExecutionModeWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TExecutionMode,
  WordType::TLiteralNumberList,
};
uint32 ExecutionModeWordTypesCount = 4;

WordType CapabilityWordTypes[]{
  WordType::TOp,
  WordType::TCapability,
};
uint32 CapabilityWordTypesCount = 2;

WordType TypeVoidWordTypes[]{
  WordType::TOp,
  WordType::TId,
};
uint32 TypeVoidWordTypesCount = 2;

WordType TypeBoolWordTypes[]{
  WordType::TOp,
  WordType::TId,
};
uint32 TypeBoolWordTypesCount = 2;

WordType TypeIntWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TLiteralNumber,
  WordType::TLiteralNumber,
};
uint32 TypeIntWordTypesCount = 4;

WordType TypeFloatWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TLiteralNumber,
};
uint32 TypeFloatWordTypesCount = 3;

WordType TypeVectorWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TLiteralNumber,
};
uint32 TypeVectorWordTypesCount = 4;

WordType TypeMatrixWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TLiteralNumber,
};
uint32 TypeMatrixWordTypesCount = 4;

WordType TypeImageWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TDim,
  WordType::TLiteralNumber,
  WordType::TLiteralNumber,
  WordType::TLiteralNumber,
  WordType::TLiteralNumber,
  WordType::TImageFormat,
  WordType::TLiteralNumberList,
};
uint32 TypeImageWordTypesCount = 10;

WordType TypeSamplerWordTypes[]{
  WordType::TOp,
  WordType::TId,
};
uint32 TypeSamplerWordTypesCount = 2;

WordType TypeSampledImageWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
};
uint32 TypeSampledImageWordTypesCount = 3;

WordType TypeArrayWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 TypeArrayWordTypesCount = 4;

WordType TypeRuntimeArrayWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
};
uint32 TypeRuntimeArrayWordTypesCount = 3;

WordType TypeStructWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TIdList,
};
uint32 TypeStructWordTypesCount = 3;

WordType TypeOpaqueWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TLiteralString,
};
uint32 TypeOpaqueWordTypesCount = 3;

WordType TypePointerWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TStorageClass,
  WordType::TId,
};
uint32 TypePointerWordTypesCount = 4;

WordType TypeFunctionWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TIdList,
};
uint32 TypeFunctionWordTypesCount = 4;

WordType TypeEventWordTypes[]{
  WordType::TOp,
  WordType::TId,
};
uint32 TypeEventWordTypesCount = 2;

WordType TypeDeviceEventWordTypes[]{
  WordType::TOp,
  WordType::TId,
};
uint32 TypeDeviceEventWordTypesCount = 2;

WordType TypeReserveIdWordTypes[]{
  WordType::TOp,
  WordType::TId,
};
uint32 TypeReserveIdWordTypesCount = 2;

WordType TypeQueueWordTypes[]{
  WordType::TOp,
  WordType::TId,
};
uint32 TypeQueueWordTypesCount = 2;

WordType TypePipeWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TAccessQualifier,
};
uint32 TypePipeWordTypesCount = 4;

WordType ConstantTrueWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
};
uint32 ConstantTrueWordTypesCount = 3;

WordType ConstantFalseWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
};
uint32 ConstantFalseWordTypesCount = 3;

WordType ConstantWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TLiteralNumberList,
};
uint32 ConstantWordTypesCount = 4;

WordType ConstantCompositeWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TIdList,
};
uint32 ConstantCompositeWordTypesCount = 4;

WordType ConstantSamplerWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TSamplerAddressingMode,
  WordType::TLiteralNumber,
  WordType::TSamplerFilterMode,
};
uint32 ConstantSamplerWordTypesCount = 6;

WordType ConstantNullWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
};
uint32 ConstantNullWordTypesCount = 3;

WordType SpecConstantTrueWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
};
uint32 SpecConstantTrueWordTypesCount = 3;

WordType SpecConstantFalseWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
};
uint32 SpecConstantFalseWordTypesCount = 3;

WordType SpecConstantWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TLiteralNumberList,
};
uint32 SpecConstantWordTypesCount = 4;

WordType SpecConstantCompositeWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TIdList,
};
uint32 SpecConstantCompositeWordTypesCount = 4;

WordType SpecConstantOpWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TLiteralNumber,
  WordType::TIdList,
};
uint32 SpecConstantOpWordTypesCount = 5;

WordType FunctionWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TFunctionControl,
  WordType::TId,
};
uint32 FunctionWordTypesCount = 5;

WordType FunctionParameterWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
};
uint32 FunctionParameterWordTypesCount = 3;

WordType FunctionEndWordTypes[]{
  WordType::TOp,
};
uint32 FunctionEndWordTypesCount = 1;

WordType FunctionCallWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TIdList,
};
uint32 FunctionCallWordTypesCount = 5;

WordType VariableWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TStorageClass,
  WordType::TId,
};
uint32 VariableWordTypesCount = 5;

WordType ImageTexelPointerWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 ImageTexelPointerWordTypesCount = 6;

WordType LoadWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TLiteralNumberList,
};
uint32 LoadWordTypesCount = 5;

WordType StoreWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TLiteralNumberList,
};
uint32 StoreWordTypesCount = 4;

WordType CopyMemoryWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TLiteralNumberList,
};
uint32 CopyMemoryWordTypesCount = 4;

WordType CopyMemorySizedWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TLiteralNumberList,
};
uint32 CopyMemorySizedWordTypesCount = 5;

WordType AccessChainWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TIdList,
};
uint32 AccessChainWordTypesCount = 5;

WordType InBoundsAccessChainWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TIdList,
};
uint32 InBoundsAccessChainWordTypesCount = 5;

WordType PtrAccessChainWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TIdList,
};
uint32 PtrAccessChainWordTypesCount = 6;

WordType ArrayLengthWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TLiteralNumber,
};
uint32 ArrayLengthWordTypesCount = 5;

WordType GenericPtrMemSemanticsWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 GenericPtrMemSemanticsWordTypesCount = 4;

WordType DecorateWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TDecoration,
  WordType::TLiteralNumberList,
};
uint32 DecorateWordTypesCount = 4;

WordType MemberDecorateWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TLiteralNumber,
  WordType::TDecoration,
  WordType::TLiteralNumberList,
};
uint32 MemberDecorateWordTypesCount = 5;

WordType DecorationGroupWordTypes[]{
  WordType::TOp,
  WordType::TId,
};
uint32 DecorationGroupWordTypesCount = 2;

WordType GroupDecorateWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TIdList,
};
uint32 GroupDecorateWordTypesCount = 3;

WordType GroupMemberDecorateWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TIdList,
};
uint32 GroupMemberDecorateWordTypesCount = 3;

WordType VectorExtractDynamicWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 VectorExtractDynamicWordTypesCount = 5;

WordType VectorInsertDynamicWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 VectorInsertDynamicWordTypesCount = 6;

WordType VectorShuffleWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TLiteralNumberList,
};
uint32 VectorShuffleWordTypesCount = 6;

WordType CompositeConstructWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TIdList,
};
uint32 CompositeConstructWordTypesCount = 4;

WordType CompositeExtractWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TLiteralNumberList,
};
uint32 CompositeExtractWordTypesCount = 5;

WordType CompositeInsertWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TLiteralNumberList,
};
uint32 CompositeInsertWordTypesCount = 6;

WordType CopyObjectWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 CopyObjectWordTypesCount = 4;

WordType TransposeWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 TransposeWordTypesCount = 4;

WordType SampledImageWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 SampledImageWordTypesCount = 5;

WordType ImageSampleImplicitLodWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TIdList,
};
uint32 ImageSampleImplicitLodWordTypesCount = 6;

WordType ImageSampleExplicitLodWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TIdList,
};
uint32 ImageSampleExplicitLodWordTypesCount = 6;

WordType ImageSampleDrefImplicitLodWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TIdList,
};
uint32 ImageSampleDrefImplicitLodWordTypesCount = 7;

WordType ImageSampleDrefExplicitLodWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TIdList,
};
uint32 ImageSampleDrefExplicitLodWordTypesCount = 7;

WordType ImageSampleProjImplicitLodWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TIdList,
};
uint32 ImageSampleProjImplicitLodWordTypesCount = 6;

WordType ImageSampleProjExplicitLodWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TIdList,
};
uint32 ImageSampleProjExplicitLodWordTypesCount = 6;

WordType ImageSampleProjDrefImplicitLodWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TIdList,
};
uint32 ImageSampleProjDrefImplicitLodWordTypesCount = 7;

WordType ImageSampleProjDrefExplicitLodWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TIdList,
};
uint32 ImageSampleProjDrefExplicitLodWordTypesCount = 7;

WordType ImageFetchWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TIdList,
};
uint32 ImageFetchWordTypesCount = 6;

WordType ImageGatherWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TIdList,
};
uint32 ImageGatherWordTypesCount = 7;

WordType ImageDrefGatherWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TIdList,
};
uint32 ImageDrefGatherWordTypesCount = 7;

WordType ImageReadWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 ImageReadWordTypesCount = 5;

WordType ImageWriteWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 ImageWriteWordTypesCount = 4;

WordType ImageQueryDimWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 ImageQueryDimWordTypesCount = 4;

WordType ImageQueryFormatWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 ImageQueryFormatWordTypesCount = 4;

WordType ImageQueryOrderWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 ImageQueryOrderWordTypesCount = 4;

WordType ImageQuerySizeLodWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 ImageQuerySizeLodWordTypesCount = 5;

WordType ImageQuerySizeWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 ImageQuerySizeWordTypesCount = 4;

WordType ImageQueryLodWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 ImageQueryLodWordTypesCount = 5;

WordType ImageQueryLevelsWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 ImageQueryLevelsWordTypesCount = 4;

WordType ImageQuerySamplesWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 ImageQuerySamplesWordTypesCount = 4;

WordType ConvertFToUWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 ConvertFToUWordTypesCount = 4;

WordType ConvertFToSWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 ConvertFToSWordTypesCount = 4;

WordType ConvertSToFWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 ConvertSToFWordTypesCount = 4;

WordType ConvertUToFWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 ConvertUToFWordTypesCount = 4;

WordType UConvertWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 UConvertWordTypesCount = 4;

WordType SConvertWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 SConvertWordTypesCount = 4;

WordType FConvertWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 FConvertWordTypesCount = 4;

WordType QuantizeToF16WordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 QuantizeToF16WordTypesCount = 4;

WordType ConvertPtrToUWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 ConvertPtrToUWordTypesCount = 4;

WordType SatConvertSToUWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 SatConvertSToUWordTypesCount = 4;

WordType SatConvertUToSWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 SatConvertUToSWordTypesCount = 4;

WordType ConvertUToPtrWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 ConvertUToPtrWordTypesCount = 4;

WordType PtrCastToGenericWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 PtrCastToGenericWordTypesCount = 4;

WordType GenericCastToPtrWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 GenericCastToPtrWordTypesCount = 4;

WordType GenericCastToPtrExplicitWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TStorageClass,
};
uint32 GenericCastToPtrExplicitWordTypesCount = 5;

WordType BitcastWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 BitcastWordTypesCount = 4;

WordType SNegateWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 SNegateWordTypesCount = 4;

WordType FNegateWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 FNegateWordTypesCount = 4;

WordType IAddWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 IAddWordTypesCount = 5;

WordType FAddWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 FAddWordTypesCount = 5;

WordType ISubWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 ISubWordTypesCount = 5;

WordType FSubWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 FSubWordTypesCount = 5;

WordType IMulWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 IMulWordTypesCount = 5;

WordType FMulWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 FMulWordTypesCount = 5;

WordType UDivWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 UDivWordTypesCount = 5;

WordType SDivWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 SDivWordTypesCount = 5;

WordType FDivWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 FDivWordTypesCount = 5;

WordType UModWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 UModWordTypesCount = 5;

WordType SRemWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 SRemWordTypesCount = 5;

WordType SModWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 SModWordTypesCount = 5;

WordType FRemWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 FRemWordTypesCount = 5;

WordType FModWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 FModWordTypesCount = 5;

WordType VectorTimesScalarWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 VectorTimesScalarWordTypesCount = 5;

WordType MatrixTimesScalarWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 MatrixTimesScalarWordTypesCount = 5;

WordType VectorTimesMatrixWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 VectorTimesMatrixWordTypesCount = 5;

WordType MatrixTimesVectorWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 MatrixTimesVectorWordTypesCount = 5;

WordType MatrixTimesMatrixWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 MatrixTimesMatrixWordTypesCount = 5;

WordType OuterProductWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 OuterProductWordTypesCount = 5;

WordType DotWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 DotWordTypesCount = 5;

WordType IAddCarryWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
};
uint32 IAddCarryWordTypesCount = 3;

WordType ISubBorrowWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
};
uint32 ISubBorrowWordTypesCount = 3;

WordType IMulExtendedWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
};
uint32 IMulExtendedWordTypesCount = 3;

WordType AnyWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 AnyWordTypesCount = 4;

WordType AllWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 AllWordTypesCount = 4;

WordType IsNanWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 IsNanWordTypesCount = 4;

WordType IsInfWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 IsInfWordTypesCount = 4;

WordType IsFiniteWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 IsFiniteWordTypesCount = 4;

WordType IsNormalWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 IsNormalWordTypesCount = 4;

WordType SignBitSetWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 SignBitSetWordTypesCount = 4;

WordType LessOrGreaterWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 LessOrGreaterWordTypesCount = 5;

WordType OrderedWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 OrderedWordTypesCount = 5;

WordType UnorderedWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 UnorderedWordTypesCount = 5;

WordType LogicalEqualWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 LogicalEqualWordTypesCount = 5;

WordType LogicalNotEqualWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 LogicalNotEqualWordTypesCount = 5;

WordType LogicalOrWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 LogicalOrWordTypesCount = 5;

WordType LogicalAndWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 LogicalAndWordTypesCount = 5;

WordType LogicalNotWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 LogicalNotWordTypesCount = 4;

WordType SelectWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 SelectWordTypesCount = 6;

WordType IEqualWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 IEqualWordTypesCount = 5;

WordType INotEqualWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 INotEqualWordTypesCount = 5;

WordType UGreaterThanWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 UGreaterThanWordTypesCount = 5;

WordType SGreaterThanWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 SGreaterThanWordTypesCount = 5;

WordType UGreaterThanEqualWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 UGreaterThanEqualWordTypesCount = 5;

WordType SGreaterThanEqualWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 SGreaterThanEqualWordTypesCount = 5;

WordType ULessThanWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 ULessThanWordTypesCount = 5;

WordType SLessThanWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 SLessThanWordTypesCount = 5;

WordType ULessThanEqualWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 ULessThanEqualWordTypesCount = 5;

WordType SLessThanEqualWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 SLessThanEqualWordTypesCount = 5;

WordType FOrdEqualWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 FOrdEqualWordTypesCount = 5;

WordType FUnordEqualWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 FUnordEqualWordTypesCount = 5;

WordType FOrdNotEqualWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 FOrdNotEqualWordTypesCount = 5;

WordType FUnordNotEqualWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 FUnordNotEqualWordTypesCount = 5;

WordType FOrdLessThanWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 FOrdLessThanWordTypesCount = 5;

WordType FUnordLessThanWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 FUnordLessThanWordTypesCount = 5;

WordType FOrdGreaterThanWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 FOrdGreaterThanWordTypesCount = 5;

WordType FUnordGreaterThanWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 FUnordGreaterThanWordTypesCount = 5;

WordType FOrdLessThanEqualWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 FOrdLessThanEqualWordTypesCount = 5;

WordType FUnordLessThanEqualWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 FUnordLessThanEqualWordTypesCount = 5;

WordType FOrdGreaterThanEqualWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 FOrdGreaterThanEqualWordTypesCount = 5;

WordType FUnordGreaterThanEqualWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 FUnordGreaterThanEqualWordTypesCount = 5;

WordType ShiftRightLogicalWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 ShiftRightLogicalWordTypesCount = 5;

WordType ShiftRightArithmeticWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 ShiftRightArithmeticWordTypesCount = 5;

WordType ShiftLeftLogicalWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 ShiftLeftLogicalWordTypesCount = 5;

WordType BitwiseOrWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 BitwiseOrWordTypesCount = 5;

WordType BitwiseXorWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 BitwiseXorWordTypesCount = 5;

WordType BitwiseAndWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 BitwiseAndWordTypesCount = 5;

WordType NotWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 NotWordTypesCount = 4;

WordType BitFieldInsertWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 BitFieldInsertWordTypesCount = 7;

WordType BitFieldSExtractWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 BitFieldSExtractWordTypesCount = 6;

WordType BitFieldUExtractWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 BitFieldUExtractWordTypesCount = 6;

WordType BitReverseWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 BitReverseWordTypesCount = 4;

WordType BitCountWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 BitCountWordTypesCount = 4;

WordType DPdxWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 DPdxWordTypesCount = 4;

WordType DPdyWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 DPdyWordTypesCount = 4;

WordType FwidthWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 FwidthWordTypesCount = 4;

WordType DPdxFineWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 DPdxFineWordTypesCount = 4;

WordType DPdyFineWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 DPdyFineWordTypesCount = 4;

WordType FwidthFineWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 FwidthFineWordTypesCount = 4;

WordType DPdxCoarseWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 DPdxCoarseWordTypesCount = 4;

WordType DPdyCoarseWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 DPdyCoarseWordTypesCount = 4;

WordType FwidthCoarseWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 FwidthCoarseWordTypesCount = 4;

WordType EmitVertexWordTypes[]{
  WordType::TOp,
};
uint32 EmitVertexWordTypesCount = 1;

WordType EndPrimitiveWordTypes[]{
  WordType::TOp,
};
uint32 EndPrimitiveWordTypesCount = 1;

WordType EmitStreamVertexWordTypes[]{
  WordType::TOp,
  WordType::TId,
};
uint32 EmitStreamVertexWordTypesCount = 2;

WordType EndStreamPrimitiveWordTypes[]{
  WordType::TOp,
  WordType::TId,
};
uint32 EndStreamPrimitiveWordTypesCount = 2;

WordType ControlBarrierWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 ControlBarrierWordTypesCount = 4;

WordType MemoryBarrierWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
};
uint32 MemoryBarrierWordTypesCount = 3;

WordType AtomicLoadWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 AtomicLoadWordTypesCount = 6;

WordType AtomicStoreWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 AtomicStoreWordTypesCount = 5;

WordType AtomicExchangeWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 AtomicExchangeWordTypesCount = 7;

WordType AtomicCompareExchangeWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 AtomicCompareExchangeWordTypesCount = 9;

WordType AtomicCompareExchangeWeakWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 AtomicCompareExchangeWeakWordTypesCount = 9;

WordType AtomicIIncrementWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 AtomicIIncrementWordTypesCount = 6;

WordType AtomicIDecrementWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 AtomicIDecrementWordTypesCount = 6;

WordType AtomicIAddWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 AtomicIAddWordTypesCount = 7;

WordType AtomicISubWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 AtomicISubWordTypesCount = 7;

WordType AtomicSMinWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 AtomicSMinWordTypesCount = 7;

WordType AtomicUMinWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 AtomicUMinWordTypesCount = 7;

WordType AtomicSMaxWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 AtomicSMaxWordTypesCount = 7;

WordType AtomicUMaxWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 AtomicUMaxWordTypesCount = 7;

WordType AtomicAndWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 AtomicAndWordTypesCount = 7;

WordType AtomicOrWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 AtomicOrWordTypesCount = 7;

WordType AtomicXorWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 AtomicXorWordTypesCount = 7;

WordType PhiWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TIdList,
};
uint32 PhiWordTypesCount = 4;

WordType LoopMergeWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TLoopControl,
};
uint32 LoopMergeWordTypesCount = 3;

WordType SelectionMergeWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TSelectionControl,
};
uint32 SelectionMergeWordTypesCount = 3;

WordType LabelWordTypes[]{
  WordType::TOp,
  WordType::TId,
};
uint32 LabelWordTypesCount = 2;

WordType BranchWordTypes[]{
  WordType::TOp,
  WordType::TId,
};
uint32 BranchWordTypesCount = 2;

WordType BranchConditionalWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TLiteralNumberList,
};
uint32 BranchConditionalWordTypesCount = 5;

WordType SwitchWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TIdList,
};
uint32 SwitchWordTypesCount = 4;

WordType KillWordTypes[]{
  WordType::TOp,
};
uint32 KillWordTypesCount = 1;

WordType ReturnWordTypes[]{
  WordType::TOp,
};
uint32 ReturnWordTypesCount = 1;

WordType ReturnValueWordTypes[]{
  WordType::TOp,
  WordType::TId,
};
uint32 ReturnValueWordTypesCount = 2;

WordType UnreachableWordTypes[]{
  WordType::TOp,
};
uint32 UnreachableWordTypesCount = 1;

WordType LifetimeStartWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TLiteralNumber,
};
uint32 LifetimeStartWordTypesCount = 3;

WordType LifetimeStopWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TLiteralNumber,
};
uint32 LifetimeStopWordTypesCount = 3;

WordType AsyncGroupCopyWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 AsyncGroupCopyWordTypesCount = 9;

WordType WaitGroupEventsWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 WaitGroupEventsWordTypesCount = 4;

WordType GroupAllWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 GroupAllWordTypesCount = 5;

WordType GroupAnyWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 GroupAnyWordTypesCount = 5;

WordType GroupBroadcastWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 GroupBroadcastWordTypesCount = 6;

WordType GroupIAddWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TGroupOperation,
  WordType::TId,
};
uint32 GroupIAddWordTypesCount = 6;

WordType GroupFAddWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TGroupOperation,
  WordType::TId,
};
uint32 GroupFAddWordTypesCount = 6;

WordType GroupFMinWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TGroupOperation,
  WordType::TId,
};
uint32 GroupFMinWordTypesCount = 6;

WordType GroupUMinWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TGroupOperation,
  WordType::TId,
};
uint32 GroupUMinWordTypesCount = 6;

WordType GroupSMinWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TGroupOperation,
  WordType::TId,
};
uint32 GroupSMinWordTypesCount = 6;

WordType GroupFMaxWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TGroupOperation,
  WordType::TId,
};
uint32 GroupFMaxWordTypesCount = 6;

WordType GroupUMaxWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TGroupOperation,
  WordType::TId,
};
uint32 GroupUMaxWordTypesCount = 6;

WordType GroupSMaxWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TGroupOperation,
  WordType::TId,
};
uint32 GroupSMaxWordTypesCount = 6;

WordType ReadPipeWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 ReadPipeWordTypesCount = 5;

WordType WritePipeWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 WritePipeWordTypesCount = 5;

WordType ReservedReadPipeWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 ReservedReadPipeWordTypesCount = 7;

WordType ReservedWritePipeWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 ReservedWritePipeWordTypesCount = 7;

WordType ReserveReadPipePacketsWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 ReserveReadPipePacketsWordTypesCount = 5;

WordType ReserveWritePipePacketsWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 ReserveWritePipePacketsWordTypesCount = 5;

WordType CommitReadPipeWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
};
uint32 CommitReadPipeWordTypesCount = 3;

WordType CommitWritePipeWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
};
uint32 CommitWritePipeWordTypesCount = 3;

WordType IsValidReserveIdWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 IsValidReserveIdWordTypesCount = 4;

WordType GetNumPipePacketsWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 GetNumPipePacketsWordTypesCount = 4;

WordType GetMaxPipePacketsWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 GetMaxPipePacketsWordTypesCount = 4;

WordType GroupReserveReadPipePacketsWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 GroupReserveReadPipePacketsWordTypesCount = 6;

WordType GroupReserveWritePipePacketsWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 GroupReserveWritePipePacketsWordTypesCount = 6;

WordType GroupCommitReadPipeWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 GroupCommitReadPipeWordTypesCount = 4;

WordType GroupCommitWritePipeWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 GroupCommitWritePipeWordTypesCount = 4;

WordType EnqueueMarkerWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 EnqueueMarkerWordTypesCount = 7;

WordType EnqueueKernelWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
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
uint32 EnqueueKernelWordTypesCount = 14;

WordType GetKernelNDrangeSubGroupCountWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 GetKernelNDrangeSubGroupCountWordTypesCount = 8;

WordType GetKernelNDrangeMaxSubGroupSizeWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 GetKernelNDrangeMaxSubGroupSizeWordTypesCount = 8;

WordType GetKernelWorkGroupSizeWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 GetKernelWorkGroupSizeWordTypesCount = 7;

WordType GetKernelPreferredWorkGroupSizeMultipleWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 GetKernelPreferredWorkGroupSizeMultipleWordTypesCount = 7;

WordType RetainEventWordTypes[]{
  WordType::TOp,
  WordType::TId,
};
uint32 RetainEventWordTypesCount = 2;

WordType ReleaseEventWordTypes[]{
  WordType::TOp,
  WordType::TId,
};
uint32 ReleaseEventWordTypesCount = 2;

WordType CreateUserEventWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
};
uint32 CreateUserEventWordTypesCount = 3;

WordType IsValidEventWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 IsValidEventWordTypesCount = 4;

WordType SetUserEventStatusWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
};
uint32 SetUserEventStatusWordTypesCount = 3;

WordType CaptureEventProfilingInfoWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 CaptureEventProfilingInfoWordTypesCount = 4;

WordType GetDefaultQueueWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
};
uint32 GetDefaultQueueWordTypesCount = 3;

WordType BuildNDRangeWordTypes[]{
  WordType::TOp,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
  WordType::TId,
};
uint32 BuildNDRangeWordTypesCount = 6;

void* LUTOpWordTypes[]{
  &NopWordTypes,
  &UndefWordTypes,
  nullptr,
  &SourceWordTypes,
  &SourceExtensionWordTypes,
  &NameWordTypes,
  &MemberNameWordTypes,
  &StringWordTypes,
  &LineWordTypes,
  nullptr,
  &ExtensionWordTypes,
  &ExtInstImportWordTypes,
  &ExtInstWordTypes,
  nullptr,
  &MemoryModelWordTypes,
  &EntryPointWordTypes,
  &ExecutionModeWordTypes,
  &CapabilityWordTypes,
  nullptr,
  &TypeVoidWordTypes,
  &TypeBoolWordTypes,
  &TypeIntWordTypes,
  &TypeFloatWordTypes,
  &TypeVectorWordTypes,
  &TypeMatrixWordTypes,
  &TypeImageWordTypes,
  &TypeSamplerWordTypes,
  &TypeSampledImageWordTypes,
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
  nullptr,
  nullptr,
  &ConstantTrueWordTypes,
  &ConstantFalseWordTypes,
  &ConstantWordTypes,
  &ConstantCompositeWordTypes,
  &ConstantSamplerWordTypes,
  &ConstantNullWordTypes,
  &SpecConstantTrueWordTypes,
  &SpecConstantFalseWordTypes,
  &SpecConstantWordTypes,
  &SpecConstantCompositeWordTypes,
  &SpecConstantOpWordTypes,
  nullptr,
  &FunctionWordTypes,
  &FunctionParameterWordTypes,
  &FunctionEndWordTypes,
  &FunctionCallWordTypes,
  nullptr,
  &VariableWordTypes,
  &ImageTexelPointerWordTypes,
  &LoadWordTypes,
  &StoreWordTypes,
  &CopyMemoryWordTypes,
  &CopyMemorySizedWordTypes,
  &AccessChainWordTypes,
  &InBoundsAccessChainWordTypes,
  &PtrAccessChainWordTypes,
  &ArrayLengthWordTypes,
  &GenericPtrMemSemanticsWordTypes,
  nullptr,
  &DecorateWordTypes,
  &MemberDecorateWordTypes,
  &DecorationGroupWordTypes,
  &GroupDecorateWordTypes,
  &GroupMemberDecorateWordTypes,
  nullptr,
  &VectorExtractDynamicWordTypes,
  &VectorInsertDynamicWordTypes,
  &VectorShuffleWordTypes,
  &CompositeConstructWordTypes,
  &CompositeExtractWordTypes,
  &CompositeInsertWordTypes,
  &CopyObjectWordTypes,
  &TransposeWordTypes,
  nullptr,
  &SampledImageWordTypes,
  &ImageSampleImplicitLodWordTypes,
  &ImageSampleExplicitLodWordTypes,
  &ImageSampleDrefImplicitLodWordTypes,
  &ImageSampleDrefExplicitLodWordTypes,
  &ImageSampleProjImplicitLodWordTypes,
  &ImageSampleProjExplicitLodWordTypes,
  &ImageSampleProjDrefImplicitLodWordTypes,
  &ImageSampleProjDrefExplicitLodWordTypes,
  &ImageFetchWordTypes,
  &ImageGatherWordTypes,
  &ImageDrefGatherWordTypes,
  &ImageReadWordTypes,
  &ImageWriteWordTypes,
  &ImageQueryDimWordTypes,
  &ImageQueryFormatWordTypes,
  &ImageQueryOrderWordTypes,
  &ImageQuerySizeLodWordTypes,
  &ImageQuerySizeWordTypes,
  &ImageQueryLodWordTypes,
  &ImageQueryLevelsWordTypes,
  &ImageQuerySamplesWordTypes,
  nullptr,
  &ConvertFToUWordTypes,
  &ConvertFToSWordTypes,
  &ConvertSToFWordTypes,
  &ConvertUToFWordTypes,
  &UConvertWordTypes,
  &SConvertWordTypes,
  &FConvertWordTypes,
  &QuantizeToF16WordTypes,
  &ConvertPtrToUWordTypes,
  &SatConvertSToUWordTypes,
  &SatConvertUToSWordTypes,
  &ConvertUToPtrWordTypes,
  &PtrCastToGenericWordTypes,
  &GenericCastToPtrWordTypes,
  &GenericCastToPtrExplicitWordTypes,
  &BitcastWordTypes,
  nullptr,
  &SNegateWordTypes,
  &FNegateWordTypes,
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
  &IAddCarryWordTypes,
  &ISubBorrowWordTypes,
  &IMulExtendedWordTypes,
  nullptr,
  nullptr,
  &AnyWordTypes,
  &AllWordTypes,
  &IsNanWordTypes,
  &IsInfWordTypes,
  &IsFiniteWordTypes,
  &IsNormalWordTypes,
  &SignBitSetWordTypes,
  &LessOrGreaterWordTypes,
  &OrderedWordTypes,
  &UnorderedWordTypes,
  &LogicalEqualWordTypes,
  &LogicalNotEqualWordTypes,
  &LogicalOrWordTypes,
  &LogicalAndWordTypes,
  &LogicalNotWordTypes,
  &SelectWordTypes,
  &IEqualWordTypes,
  &INotEqualWordTypes,
  &UGreaterThanWordTypes,
  &SGreaterThanWordTypes,
  &UGreaterThanEqualWordTypes,
  &SGreaterThanEqualWordTypes,
  &ULessThanWordTypes,
  &SLessThanWordTypes,
  &ULessThanEqualWordTypes,
  &SLessThanEqualWordTypes,
  &FOrdEqualWordTypes,
  &FUnordEqualWordTypes,
  &FOrdNotEqualWordTypes,
  &FUnordNotEqualWordTypes,
  &FOrdLessThanWordTypes,
  &FUnordLessThanWordTypes,
  &FOrdGreaterThanWordTypes,
  &FUnordGreaterThanWordTypes,
  &FOrdLessThanEqualWordTypes,
  &FUnordLessThanEqualWordTypes,
  &FOrdGreaterThanEqualWordTypes,
  &FUnordGreaterThanEqualWordTypes,
  nullptr,
  nullptr,  
  &ShiftRightLogicalWordTypes,
  &ShiftRightArithmeticWordTypes,
  &ShiftLeftLogicalWordTypes,
  &BitwiseOrWordTypes,
  &BitwiseXorWordTypes,
  &BitwiseAndWordTypes,
  &NotWordTypes,
  &BitFieldInsertWordTypes,
  &BitFieldSExtractWordTypes,
  &BitFieldUExtractWordTypes,
  &BitReverseWordTypes,
  &BitCountWordTypes,
  nullptr,
  &DPdxWordTypes,
  &DPdyWordTypes,
  &FwidthWordTypes,
  &DPdxFineWordTypes,
  &DPdyFineWordTypes,
  &FwidthFineWordTypes,
  &DPdxCoarseWordTypes,
  &DPdyCoarseWordTypes,
  &FwidthCoarseWordTypes,
  nullptr,
  nullptr,
  &EmitVertexWordTypes,
  &EndPrimitiveWordTypes,
  &EmitStreamVertexWordTypes,
  &EndStreamPrimitiveWordTypes,
  nullptr,
  nullptr,
  &ControlBarrierWordTypes,
  &MemoryBarrierWordTypes,
  nullptr,
  &AtomicLoadWordTypes,
  &AtomicStoreWordTypes,
  &AtomicExchangeWordTypes,
  &AtomicCompareExchangeWordTypes,
  &AtomicCompareExchangeWeakWordTypes,
  &AtomicIIncrementWordTypes,
  &AtomicIDecrementWordTypes,
  &AtomicIAddWordTypes,
  &AtomicISubWordTypes,
  &AtomicSMinWordTypes,
  &AtomicUMinWordTypes,
  &AtomicSMaxWordTypes,
  &AtomicUMaxWordTypes,
  &AtomicAndWordTypes,
  &AtomicOrWordTypes,
  &AtomicXorWordTypes,
  nullptr,
  nullptr,  
  &PhiWordTypes,
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
  nullptr,
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
  nullptr,
  nullptr,
  &ReadPipeWordTypes,
  &WritePipeWordTypes,
  &ReservedReadPipeWordTypes,
  &ReservedWritePipeWordTypes,
  &ReserveReadPipePacketsWordTypes,
  &ReserveWritePipePacketsWordTypes,
  &CommitReadPipeWordTypes,
  &CommitWritePipeWordTypes,
  nullptr,
  nullptr,
  nullptr,  
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
};

uint32 LUTOpWordTypesCount[]{
  NopWordTypesCount,
  UndefWordTypesCount,
  0,
  SourceWordTypesCount,
  SourceExtensionWordTypesCount,
  NameWordTypesCount,
  MemberNameWordTypesCount,
  StringWordTypesCount,
  LineWordTypesCount,
  0,
  ExtensionWordTypesCount,
  ExtInstImportWordTypesCount,
  ExtInstWordTypesCount,
  0,
  MemoryModelWordTypesCount,
  EntryPointWordTypesCount,
  ExecutionModeWordTypesCount,
  CapabilityWordTypesCount,
  0,
  TypeVoidWordTypesCount,
  TypeBoolWordTypesCount,
  TypeIntWordTypesCount,
  TypeFloatWordTypesCount,
  TypeVectorWordTypesCount,
  TypeMatrixWordTypesCount,
  TypeImageWordTypesCount,
  TypeSamplerWordTypesCount,
  TypeSampledImageWordTypesCount,
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
  0,
  0,
  ConstantTrueWordTypesCount,
  ConstantFalseWordTypesCount,
  ConstantWordTypesCount,
  ConstantCompositeWordTypesCount,
  ConstantSamplerWordTypesCount,
  ConstantNullWordTypesCount,
  SpecConstantTrueWordTypesCount,
  SpecConstantFalseWordTypesCount,
  SpecConstantWordTypesCount,
  SpecConstantCompositeWordTypesCount,
  SpecConstantOpWordTypesCount,
  0,
  FunctionWordTypesCount,
  FunctionParameterWordTypesCount,
  FunctionEndWordTypesCount,
  FunctionCallWordTypesCount,
  0,
  VariableWordTypesCount,
  ImageTexelPointerWordTypesCount,
  LoadWordTypesCount,
  StoreWordTypesCount,
  CopyMemoryWordTypesCount,
  CopyMemorySizedWordTypesCount,
  AccessChainWordTypesCount,
  InBoundsAccessChainWordTypesCount,
  PtrAccessChainWordTypesCount,
  ArrayLengthWordTypesCount,
  GenericPtrMemSemanticsWordTypesCount,
  0,
  DecorateWordTypesCount,
  MemberDecorateWordTypesCount,
  DecorationGroupWordTypesCount,
  GroupDecorateWordTypesCount,
  GroupMemberDecorateWordTypesCount,
  0,
  VectorExtractDynamicWordTypesCount,
  VectorInsertDynamicWordTypesCount,
  VectorShuffleWordTypesCount,
  CompositeConstructWordTypesCount,
  CompositeExtractWordTypesCount,
  CompositeInsertWordTypesCount,
  CopyObjectWordTypesCount,
  TransposeWordTypesCount,
  0,
  SampledImageWordTypesCount,
  ImageSampleImplicitLodWordTypesCount,
  ImageSampleExplicitLodWordTypesCount,
  ImageSampleDrefImplicitLodWordTypesCount,
  ImageSampleDrefExplicitLodWordTypesCount,
  ImageSampleProjImplicitLodWordTypesCount,
  ImageSampleProjExplicitLodWordTypesCount,
  ImageSampleProjDrefImplicitLodWordTypesCount,
  ImageSampleProjDrefExplicitLodWordTypesCount,
  ImageFetchWordTypesCount,
  ImageGatherWordTypesCount,
  ImageDrefGatherWordTypesCount,
  ImageReadWordTypesCount,
  ImageWriteWordTypesCount,
  ImageQueryDimWordTypesCount,
  ImageQueryFormatWordTypesCount,
  ImageQueryOrderWordTypesCount,
  ImageQuerySizeLodWordTypesCount,
  ImageQuerySizeWordTypesCount,
  ImageQueryLodWordTypesCount,
  ImageQueryLevelsWordTypesCount,
  ImageQuerySamplesWordTypesCount,
  0,
  ConvertFToUWordTypesCount,
  ConvertFToSWordTypesCount,
  ConvertSToFWordTypesCount,
  ConvertUToFWordTypesCount,
  UConvertWordTypesCount,
  SConvertWordTypesCount,
  FConvertWordTypesCount,
  QuantizeToF16WordTypesCount,
  ConvertPtrToUWordTypesCount,
  SatConvertSToUWordTypesCount,
  SatConvertUToSWordTypesCount,
  ConvertUToPtrWordTypesCount,
  PtrCastToGenericWordTypesCount,
  GenericCastToPtrWordTypesCount,
  GenericCastToPtrExplicitWordTypesCount,
  BitcastWordTypesCount,
  0,
  SNegateWordTypesCount,
  FNegateWordTypesCount,
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
  IAddCarryWordTypesCount,
  ISubBorrowWordTypesCount,
  IMulExtendedWordTypesCount,
  0,
  0,
  AnyWordTypesCount,
  AllWordTypesCount,
  IsNanWordTypesCount,
  IsInfWordTypesCount,
  IsFiniteWordTypesCount,
  IsNormalWordTypesCount,
  SignBitSetWordTypesCount,
  LessOrGreaterWordTypesCount,
  OrderedWordTypesCount,
  UnorderedWordTypesCount,
  LogicalEqualWordTypesCount,
  LogicalNotEqualWordTypesCount,
  LogicalOrWordTypesCount,
  LogicalAndWordTypesCount,
  LogicalNotWordTypesCount,
  SelectWordTypesCount,
  IEqualWordTypesCount,
  INotEqualWordTypesCount,
  UGreaterThanWordTypesCount,
  SGreaterThanWordTypesCount,
  UGreaterThanEqualWordTypesCount,
  SGreaterThanEqualWordTypesCount,
  ULessThanWordTypesCount,
  SLessThanWordTypesCount,
  ULessThanEqualWordTypesCount,
  SLessThanEqualWordTypesCount,
  FOrdEqualWordTypesCount,
  FUnordEqualWordTypesCount,
  FOrdNotEqualWordTypesCount,
  FUnordNotEqualWordTypesCount,
  FOrdLessThanWordTypesCount,
  FUnordLessThanWordTypesCount,
  FOrdGreaterThanWordTypesCount,
  FUnordGreaterThanWordTypesCount,
  FOrdLessThanEqualWordTypesCount,
  FUnordLessThanEqualWordTypesCount,
  FOrdGreaterThanEqualWordTypesCount,
  FUnordGreaterThanEqualWordTypesCount,
  0,
  0,
  ShiftRightLogicalWordTypesCount,
  ShiftRightArithmeticWordTypesCount,
  ShiftLeftLogicalWordTypesCount,
  BitwiseOrWordTypesCount,
  BitwiseXorWordTypesCount,
  BitwiseAndWordTypesCount,
  NotWordTypesCount,
  BitFieldInsertWordTypesCount,
  BitFieldSExtractWordTypesCount,
  BitFieldUExtractWordTypesCount,
  BitReverseWordTypesCount,
  BitCountWordTypesCount,
  0,
  DPdxWordTypesCount,
  DPdyWordTypesCount,
  FwidthWordTypesCount,
  DPdxFineWordTypesCount,
  DPdyFineWordTypesCount,
  FwidthFineWordTypesCount,
  DPdxCoarseWordTypesCount,
  DPdyCoarseWordTypesCount,
  FwidthCoarseWordTypesCount,
  0,
  0,
  EmitVertexWordTypesCount,
  EndPrimitiveWordTypesCount,
  EmitStreamVertexWordTypesCount,
  EndStreamPrimitiveWordTypesCount,
  0,
  0,
  ControlBarrierWordTypesCount,
  MemoryBarrierWordTypesCount,
  0,
  AtomicLoadWordTypesCount,
  AtomicStoreWordTypesCount,
  AtomicExchangeWordTypesCount,
  AtomicCompareExchangeWordTypesCount,
  AtomicCompareExchangeWeakWordTypesCount,
  AtomicIIncrementWordTypesCount,
  AtomicIDecrementWordTypesCount,
  AtomicIAddWordTypesCount,
  AtomicISubWordTypesCount,
  AtomicSMinWordTypesCount,
  AtomicUMinWordTypesCount,
  AtomicSMaxWordTypesCount,
  AtomicUMaxWordTypesCount,
  AtomicAndWordTypesCount,
  AtomicOrWordTypesCount,
  AtomicXorWordTypesCount,
  0,
  0,
  PhiWordTypesCount,
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
  0,
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
  0,
  0,
  ReadPipeWordTypesCount,
  WritePipeWordTypesCount,
  ReservedReadPipeWordTypesCount,
  ReservedWritePipeWordTypesCount,
  ReserveReadPipePacketsWordTypesCount,
  ReserveWritePipePacketsWordTypesCount,
  CommitReadPipeWordTypesCount,
  CommitWritePipeWordTypesCount,
  0,
  0,
  0,
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
};

OpHandler LUTHandlerMethods[]{
  HandleNop,
  HandleUndef,
  nullptr,
  HandleSource,
  HandleSourceExtension,
  HandleName,
  HandleMemberName,
  HandleString,
  HandleLine,
  nullptr,
  HandleExtension,
  HandleExtInstImport,
  HandleExtInst,
  nullptr,
  HandleMemoryModel,
  HandleEntryPoint,
  HandleExecutionMode,
  HandleCapability,
  nullptr,
  HandleTypeVoid,
  HandleTypeBool,
  HandleTypeInt,
  HandleTypeFloat,
  HandleTypeVector,
  HandleTypeMatrix,
  HandleTypeImage,
  HandleTypeSampler,
  HandleTypeSampledImage,
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
  nullptr,
  nullptr,
  HandleConstantTrue,
  HandleConstantFalse,
  HandleConstant,
  HandleConstantComposite,
  HandleConstantSampler,
  HandleConstantNull,
  HandleSpecConstantTrue,
  HandleSpecConstantFalse,
  HandleSpecConstant,
  HandleSpecConstantComposite,
  HandleSpecConstantOp,
  nullptr,
  HandleFunction,
  HandleFunctionParameter,
  HandleFunctionEnd,
  HandleFunctionCall,
  nullptr,
  HandleVariable,
  HandleImageTexelPointer,
  HandleLoad,
  HandleStore,
  HandleCopyMemory,
  HandleCopyMemorySized,
  HandleAccessChain,
  HandleInBoundsAccessChain,
  HandlePtrAccessChain,
  HandleArrayLength,
  HandleGenericPtrMemSemantics,
  nullptr,
  HandleDecorate,
  HandleMemberDecorate,
  HandleDecorationGroup,
  HandleGroupDecorate,
  HandleGroupMemberDecorate,
  nullptr,
  HandleVectorExtractDynamic,
  HandleVectorInsertDynamic,
  HandleVectorShuffle,
  HandleCompositeConstruct,
  HandleCompositeExtract,
  HandleCompositeInsert,
  HandleCopyObject,
  HandleTranspose,
  nullptr,
  HandleSampledImage,
  HandleImageSampleImplicitLod,
  HandleImageSampleExplicitLod,
  HandleImageSampleDrefImplicitLod,
  HandleImageSampleDrefExplicitLod,
  HandleImageSampleProjImplicitLod,
  HandleImageSampleProjExplicitLod,
  HandleImageSampleProjDrefImplicitLod,
  HandleImageSampleProjDrefExplicitLod,
  HandleImageFetch,
  HandleImageGather,
  HandleImageDrefGather,
  HandleImageRead,
  HandleImageWrite,
  HandleImageQueryDim,
  HandleImageQueryFormat,
  HandleImageQueryOrder,
  HandleImageQuerySizeLod,
  HandleImageQuerySize,
  HandleImageQueryLod,
  HandleImageQueryLevels,
  HandleImageQuerySamples,
  nullptr,
  HandleConvertFToU,
  HandleConvertFToS,
  HandleConvertSToF,
  HandleConvertUToF,
  HandleUConvert,
  HandleSConvert,
  HandleFConvert,
  HandleQuantizeToF16,
  HandleConvertPtrToU,
  HandleSatConvertSToU,
  HandleSatConvertUToS,
  HandleConvertUToPtr,
  HandlePtrCastToGeneric,
  HandleGenericCastToPtr,
  HandleGenericCastToPtrExplicit,
  HandleBitcast,
  nullptr,
  HandleSNegate,
  HandleFNegate,
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
  HandleIAddCarry,
  HandleISubBorrow,
  HandleIMulExtended,
  nullptr,
  nullptr,
  HandleAny,
  HandleAll,
  HandleIsNan,
  HandleIsInf,
  HandleIsFinite,
  HandleIsNormal,
  HandleSignBitSet,
  HandleLessOrGreater,
  HandleOrdered,
  HandleUnordered,
  HandleLogicalEqual,
  HandleLogicalNotEqual,
  HandleLogicalOr,
  HandleLogicalAnd,
  HandleLogicalNot,
  HandleSelect,
  HandleIEqual,
  HandleINotEqual,
  HandleUGreaterThan,
  HandleSGreaterThan,
  HandleUGreaterThanEqual,
  HandleSGreaterThanEqual,
  HandleULessThan,
  HandleSLessThan,
  HandleULessThanEqual,
  HandleSLessThanEqual,
  HandleFOrdEqual,
  HandleFUnordEqual,
  HandleFOrdNotEqual,
  HandleFUnordNotEqual,
  HandleFOrdLessThan,
  HandleFUnordLessThan,
  HandleFOrdGreaterThan,
  HandleFUnordGreaterThan,
  HandleFOrdLessThanEqual,
  HandleFUnordLessThanEqual,
  HandleFOrdGreaterThanEqual,
  HandleFUnordGreaterThanEqual,
  nullptr,
  nullptr,
  HandleShiftRightLogical,
  HandleShiftRightArithmetic,
  HandleShiftLeftLogical,
  HandleBitwiseOr,
  HandleBitwiseXor,
  HandleBitwiseAnd,
  HandleNot,
  HandleBitFieldInsert,
  HandleBitFieldSExtract,
  HandleBitFieldUExtract,
  HandleBitReverse,
  HandleBitCount,
  nullptr,
  HandleDPdx,
  HandleDPdy,
  HandleFwidth,
  HandleDPdxFine,
  HandleDPdyFine,
  HandleFwidthFine,
  HandleDPdxCoarse,
  HandleDPdyCoarse,
  HandleFwidthCoarse,
  nullptr,
  nullptr,
  HandleEmitVertex,
  HandleEndPrimitive,
  HandleEmitStreamVertex,
  HandleEndStreamPrimitive,
  nullptr,
  nullptr,
  HandleControlBarrier,
  HandleMemoryBarrier,
  nullptr,
  HandleAtomicLoad,
  HandleAtomicStore,
  HandleAtomicExchange,
  HandleAtomicCompareExchange,
  HandleAtomicCompareExchangeWeak,
  HandleAtomicIIncrement,
  HandleAtomicIDecrement,
  HandleAtomicIAdd,
  HandleAtomicISub,
  HandleAtomicSMin,
  HandleAtomicUMin,
  HandleAtomicSMax,
  HandleAtomicUMax,
  HandleAtomicAnd,
  HandleAtomicOr,
  HandleAtomicXor,
  nullptr,
  nullptr,
  HandlePhi,
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
  nullptr,
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
  nullptr,
  nullptr,
  HandleReadPipe,
  HandleWritePipe,
  HandleReservedReadPipe,
  HandleReservedWritePipe,
  HandleReserveReadPipePackets,
  HandleReserveWritePipePackets,
  HandleCommitReadPipe,
  HandleCommitWritePipe,
  nullptr,
  nullptr,
  nullptr,
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
};
