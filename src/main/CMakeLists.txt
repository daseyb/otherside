cmake_minimum_required (VERSION 2.8)
project (otherside C CXX)

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

add_subdirectory(./../shared shared)

include_directories(${CMAKE_SOURCE_DIR}/src/main)
include_directories(${SHARED_LIB_INCLUDE_DIR})

set(SRCS otherside_main.cpp parser.cpp codegen.cpp interpreted_vm.cpp)
add_executable(otherside ${SRCS})

IF (WIN32)
	target_link_libraries(otherside shared)
ELSE()
	target_link_libraries(otherside shared dl)
ENDIF()

