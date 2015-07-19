#pragma once
#include <sstream>

struct Program;

bool genCode(std::stringstream* ss, const Program& prog);

bool genCode(const char* outFileName, const Program& prog);