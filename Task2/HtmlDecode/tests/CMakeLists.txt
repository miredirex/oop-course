cmake_minimum_required(VERSION 3.16)
project(HtmlDecode)

set(CMAKE_CXX_STANDARD 17)

add_executable(HtmlDecodeTests catch_runner.h htmldecode_tests.cpp ../src/htmldecode.cpp)