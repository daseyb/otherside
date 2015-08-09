cmake_minimum_required (VERSION 3.1)
project (otherside_test C CXX)

# We need C++ 11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED on)

add_subdirectory(./../shared shared)

include_directories(${CMAKE_SOURCE_DIR}/src/main)
include_directories(${SHARED_LIB_INCLUDE_DIR})

add_executable(otherside_test_parser otherside_test_parser.cpp)
add_executable(otherside_test_codegen otherside_test_codegen.cpp)

IF (WIN32)
	target_link_libraries(otherside_test_parser otherside shared)
	target_link_libraries(otherside_test_codegen otherside shared)
ELSE()
	target_link_libraries(otherside_test_parser otherside shared dl)
	target_link_libraries(otherside_test_codegen otherside shared dl)
ENDIF()

add_test(NAME parser_test COMMAND otherside_test_parser data/light.frag.spv WORKING_DIRECTORY ${CMAKE_SOURCE_DIR})
add_test(NAME codegen_test COMMAND otherside_test_codegen data/light.frag.spv data/light.frag.cpp WORKING_DIRECTORY ${CMAKE_SOURCE_DIR})