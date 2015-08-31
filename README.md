# otherside

[![Join the chat at https://gitter.im/bonus2113/otherside](https://badges.gitter.im/Join%20Chat.svg)](https://gitter.im/bonus2113/otherside?utm_source=badge&utm_medium=badge&utm_campaign=pr-badge&utm_content=badge)
[![Build Status](https://travis-ci.org/bonus2113/otherside.svg?branch=master)](https://travis-ci.org/bonus2113/otherside)

A VM running SPIR-V code on the CPU

This is an implementation of the SPIR-V, the new intermediate language defined by Khronos.  
See the official specification here: [SPIR-V 1.0](https://www.khronos.org/registry/spir-v/specs/1.0/SPIRV.html)

It also produces C like code that represents the given SPIR-V file (for easier reading).

#### Why?
I'm mostly working on this out of academic interest. I do plan on using it in my universities "write a software rasterizer" project.  
Once verification is implemented it could be used to verify the output of tools that produce SPIR-V (and right now, I guess if the program runs and gives the correct output, that is some kind of verification as well).

#### Note 
This is very much a work in progress. Not all instructions are implemented and performance has not been a priority so far.

#### Spec Parser
This project downloads the latest spec and generates C++ files with useful declerations from it. Mostly information about  op codes and structs to represent them to help with parsing and processing.

#### Todo

* SPIR-V Validation ([validation rules described here]( https://www.khronos.org/registry/spir-v/specs/1.0/SPIRV.html#_a_id_validation_a_validation_rules))
* Implement all OpCodes
* Improve performance
* Better human readable parsing output (at least match the reference compiler)

#### Example Code
Input File:  
![Input File](https://raw.githubusercontent.com/bonus2113/otherside/4f9a9b915d84ed1de4681e9d2433c29179134896/data/testin.bmp)

Output File:  
![Output File](https://raw.githubusercontent.com/bonus2113/otherside/4f9a9b915d84ed1de4681e9d2433c29179134896/data/testout.bmp)

Shader code:

    #version 110
    varying vec2 uv;
    uniform sampler2D testTex;

    void main() {
      vec4 col = texture2D(testTex, uv);
      col.rgb = col.rbr;
      gl_FragColor = col;
      gl_FragColor.a = 1.0;
    }
    
C++ code:

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
    
      save_bmp("data/testout.bmp", outTex);
    
      std::cout << " done";
      return 0;
    }
