#include "validation.h"
#include "parser_definitions.h"
#include "lookups_gen.h"
#include <set>
#include "parser.h"

#define CURRENT_OP prog.Ops[opIndex]
#define CURRENT_OP_TYPE CURRENT_OP.Op
#define FORBID(op) forbiddenOps.insert(op)
#define ALLOW(op) forbiddenOps.erase(forbiddenOps.find(op))
#define NOT_FORBIDDEN(op) \
  if(forbiddenOps.find(op) != forbiddenOps.end()) { errorOut << "Instruction " << writeOp(prog.Ops[opIndex]) << "was not allowed here. (Index: " << opIndex << ")" << std::endl; return false; }

#define NOT_END (opIndex < prog.Ops.size())
#define EXPECT_OP(op) if(!NOT_END) { errorOut << "Unexpected end of instruction stream. Expected: " << OpStrings[(int)op] << std::endl; return false; }

#define REQUIRED_F(func) \
  EXPECT_OP(CURRENT_OP_TYPE) \
  if(func(CURRENT_OP_TYPE)) { \
    NOT_FORBIDDEN(CURRENT_OP_TYPE) opIndex++; \
  } else { \
    errorOut << "Instruction " << writeOp(prog.Ops[opIndex]) << "was not allowed here. (L" << opIndex << ")" << std::endl; \
    return false;  \
  }

#define REQUIRED(op) \
  EXPECT_OP(op) \
  if(CURRENT_OP_TYPE == op) { \
    NOT_FORBIDDEN(op) opIndex++; \
  } else { \
    errorOut << "Instruction " << writeOp(prog.Ops[opIndex]) << "was not allowed here. (L" << opIndex << ") Required: " << OpStrings[(int)op] << std::endl; \
    return false;  \
  }

#define REQUIRED_USE(op) \
  REQUIRED(op) \
  FORBID(op);

#define OPTIONAL_USE(op) { EXPECT_OP(op) if(CURRENT_OP_TYPE == op) {  NOT_FORBIDDEN(op) opIndex++; } FORBID(op); }
#define MANY(op)  EXPECT_OP(op) while(NOT_END && CURRENT_OP_TYPE == op) { NOT_FORBIDDEN(op) opIndex++; }
#define MANY_USE(op) { EXPECT_OP(op) MANY(op) FORBID(op); }
#define MANY_F(func) while(NOT_END && func(CURRENT_OP)) {NOT_FORBIDDEN(CURRENT_OP_TYPE) opIndex++; }


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

  MANY_F([](SOp op) {
      return op.Op == spv::Op::OpName ||
             op.Op == spv::Op::OpMemberName;
  })
  FORBID(spv::Op::OpName), FORBID(spv::Op::OpMemberName);

  MANY_USE(spv::Op::OpLine)

  MANY_F([](SOp op) {
      return op.Op == spv::Op::OpDecorate ||
          op.Op == spv::Op::OpMemberDecorate ||
          op.Op == spv::Op::OpGroupDecorate ||
          op.Op == spv::Op::OpGroupMemberDecorate ||
          op.Op == spv::Op::OpDecorationGroup;
  })

  FORBID(spv::Op::OpDecorate), FORBID(spv::Op::OpMemberDecorate), FORBID(spv::Op::OpGroupDecorate),
  FORBID(spv::Op::OpGroupMemberDecorate), FORBID(spv::Op::OpDecorationGroup);

  MANY_F([](SOp op) {
      return
          OpStrings[(int)op.Op].find("Type") != std::string::npos ||
          OpStrings[(int)op.Op].find("Constant") != std::string::npos ||
          (op.Op == spv::Op::OpVariable && ((SVariable*)op.Memory)->StorageClass != spv::StorageClass::Function);
  })

  while(NOT_END && CURRENT_OP_TYPE == spv::Op::OpFunction) {
    REQUIRED(spv::Op::OpFunction)
    MANY(spv::Op::OpFunctionParameter)
    bool isFirstBlock = true;
    while(NOT_END && CURRENT_OP_TYPE != spv::Op::OpFunctionEnd) {
      REQUIRED(spv::Op::OpLabel)

      if(isFirstBlock) {
        MANY_F([](SOp op) {
            return op.Op == spv::Op::OpVariable &&
                ((SVariable*)op.Memory)->StorageClass == spv::StorageClass::Function;
        })
        FORBID(spv::Op::OpVariable);
      }

      auto isBranch = [](spv::Op op) {
          return
              op == spv::Op::OpBranch ||
              op == spv::Op::OpBranchConditional ||
              op == spv::Op::OpSwitch ||
              op == spv::Op::OpKill ||
              op == spv::Op::OpReturn ||
              op == spv::Op::OpReturnValue ||
              op == spv::Op::OpUnreachable;
      };

      auto blockMany = [isFirstBlock, isBranch](SOp op) {
          return (op.Op != spv::Op::OpPhi || !isFirstBlock) &&
                 op.Op != spv::Op::OpLabel &&
                 !isBranch(op.Op);
      };

      MANY_F(blockMany)

      REQUIRED_F(isBranch)

      isFirstBlock = false;
    }

    ALLOW(spv::Op::OpVariable);
    REQUIRED(spv::Op::OpFunctionEnd)
  }

  if(NOT_END) {
    errorOut << "Expected end of module but found (Index: " << opIndex << ") " << writeOp(CURRENT_OP);
    return false;
  }

  return true;
}

bool validate(const Program& prog, std::ostream& errorOut) {
  if(!v_layout(prog, errorOut)) {
    errorOut << "Logical layout is not correct!" << std::endl;
    return false;
  }
  return true;
}