cmake_minimum_required(VERSION 3.1)

project(shared C CXX)

set(SHARED_LIB_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR})

set(SHARED_LIB_INCLUDE_DIR ${SHARED_LIB_INCLUDE_DIR} PARENT_SCOPE)

if(TARGET shared)

message("shared is already defined")

else()

include_directories(${SHARED_LIB_INCLUDE_DIR})

set(SRCS lookups.cpp lookups_gen.cpp utils.cpp)

# We need C++ 11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED on)

add_library(shared STATIC ${SRCS})

endif()

