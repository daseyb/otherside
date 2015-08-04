cmake_minimum_required (VERSION 2.6)
project (otherside)

add_subdirectory(./../shared shared)

include_directories(${SHARED_LIB_INCLUDE_DIR})

set(SRCS otherside_main.cpp parser.cpp codegen.cpp interpreted_vm.cpp)
add_executable(otherside ${SRCS})

target_link_libraries(otherside shared)

set_property(TARGET otherside PROPERTY CXX_STANDARD 11)