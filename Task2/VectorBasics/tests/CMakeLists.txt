cmake_minimum_required(VERSION 3.15)
project(VectorBasics)

set(CMAKE_CXX_STANDARD 17)

add_executable(VectorBasicsTests catch_runner.h vector_process_tests.cpp ../src/vector_process.cpp)