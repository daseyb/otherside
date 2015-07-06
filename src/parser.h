#pragma once
#include "types.h"
#include <string>
#include <memory>

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

  bool ParseProgram(Program* prog);
  uint32* GetBufferPtr() const {
    return bufferStart.get();
  }

};

std::string writeOp(SOp op);
