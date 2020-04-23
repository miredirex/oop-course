cmake_minimum_required(VERSION 3.16)
project(HtmlDecode)

set(CMAKE_CXX_STANDARD 17)

add_library(HtmlDecodeLib src/htmldecode.cpp)
target_include_directories(HtmlDecodeLib PUBLIC include)

add_subdirectory(src)
add_subdirectory(tests)