cmake_minimum_required (VERSION 2.8)
project (otherside)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED on)

add_subdirectory(src/main)
add_subdirectory(src/shared)
add_subdirectory(src/ext)
