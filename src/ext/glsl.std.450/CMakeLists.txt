cmake_minimum_required (VERSION 3.1)
project (glsl.std.450 C CXX)

# We need C++ 11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED on)

add_subdirectory(./../../shared shared)

include_directories(${SHARED_LIB_INCLUDE_DIR})

set(SRCS glsl.std.450.cpp)
add_library(glsl.std.450 MODULE ${SRCS})
target_link_libraries(glsl.std.450 shared)

set_property(TARGET glsl.std.450 PROPERTY CXX_STANDARD 11)

add_custom_command(TARGET glsl.std.450 POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:glsl.std.450> ${CMAKE_SOURCE_DIR}/ext/
)
  
file(COPY DESTINATION ${CMAKE_SOURCE_DIR}/ext)