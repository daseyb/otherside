cmake_minimum_required (VERSION 2.8)
project (ext C CXX)

# We need C++ 11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED on)

add_subdirectory(glsl.std.450)
