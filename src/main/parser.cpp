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
    for (int i = 1; i < wordCount; i++) {
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
  for (int i = 1; i < wordCount; i++) {
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

  return Result;
}

bool Parser::ParseProgram(Program* prog) {
  if (!expectAndEat(spv::MagicNumber)) {
    return false;
  }

  prog->Version = getAndEat();
  std::cout << "Version: " << prog->Version << std::endl;

  prog->GeneratorMagic = getAndEat();
  std::cout << "Generator Magic: " << prog->GeneratorMagic << std::endl;

  prog->IDBound = getAndEat();
  std::cout << "ID Bound: " << prog->IDBound << std::endl;

  prog->InstructionSchema = getAndEat();
  std::cout << "Instruction Schema: " << prog->InstructionSchema << std::endl;
  std::cout << "=================================================" << std::endl;

  int instructionIndex = 0;
  
  prog->NextOp = readInstruction();

  do {
    SOp op = prog->NextOp;
    std::cout << std::setw(3) << instructionIndex << ": " << writeOp(op);
    instructionIndex++;
    if (!end()) {
      prog->NextOp = readInstruction();
    }
    else {
      prog->NextOp = SOp{ Op::OpNop, nullptr };
    }

    LUTHandlerMethods[(int)op.Op]((void*)op.Memory, prog);

    if (prog->InFunction && prog->CurrentFunction->InBlock) {
      addOp(prog, op);
    }

  } while (prog->NextOp.Op != Op::OpNop);

  return true;
}

std::string writeOp(SOp op) {
  std::stringstream opline;

  opline << OpStrings[(int)op.Op];

  WordType wordTypes[255];

  uint32 opWordCount = 0;

  if (sizeof(LUTOpWordTypes) / sizeof(void*) <= (int)op.Op) {
    return "";
  }
  else {
    WordType* opWordTypes = (WordType*)LUTOpWordTypes[(int)op.Op];
    opWordCount = LUTOpWordTypesCount[(int)op.Op];

    for (int i = 0; i < opWordCount; i++) {
      wordTypes[i] = opWordTypes[i];
    }
  }

  for (int i = 1; i < opWordCount; i++) {
    uint32 word = *((uint32*)op.Memory + i - 1);

    if (wordTypes[i] == WordType::TLiteralNumber) {
      opline << " " << word;
    }
    else if (wordTypes[i] == WordType::TId) {
      opline << " [" << word << "]";
    }
    else if (wordTypes[i] == WordType::TIdList) {
      uint32 count = word;
      uint32* ptr = *(uint32**)((uint32*)op.Memory + i);
      opline << " [";
      for (int j = 0; j < count; j++) {
        word = ptr[j];
        opline << "[" << word << "]" << (j != count - 1 ? ", " : "");
      }
      opline << "]";

      break;
    }
    else if (wordTypes[i] == WordType::TLiteralNumberList) {
      uint32 count = word;
      uint32* ptr = *(uint32**)((uint32*)op.Memory + i);
      opline << " [";
      for (int j = 0; j < count; j++) {
        word = ptr[j];
        opline << word << (j != count - 1 ? ", " : "");
      }
      opline << "]";

      break;
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

  opline << std::endl;
  return opline.str();
}
