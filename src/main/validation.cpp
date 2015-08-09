#include "validation.h"
#include "parser_definitions.h"
#include "lookups_gen.h"
#include <set>
#include "parser.h"

#define CURRENT_OP prog.Ops[opIndex]
#define CURRENT_OP_TYPE CURRENT_OP.Op
#define FORBID(op) forbiddenOps.insert(op)
#define NOT_FORBIDDEN(op) \
  if(forbiddenOps.find(op) != forbiddenOps.end()) { errorOut << "Instruction " << writeOp(prog.Ops[opIndex]) << "was not allowed here. (Index: " << opIndex << ")" << std::endl; return false; }

#define REQUIRED_USE(op) \
  if(CURRENT_OP_TYPE == op) { \
    NOT_FORBIDDEN(op) opIndex++; \
  } else { \
    errorOut << "Instruction " << writeOp(prog.Ops[opIndex]) << "was not allowed here. (L" << opIndex << ") Required: " << OpStrings[(int)op] << std::endl; \
    return false;  \
  } \
  FORBID(op);

#define OPTIONAL_USE(op) { if(CURRENT_OP_TYPE == op) {  NOT_FORBIDDEN(op) opIndex++; } FORBID(op); }
#define MANY(op) while(CURRENT_OP_TYPE == op) { NOT_FORBIDDEN(op) opIndex++; }
#define MANY_USE(op) { MANY(op) FORBID(op); }
#define MANY_F(func) while(func(CURRENT_OP)) { NOT_FORBIDDEN(CURRENT_OP_TYPE) opIndex++; }


bool v_ids(const Program& prog, std::ostream& errorOut) {
  return true;
}

bool v_layout(const Program& prog, std::ostream& errorOut) {
  int opIndex = 0;
  std::set<spv::Op> forbiddenOps;

  OPTIONAL_USE(spv::Op::OpSource)
  OPTIONAL_USE(spv::Op::OpSourceExtension)
  MANY_USE(spv::Op::OpCapability)
  MANY_USE(spv::Op::OpExtension)
  MANY_USE(spv::Op::OpExtInstImport)
  REQUIRED_USE(spv::Op::OpMemoryModel)
  MANY_USE(spv::Op::OpEntryPoint)
  MANY_USE(spv::Op::OpExecutionMode)
  MANY_USE(spv::Op::OpString)
  MANY_USE(spv::Op::OpName)
  MANY_USE(spv::Op::OpMemberName)
  MANY_USE(spv::Op::OpLine)

  MANY_F([](SOp op) {
      return op.Op == spv::Op::OpDecorate ||
          op.Op == spv::Op::OpMemberDecorate ||
          op.Op == spv::Op::OpGroupDecorate ||
          op.Op == spv::Op::OpGroupMemberDecorate ||
          op.Op == spv::Op::OpDecorationGroup;
  })

  MANY_F([](SOp op) {
      return
          OpStrings[(int)op.Op].find("OpType") != std::string::npos ||
          (op.Op == spv::Op::OpVariable &&
           ((SVariable*)op.Memory)->StorageClass != spv::StorageClass::Function);
  })

  //TODO (Dario): Function Declerations
  //TODO (Dario): Function Definitions

  return true;
}

bool validate(const Program& prog, std::ostream& errorOut) {
  if(!v_layout(prog, errorOut)) {
    errorOut << "Logical layout is not correct!" << std::endl;
    return false;
  }
  return true;
}