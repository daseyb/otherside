#include "parser.h"

#include <assert.h>
#include <iostream>
#include <sstream>
#include <iomanip> 
#include <cstring>
#include "types.h"
#include "parser_definitions.h"


uint32 Parser::get() const {
  return *buffer;
}

bool Parser::end() const {
  return index >= length;
}

void Parser::eat() {
  index++;
  buffer++;
}

uint32 Parser::getAndEat() {
  uint32 result = get();
  eat();
  return result;
}

bool Parser::expectAndEat(uint32 e) {
  assert(e == get());
  eat();
  return true;
}

bool Parser::expect(uint32 e) const {
  assert(e == get());
  return true;
}


SOp Parser::readInstruction() {
  uint32* opData = buffer;
  uint32 word = getAndEat();
  spv::Op op = (spv::Op)(word & spv::OpCodeMask);
  uint32 wordCount = (uint32)(word >> spv::WordCountShift);

  WordType wordTypes[255];

  uint32 opWordCount = wordCount;

  if (sizeof(LUTOpWordTypes) / sizeof(void*) <= (int)op) {
    wordTypes[0] = WordType::TOp;
    for (uint32 i = 1; i < wordCount; i++) {
      wordTypes[i] = WordType::TLiteralNumber;
    }
  }
  else {
    WordType* opWordTypes = (WordType*)LUTOpWordTypes[(int)op];
    opWordCount = LUTOpWordTypesCount[(int)op];

    for (int i = 0; i < wordCount; i++) {
      wordTypes[i] = opWordTypes[i > opWordCount - 1 ? opWordCount - 1 : i];
    }
  }

  uint32* opMem = new uint32[opWordCount + 1];
  memset(opMem, 0, sizeof(uint32) * (opWordCount + 1));
  SOp Result = { op, opMem };
  auto bufferBegin = buffer;
  int indexBegin = index;

  for (uint32 i = 1; i < wordCount; i++) {
    word = getAndEat();
    void* currMem = opMem + i - 1;
    uint32* currMemU32 = (uint32*)currMem;
    if (wordTypes[i] == WordType::TIdList || wordTypes[i] == WordType::TLiteralNumberList) {
      assert(i + 1 == opWordCount);
      *currMemU32++ = (uint32) (wordCount - opWordCount + 1);
      currMem = currMemU32;
      *(uint32 **) currMem = (uint32 *) (buffer - 1);
      break;
    } else if (wordTypes[i] == WordType::TLiteralString) {
      assert(i + 1 == opWordCount);
      *(char **) currMem = (char *) (buffer - 1);
      break;
    } else {
      *currMemU32 = word;
    }
  }

  buffer = bufferBegin + wordCount - 1;
  index = indexBegin + wordCount - 1;

  return Result;
}

bool Parser::Parse(Program *outProg) {
  if (!expectAndEat(spv::MagicNumber)) {
    return false;
  }

  ParseProgram prog;
  prog.Version = getAndEat();
  prog.GeneratorMagic = getAndEat();
  prog.IDBound = getAndEat();
  prog.InstructionSchema = getAndEat();

  int instructionIndex = 0;
  prog.NextOp = readInstruction();

  do {
    SOp op = prog.NextOp;
    instructionIndex++;
    if (!end()) {
      prog.NextOp = readInstruction();
    } else {
      prog.NextOp = SOp{ Op::OpNop, nullptr };
    }

    LUTHandlerMethods[(int)op.Op]((void*)op.Memory, &prog);
    prog.Ops.push_back(op);

    if (prog.InFunction && prog.CurrentFunction->InBlock) {
      addOp(&prog, op);
    }
  } while (prog.NextOp.Op != Op::OpNop);

  *outProg = (Program)prog;
  return true;
}

std::string getDescriptor(uint32 id, const Program* prog) {
  if(prog->Names.find(id) != prog->Names.end()) {
    return prog->Names.at(id).Name;
  } else if(prog->Variables.find(id) != prog->Variables.end()) {
    SVariable variable = prog->Variables.at(id);
    return getDescriptor(variable.ResultId, prog);
  }
  return  "";
}

bool writeOpArg(std::stringstream& opline, SOp op, int i, const Program* prog, const WordType* wordTypes) {
  uint32 word = *((uint32*)op.Memory + i - 1);

  if (wordTypes[i] == WordType::TLiteralNumber) {
    opline << " " << word;
  }
  else if (wordTypes[i] == WordType::TId) {
    opline << " [" << word;
    if (prog != nullptr && op.Op != Op::OpName && op.Op != Op::OpMemberName) {
      auto desc = getDescriptor(word, prog);
      if (desc.size() > 0) {
        opline << "(" << getDescriptor(word, prog) << ")";
      }
    }
    opline << "]";
  }
  else if (wordTypes[i] == WordType::TIdList) {
    uint32 count = word;
    uint32* ptr = *(uint32**)((uint32*)op.Memory + i);
    opline << " [";
    for (uint32 j = 0; j < count; j++) {
      word = ptr[j];
      opline << "[" << word;
      if (prog != nullptr && op.Op != Op::OpName && op.Op != Op::OpMemberName) {
        auto desc = getDescriptor(word, prog);
        if (desc.size() > 0) {
          opline << "(" << getDescriptor(word, prog) << ")";
        }
      }
      opline << "]" << (j != count - 1 ? ", " : "");
    }
    opline << "]";

    return false;
  }
  else if (wordTypes[i] == WordType::TLiteralNumberList) {
    uint32 count = word;
    uint32* ptr = *(uint32**)((uint32*)op.Memory + i);
    opline << " [";
    for (uint32 j = 0; j < count; j++) {
      word = ptr[j];
      opline << word << (j != count - 1 ? ", " : "");
    }
    opline << "]";

    return false;
  }
  else if (wordTypes[i] == WordType::TLiteralString) {
    if (wordTypes[i - 1] != WordType::TLiteralString) {
      char* str = *((char**)((uint32*)op.Memory + i - 1));
      opline << " " << str;
    }
  }
  else {
    std::string* lutPointer = *((std::string**)LUTPointers + (uint32)wordTypes[i]);
    std::string name = lutPointer[word];
    opline << " " << name;
  }

}

std::string writeOp(SOp op, const Program* prog) {
  std::stringstream opline;

  WordType wordTypes[255];

  uint32 opWordCount = 0;

  if (sizeof(LUTOpWordTypes) / sizeof(void*) <= (int)op.Op) {
    return "";
  } else {
    WordType* opWordTypes = (WordType*)LUTOpWordTypes[(int)op.Op];
    opWordCount = LUTOpWordTypesCount[(int)op.Op];

    for (uint32 i = 0; i < opWordCount; i++) {
      wordTypes[i] = opWordTypes[i];
    }
  }

  opline << OpStrings[(int)op.Op];

  for (uint32 i = 1; i < opWordCount && writeOpArg(opline, op, i, prog, wordTypes); i++);

  opline << std::endl;
  return opline.str();
}

std::string writeProgram(const Program& prog) {
  std::stringstream progStream;
  progStream << "Version: " << prog.Version << std::endl;
  progStream << "Generator Magic: " << prog.GeneratorMagic << std::endl;
  progStream << "ID Bound: " << prog.IDBound << std::endl;
  progStream << "Instruction Schema: " << prog.InstructionSchema << std::endl;
  progStream << "=================================================" << std::endl;
  int instructionIndex = 0;
  for(auto& op : prog.Ops) {
    progStream << std::setw(3) << instructionIndex << ": " << writeOp(op, &prog);
    instructionIndex++;
  }
  return progStream.str();
}

std::string writeOp(SOp op) {
  return writeOp(op, nullptr);
}
