cmake_minimum_required(VERSION 3.15)
project(replace)

set(CMAKE_CXX_STANDARD 14)

add_executable(replace main.cpp replacer.cpp replacer.h)