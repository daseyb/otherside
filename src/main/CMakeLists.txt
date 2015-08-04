cmake_minimum_required (VERSION 2.8)
project (otherside C CXX)

# We need C++ 11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED on)

add_subdirectory(./../shared shared)

include_directories(${SHARED_LIB_INCLUDE_DIR})

set(SRCS otherside_main.cpp parser.cpp codegen.cpp interpreted_vm.cpp)
add_executable(otherside ${SRCS})

target_link_libraries(otherside shared dl)
