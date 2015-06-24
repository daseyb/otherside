typedef unsigned char byte;
typedef unsigned int uint32;
typedef unsigned short uint16;

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <assert.h>
#include "Khronos\spirv.h"
#include "lookups.h"

std::string USAGE = "-i <input file>";

static uint32* buffer;
static int length;
static int index;

uint32 p_get() {
  return *buffer;
}

bool p_End() {
  return index >= length;
}

void p_eat() {
  index++;
  buffer++;
}

uint32 p_getAndEat() {
  uint32 result = p_get();
  p_eat();
  return result;
}

bool p_expectAndEat(uint32 e) {
  assert(e == p_get());
  p_eat();
  return true;
}

bool p_expect(uint32 e) {
  assert(e == p_get());
  return true;
}

void p_readInstruction() {
  uint32* opData = buffer;
  uint32 word = p_getAndEat();
  spv::Op op = (spv::Op)(word & spv::OpCodeMask);
  uint16 wordCount = (uint16)(word >> spv::WordCountShift);

  std::cout << OpStrings[(uint32)op];

  WordType wordTypes[255];

  if (sizeof(LUTOpWordTypes) / sizeof(void*) <= op) {
    wordTypes[0] = WordType::TOp;
    for (int i = 1; i < wordCount; i++) {
      wordTypes[i] = WordType::TValue;
    }
  } else {
    WordType* opWordTypes = (WordType*)LUTOpWordTypes[op];
    uint32 opWordTypeCount = LUTOpWordTypesCount[op];

    for (int i = 0; i < wordCount; i++) {
      wordTypes[i] = opWordTypes[i > opWordTypeCount - 1 ? opWordTypeCount - 1 : i];
    }
  }
  

  for (int i = 1; i < wordCount; i++) {
    word = p_getAndEat();
    if (wordTypes[i] == WordType::TValue) {
      std::cout << " " << word;
    }
    else if (wordTypes[i] == WordType::TId) {
      std::cout << " [" << word << "]";
    }
    else if (wordTypes[i] == WordType::TChar) {
      if (wordTypes[i - 1] != WordType::TChar) {
        std::cout << " ";
      }

      char* cbuff = (char*)&word;
      for (int j = 0; j < 4; j++) {
        std::cout << *cbuff;
        cbuff++;
      }
    }
    else {
      std::string* lutPointer = *((std::string**)LUTPointers + (uint32)wordTypes[i]);
      std::string name = lutPointer[word];
      std::cout << " " << name;
    }
  }

  std::cout << std::endl;
}

struct CmdArgs {
  const char* InputFile;
};

bool ParseArgs(int argc, const char** argv, CmdArgs* args) {
  for (int i = 1; i < argc; i++) {
    const char* arg = argv[i];

    if (strcmp(arg, "-i") == 0) {
      i++;
      if (i == argc) {
        return false;
      }
      args->InputFile = argv[i];
    }
  }
  return true;
}


int main(int argc, const char** argv) {
  CmdArgs args;
  if (!ParseArgs(argc, argv, &args)) {
    std::cout << "Could not parse arguments. Usage: " << USAGE << std::endl;
    return -1;
  }

  std::ifstream inputFile;
  inputFile.open(args.InputFile, std::ifstream::in | std::ifstream::binary);
  inputFile.seekg(0, std::ios::end);
  std::streamsize size = inputFile.tellg();
  inputFile.seekg(0, std::ios::beg);

  assert(size % 4 == 0);
  std::streamsize wordCount = size / 4;

  buffer = new uint32[wordCount];
  length = wordCount;
  index = 0;

  if (!inputFile.read((char*)buffer, size)) {
    std::cout << "Could not read file." << std::endl;
    return -1;
  }
  
  inputFile.close();

  p_expectAndEat(spv::MagicNumber);

  uint32 versionNumber = p_getAndEat();
  std::cout << "Version: " << versionNumber << std::endl;
  
  uint32 genMagic = p_getAndEat();
  std::cout << "Generator Magic: " << genMagic << std::endl;

  uint32 bound = p_getAndEat();
  std::cout << "ID Bound: " << bound << std::endl;

  uint32 instructionSchema = p_getAndEat();
  std::cout << "Instruction Schema: " << instructionSchema << std::endl;

  std::cout << "=================================================" << std::endl;

  int instructionIndex = 0;

  while (!p_End()) {
    std::cout << std::setw(3) << instructionIndex << ": ";
    p_readInstruction();
    instructionIndex++;
  }

  getchar();
  
  return 0;
}