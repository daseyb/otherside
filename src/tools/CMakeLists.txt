cmake_minimum_required (VERSION 3.1)
project (tools C CXX)

# We need C++ 11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED on)

add_subdirectory(disassembler)
