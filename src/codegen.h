#pragma once
#include <sstream>

struct Program;

bool genCode(std::stringstream* ss, const Program& prog);