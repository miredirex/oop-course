cmake_minimum_required(VERSION 3.15)
project(VectorBasics)

set(CMAKE_CXX_STANDARD 17)

add_executable(VectorBasics main.cpp vector_io.cpp vector_io.h vector_process.cpp vector_process.h)