cmake_minimum_required(VERSION 3.16)
project(Car)

set(CMAKE_CXX_STANDARD 17)

add_library(CarLib src/Car.cpp src/IntRange.cpp)
target_include_directories(CarLib PUBLIC include)

add_subdirectory(src)
add_subdirectory(tests)