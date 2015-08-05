cmake_minimum_required (VERSION 2.8)
project (glsl.std.450 C CXX)

# We need C++ 11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED on)

if(UNIX)
    # only build 32-bit binaries
    add_definitions(-m32)
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -m32")
    set(CMAKE_SHARED_LIBRARY_C_FLAGS "${CMAKE_SHARED_LIBRARY_C_FLAGS} -m32")
    set(CMAKE_SHARED_LIBRARY_CXX_FLAGS "${CMAKE_SHARED_LIBRARY_CXX_FLAGS} -m32")
endif()

add_subdirectory(./../../shared shared)

include_directories(${SHARED_LIB_INCLUDE_DIR})

set(SRCS glsl.std.450.cpp)
add_library(glsl.std.450 MODULE ${SRCS})
target_link_libraries(glsl.std.450 shared)

set_property(TARGET glsl.std.450 PROPERTY CXX_STANDARD 11)
