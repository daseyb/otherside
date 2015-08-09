#pragma once
#include "types.h"
#include <string>
#include <assert.h>
#include <memory>
#include <fstream>
#include <iostream>

struct Program;
struct SOp;

class Parser {
private:
  std::unique_ptr<uint32> bufferStart;
  uint32* buffer;
  int length;
  int index;

  uint32 get() const;
  bool end() const;
  void eat();
  uint32 getAndEat();
  bool expectAndEat(uint32 e);
  bool expect(uint32 e) const;
  SOp readInstruction();

public:
  Parser(int length) {
    this->index = 0;
    this->length = length;
    this->bufferStart = std::unique_ptr<uint32>(new uint32[length]);
    this->buffer = bufferStart.get();
  }

  Parser(const char* inputFileName) {
    assert(inputFileName);

    this->index = 0;

    std::ifstream inputFile;

    inputFile.open(inputFileName, std::ifstream::in | std::ifstream::binary);
    assert(inputFile.is_open());
    inputFile.seekg(0, std::ios::end);
    std::streamsize size = inputFile.tellg();
    inputFile.seekg(0, std::ios::beg);
    assert(size % 4 == 0);

    this->length = size / 4;
    this->bufferStart = std::unique_ptr<uint32>(new uint32[length]);
    this->buffer = bufferStart.get();

    if (!inputFile.read((char*)GetBufferPtr(), size)) {
      std::cout << "Could not read file." << std::endl;
    }
    
    inputFile.close();
  }

  bool ParseProgram(Program* prog);
  uint32* GetBufferPtr() const {
    return bufferStart.get();
  }

};

std::string writeProgram(const Program& prog);
std::string writeOp(SOp op);
