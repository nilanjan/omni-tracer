cmake_minimum_required(VERSION 3.8)

project(omni_gen)

file(GLOB SOURCES "src/*.cpp")
file(GLOB HEADERS "src/*.hpp")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -isystem")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wall -isystem")

set(LIBRARY_OUTPUT_PATH  ${CMAKE_BINARY_DIR}/lib)

add_library(${PROJECT_NAME} SHARED ${SOURCES} ${HEADERS})
