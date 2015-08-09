cmake_minimum_required (VERSION 3.1)
project (otherside C CXX)

# We need C++ 11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED on)

add_subdirectory(./../shared shared)

include_directories(${CMAKE_SOURCE_DIR}/src/main)
include_directories(${SHARED_LIB_INCLUDE_DIR})

set(SRCS parser.cpp codegen.cpp interpreted_vm.cpp)
add_library(otherside STATIC ${SRCS})

add_executable(otherside_exe otherside_main.cpp)
SET_TARGET_PROPERTIES ( otherside_exe PROPERTIES OUTPUT_NAME otherside)

IF (WIN32)
	target_link_libraries(otherside_exe otherside shared)
ELSE()
	target_link_libraries(otherside_exe otherside shared dl)
ENDIF()

add_test(NAME otherside_exe_end2end COMMAND otherside_exe -i data/light.frag.spv -o data/light.frag.cpp WORKING_DIRECTORY ${CMAKE_SOURCE_DIR})


