#include <fstream>
#include <assert.h>
#include <iostream>
#include <sstream>
#include <string>
#include "types.h"

#include "parser_definitions.h" 
#include "parser.h"
#include "codegen.h"

std::string USAGE = "-i <input file> -o <outputFile>";

struct CmdArgs {
  const char* InputFile;
  const char* OutputFile;
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
    } else if (strcmp(arg, "-o") == 0) {
      i++;
      if (i == argc) {
        return false;
      }
      args->OutputFile = argv[i];
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

  Parser parser(wordCount);


  if (!inputFile.read((char*)parser.GetBufferPtr(), size)) {
    std::cout << "Could not read file." << std::endl;
    return -1;
  }
  
  inputFile.close();

  Program prog;

  if (!parser.ParseProgram(&prog)) {
    std::cout << "Could not parse program." << std::endl;
  }

  std::stringstream out;
  if (!genCode(&out, prog)) {
    std::cout << "Could not generate code for program." << std::endl;
  }

  std::ofstream outFile;
  outFile.open(args.OutputFile, std::ofstream::out);
  outFile << out.str();
  outFile.close();

  getchar();
  
  return 0;
}