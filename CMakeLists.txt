cmake_minimum_required(VERSION 3.28)

set(CMAKE_CXX_STANDARD 20)

project(matmod)

add_library(fraction src/fraction.cpp src/fraction.h)
add_library(smatrix src/smatrix.cpp src/smatrix.h)

add_executable(matmod src/main.cpp)

target_link_libraries(smatrix PRIVATE fraction)
target_link_libraries(matmod PRIVATE smatrix)
