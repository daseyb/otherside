cmake_minimum_required(VERSION 2.6)

set(SHARED_LIB_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR})

set(SHARED_LIB_INCLUDE_DIR ${SHARED_LIB_INCLUDE_DIR} PARENT_SCOPE)

if(TARGET shared)

message("shared is already defined")

else()

include_directories(${SHARED_LIB_INCLUDE_DIR})

set(SRCS lookups.cpp lookups_gen.cpp)
add_library(shared STATIC ${SRCS})

set_property(TARGET shared PROPERTY CXX_STANDARD 11)

endif()

