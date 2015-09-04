#include <fstream>
#include <assert.h>
#include <iostream>
#include <sstream>
#include <string>
#include "types.h"

#include "parser_definitions.h" 
#include "parser.h"
#include "codegen.h"
#include "validation.h"
#include "interpreted_vm.h"
#include "utils.h"

std::string USAGE = "-i <input file> -o <outputFile>";

struct TestArgs {
  const char* ShaderFile;
  const char* CppFile;
  std::map<std::string, void*> inputValues;
};

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

  Parser parser(args.InputFile);
  Program prog;

  if (!parser.Parse(&prog)) {
    std::cout << "Could not parse program." << std::endl;
    return -1;
  }

  std::cout << "Validating program:...";
  if(!validate(prog, std::cout)) {
    std::cout << "Validation failed." << std::endl;
    return -1;
  }
  std::cout << "done" << std::endl;

  std::cout << writeProgram(prog);

  std::cout << "Generationg code:...";
  if (!genCode(args.OutputFile, prog)) {
    std::cout << "Could not generate code for program." << std::endl;
    return -1;
  }
  std::cout << "done" << std::endl;

  Environment env;
  InterpretedVM vm(prog, env);
  if(!vm.Setup()) {
      std::cout << "Could not setup the VM." << std::endl;
      return -1;
  }

  std::cout << "Running program:...";

  Texture inTex = load_tex("data/testin.bmp");

  Sampler* sampler = new Sampler{ 2, (uint32*)&inTex, inTex.data, FilterMode::FMPoint, WrapMode::WMRepeat };
  Vec2* texSize = new Vec2{ (float)inTex.width, (float)inTex.height};
  Light* light = new Light{ {1, 0, 0, 1}, {0.5f, 0.5f} };
  Color* fragColor = new Color{ 0, 0, 0, 0 };
  Vec2* uv = new Vec2{ 1.0f, 1.0f };

  bool allVariablesSet = true;
  allVariablesSet &= vm.SetVariable("uv", &uv);
  allVariablesSet &= vm.SetVariable("texSize", &texSize);
  allVariablesSet &= vm.SetVariable("testTex", &sampler);
  allVariablesSet &= vm.SetVariable("light", &light);
  allVariablesSet &= vm.SetVariable("gl_FragColor", &fragColor);

  if(!allVariablesSet) {
    std::cout << "Could not set all variables." << std::endl;
    return -1;
  }

  Texture outTex = MakeFlatTexture(inTex.width, inTex.height, { 0, 0, 0, 1 });

  for (int x = 0; x < outTex.width; x++) {
    for (int y = 0; y < outTex.height; y++) {
      uv->x = float(x) / outTex.width;
      uv->y = float(y) / outTex.height;

      if (!vm.Run()) {
        std::cout << "Program failed to run.";
        return -1;
      }

      outTex.data[x + y * outTex.width] = **(Color**)vm.ReadVariable("gl_FragColor");
    }
  }

  save_bmp("data/testout.bmp", outTex);

  std::cout << " done";
  return 0;
}
