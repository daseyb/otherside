cmake_minimum_required (VERSION 3.1)
project (disassembler C CXX)

# We need C++ 11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED on)

add_subdirectory(./../../shared shared)

include_directories(${CMAKE_SOURCE_DIR}/src/main)
include_directories(${SHARED_LIB_INCLUDE_DIR})

add_executable(disassembler disassembler_main.cpp)

IF (WIN32)
	target_link_libraries(disassembler otherside shared)
ELSE()
	target_link_libraries(disassembler otherside shared dl)
ENDIF()