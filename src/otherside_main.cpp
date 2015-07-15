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

struct Color {
  float r;
  float g;
  float b;
  float a;
};


struct Texture {
  int width;
  int height;
  Color* data;
};

Texture MakeFlatTexture(int w, int h, Color col) {
  Color* data = new Color[w * h];
  for (int i = 0; i < w * h; i++) {
    data[i] = col;
  }
  return Texture{ w, h, data };
}

Texture MakeGradientTexture(int w, int h) {
  Color* data = new Color[w * h];
  float a = 1;
  for (int x = 0; x < w; x++) {
    float r = float(x) / (w - 1);
    for (int y = 0; y < h; y++) {
      float g = float(y) / (h - 1);
      float b = r*g;
      data[x + y * w] = { r, g, b, a };
    }
  }
  return Texture{ w, h, data };
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

  Environment env;
  InterpretedVM vm(prog, env);
  
  Color* col = new Color();
  col->r = 1;
  col->g = 0.5f;
  col->b= 0.25f;


  Color* uv = new Color();
  uv->r = 1.2f;
  uv->g = 0.6f;

  Texture tex = MakeGradientTexture(10, 10);

  Sampler* sampler = new Sampler{ 2, (uint32*)&tex, tex.data, FilterMode::Point, WrapMode::Repeat };

  vm.SetVariable("uv", &uv);
  vm.SetVariable("testTex", &sampler);

  std::cout << "============================================" << std::endl;
  std::cout << "Running program with: " << std::endl;
  std::cout << "uv = (" << uv->r << "," << uv->g << ")" << std::endl;
  std::cout << "testTex = " << tex.width << std::endl;
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