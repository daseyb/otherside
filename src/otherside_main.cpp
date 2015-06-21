#include <iostream>
#include <string>
#include <fstream>
#include <assert.h>
#include "Khronos\spirv.h"

typedef unsigned char byte;
typedef unsigned int uint32;
typedef unsigned short uint16;

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
  uint32 word = p_getAndEat();
  uint16 op = (uint16)(word & spv::OpCodeMask);
  uint16 wordCount = (uint16)(word >> spv::WordCountShift);

  std::cout << "Op: " << op;
  
  for (int i = 0; i < wordCount-1; i++) {
    word = p_getAndEat();
    std::cout << " " << word;
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

  while (!p_End()) {
    p_readInstruction();
  }

  getchar();
  
  return 0;
}