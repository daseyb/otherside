#include "parser.h"

#include <assert.h>
#include <iostream>
#include <sstream>
#include <iomanip> 
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
  uint16 wordCount = (uint16)(word >> spv::WordCountShift);

  WordType wordTypes[255];

  uint16 opWordCount = wordCount;

  if (sizeof(LUTOpWordTypes) / sizeof(void*) <= op) {
    wordTypes[0] = WordType::TOp;
    for (int i = 1; i < wordCount; i++) {
      wordTypes[i] = WordType::TLiteralNumber;
    }
  }
  else {
    WordType* opWordTypes = (WordType*)LUTOpWordTypes[op];
    opWordCount = LUTOpWordTypesCount[op];

    for (int i = 0; i < wordCount; i++) {
      wordTypes[i] = opWordTypes[i > opWordCount - 1 ? opWordCount - 1 : i];
    }
  }

  uint32* opMem = new uint32[opWordCount + 1];
  memset(opMem, 0, sizeof(uint32) * (opWordCount + 1));
  SOp Result = { op, opMem };

  for (int i = 1; i < wordCount; i++) {
    word = getAndEat();
    uint32* currMem = opMem + i - 1;

    if (wordTypes[i] == WordType::TLiteralNumber || wordTypes[i] == WordType::TId) {
      *currMem = word;
    } else if (wordTypes[i] == WordType::TIdList || wordTypes[i] == WordType::TLiteralNumberList) {
      if (i + 1 == opWordCount) {
        *(currMem++) = (uint32)(wordCount - opWordCount + 1);
        *(uint32**)currMem = (uint32*)(buffer - 1);
      } else if (i < opWordCount) {
        *currMem = word;
      }
    } else if (wordTypes[i] == WordType::TLiteralString) {
      if (wordTypes[i - 1] != WordType::TLiteralString) {
        *(char**)currMem = (char*)(buffer - 1);
      }
    } else {
      *currMem = word;
    }
  }

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

    LUTHandlerMethods[op.Op]((void*)op.Memory, prog);

    if (prog->InFunction && prog->CurrentFunction.InBlock) {
      addOp(prog, op);
    }

  } while (prog->NextOp.Op != Op::OpNop);

  return true;
}

std::string writeOp(SOp op) {
  std::stringstream opline;

  opline << OpStrings[op.Op];

  WordType wordTypes[255];

  uint32 opWordCount = 0;

  if (sizeof(LUTOpWordTypes) / sizeof(void*) <= op.Op) {
    return "";
  }
  else {
    WordType* opWordTypes = (WordType*)LUTOpWordTypes[op.Op];
    opWordCount = LUTOpWordTypesCount[op.Op];

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

      for (int j = 0; j < count; j++) {
        word = *((uint32*)op.Memory + i + j);
        opline << " [" << word << "]";
      }

      break;
    }
    else if (wordTypes[i] == WordType::TLiteralNumberList) {
      uint32 count = word;

      for (int j = 0; j < count; j++) {
        word = *((uint32*)op.Memory + i + j);
        opline << " " << word;
      }

      break;
    }
    else if (wordTypes[i] == WordType::TLiteralString) {
      if (wordTypes[i - 1] != WordType::TLiteralString) {
        opline << " " << (char*)word;
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