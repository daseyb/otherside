cmake_minimum_required (VERSION 2.6)
project (Otherside)

add_subdirectory(./../shared shared)

include_directories(${SHARED_LIB_INCLUDE_DIR})

set(SRCS otherside_main.cpp parser.cpp codegen.cpp lookups.cpp lookups_gen.cpp interpreted_vm.cpp)
add_executable(Otherside ${SRCS})