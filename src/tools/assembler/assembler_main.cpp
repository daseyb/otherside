#include "types.h"
#include "parser_definitions.h"
#include "parser.h"
#include <assert.h>
#include <iostream>
#include <fstream>
#include <sstream>

const int GENERATOR_MAGIC = 0xFEEDFEED;

int main(int argc, char** argv) {
  assert(argc == 3);
  char* infilename = argv[1];
  char* outfilename = argv[2];

  std::ifstream inFile;
  inFile.open(infilename, std::ifstream::in);
  if(!inFile.is_open()) {
    std::cout << "Could not open file " << infilename << std::endl;
    return -1;
  }

  std::ofstream outFile;
  outFile.open(outfilename, std::ofstream::out | std::ofstream::binary);
  if(!outFile.is_open()) {
    std::cout << "Could not open file " << outfilename << std::endl;
    return -1;
  }

/*
  std::string valueString;
  inFile >> valueString;
  assert(valueString.find("Version: ") == valueString.begin());
  uint32 version = getValue<uint32>(valueString);
  inFile >> valueString;
  uint32 generatorMagic = getValue<uint32>(valueString);

  outFile << spv::MagicNumber;
  outFile << version;
  outFile << generatorMagic;

  Program program;
  Parser parser(argv[1]);
  parser.Parse(&program);
  std::cout << writeProgram(program);*/
}


