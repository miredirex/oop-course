cmake_minimum_required(VERSION 3.16)
project(MiniDictionary)

set(CMAKE_CXX_STANDARD 17)

add_library(MiniDictionaryLib src/Dictionary.cpp src/DictionaryIO.cpp include/dictionary/DictionaryApplication.h src/DictionaryApplication.cpp src/StringUtils.cpp)
target_include_directories(MiniDictionaryLib PUBLIC include)

add_subdirectory(src)