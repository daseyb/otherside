#include "types.h"
#include "parser_definitions.h"
#include "parser.h"
#include <assert.h>
#include <iostream>

int main(int argc, char** argv) {
  assert(argc == 2);
  Program program;
  Parser parser(argv[1]);
  parser.Parse(&program);
  std::cout << writeProgram(program);
}


