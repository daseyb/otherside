#include <fstream>
#include <assert.h>
#include <iostream>
#include <sstream>
#include <string>
#include "types.h"

#include "parser_definitions.h" 
#include "parser.h"
#include "codegen.h"
#include "interpreted_vm.h"

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

struct Color {
  float r;
  float g;
  float b;
  float a;
};

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

  Environment env;
  InterpretedVM vm(prog, env);
  
  Color* col = new Color();
  col->r = 1;
  col->g = 0.5f;
  col->b= 0.25f;

  vm.SetVariable("color", &col);
  
  std::cout << "============================================" << std::endl;
  std::cout << "Running program with: " << std::endl;
  std::cout << "color = (" << col->r << "," << col->g << "," << col->b << ")" << std::endl;
  std::cout << "============================================" << std::endl;
  if (!vm.Run()) {
    std::cout << "Could not run program." << std::endl;
  } else {
    std::cout << "Success!" << std::endl;
    Color* fracColor = *(Color**)vm.ReadVariable("gl_FragColor");
    std::cout << "gl_FragColor = (" << fracColor->r << "," << fracColor->g << "," << fracColor->b << "," << fracColor->a << ")" << std::endl;
  }



  getchar();
  
  return 0;
}