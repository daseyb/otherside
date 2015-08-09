#pragma once
#include <ostream>

struct Program;

bool validate(Program prog, std::ostream& errorOut);