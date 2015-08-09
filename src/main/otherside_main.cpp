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

#define STB_IMAGE_IMPLEMENTATION
#include "stb/stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb/stb_image_write.h"

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

template<typename T>
struct TColor {
  T r;
  T g;
  T b;
  T a;
};

typedef TColor<float> Color;
typedef TColor<byte> BColor;

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

BColor* ConvertToByte(uint32 w, uint32 h, Color* in) {
  BColor* data = new BColor[w *h];
  for (int x = 0; x < w; x++) {
    for (int y = 0; y < h; y++) {
      auto p = in[x + y * w];
      data[x + y * w] = BColor { byte(p.r * 255), byte(p.g * 255), byte(p.b * 255), byte(p.a * 255) };
    }
  }
  return data;
}

Color* ConvertToFloat(uint32 w, uint32 h, BColor* in) {
  Color* data = new Color[w *h];
  for (int x = 0; x < w; x++) {
    for (int y = 0; y < h; y++) {
      auto p = in[x + y * w];
      data[x + y * w] = { float(p.r) / 255, float(p.g) / 255, float(p.b) / 255, float(p.a) / 255 };
    }
  }
  return data;
}

struct Vec2 {
  float x;
  float y;
};

struct Light {
  Color color;
  Vec2 pos;
};

int main(int argc, const char** argv) {
  CmdArgs args;
  if (!ParseArgs(argc, argv, &args)) {
    std::cout << "Could not parse arguments. Usage: " << USAGE << std::endl;
    return -1;
  }

  Parser parser(args.InputFile);
  Program prog;

  if (!parser.ParseProgram(&prog)) {
    std::cout << "Could not parse program." << std::endl;
    return -1;
  }

  if(!validate(prog, std::cout)) {
    std::cout << "Validation failed." << std::endl;
    return -1;
  }

  if (!genCode(args.OutputFile, prog)) {
    std::cout << "Could not generate code for program." << std::endl;
    return -1;
  }

  Environment env;
  InterpretedVM vm(prog, env);
  if(!vm.Setup()) {
      std::cout << "Could not setup the VM." << std::endl;
      return -1;
  }

  Color* col = new Color{ 1, 0.5f, 0.25f };
  Vec2* uv = new Vec2{ 1.0f, 1.0f };

  Texture inTex;
  int comps;
  BColor* inputData = (BColor*)stbi_load("data/testin.bmp", &inTex.width, &inTex.height, &comps, 4);
  inTex.data = ConvertToFloat(inTex.width, inTex.height, inputData);

  Sampler* sampler = new Sampler{ 2, (uint32*)&inTex, inTex.data, FilterMode::FMPoint, WrapMode::WMRepeat };
  Texture outTex = MakeFlatTexture(inTex.width, inTex.height, { 0, 0, 0, 1 });

  std::cout << "Running program: ...";

  Vec2* texSize = new Vec2{ (float)inTex.width, (float)inTex.height};
  Light* light = new Light{ {1, 0, 0, 1}, {0.5f, 0.5f} };
  Color* fragColor = new Color{ 0, 0, 0, 0 };

  vm.SetVariable("uv", &uv);
  vm.SetVariable("texSize", &texSize);
  vm.SetVariable("testTex", &sampler);
  vm.SetVariable("light", &light);
  vm.SetVariable("gl_FragColor", &fragColor);

  bool didFail = false;
  for (int x = 0; x < outTex.width && !didFail; x++) {
    for (int y = 0; y < outTex.height; y++) {
      uv->x = float(x) / outTex.width;
      uv->y = float(y) / outTex.height;

      if (!vm.Run()) {
        std::cout << "Program failed to run.";
        getchar();
        return -1;
      }

      outTex.data[x + y * outTex.width] = **(Color**)vm.ReadVariable("gl_FragColor");
    }
  }

  BColor* outData = ConvertToByte(outTex.width, outTex.height, outTex.data);
  stbi_write_bmp("data/testout.bmp", outTex.width, outTex.height, 4, outData);

  std::cout << " done";

  return 0;
}
