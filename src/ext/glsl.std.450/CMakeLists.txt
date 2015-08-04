cmake_minimum_required (VERSION 2.6)
project (glsl.std.450)

add_subdirectory(./../../shared shared)

include_directories(${SHARED_LIB_INCLUDE_DIR})

set(SRCS glsl.std.450.cpp)
add_library(glsl.std.450 MODULE ${SRCS})
target_link_libraries(glsl.std.450 shared)