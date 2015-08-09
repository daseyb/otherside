#pragma once
#include <ostream>

struct Program;

bool validate(const Program& prog, std::ostream& errorOut);