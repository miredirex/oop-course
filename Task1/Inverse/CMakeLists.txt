cmake_minimum_required(VERSION 3.15)
project(inverse)

set(CMAKE_CXX_STANDARD 17)

add_executable(inverse main.cpp matrix3x3.cpp matrix3x3.h matrix2x2.cpp matrix2x2.h matrix_io.cpp matrix_io.h)