cmake_minimum_required(VERSION 3.16)

# Setup vcpkg
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_CURRENT_SOURCE_DIR}/../../vcpkg/scripts/buildsystems/vcpkg.cmake
        CACHE STRING "Vcpkg toolchain file")

project(Shapes)
set(CMAKE_CXX_STANDARD 17)

set(Shapes_SOURCE_FILES
        src/Point.cpp
        src/ShapeInputPatterns.cpp
        src/Scene.cpp
        src/shape/Circle.cpp
        src/shape/LineSegment.cpp
        src/shape/Rectangle.cpp
        src/shape/Triangle.cpp
        src/canvas/SDLCanvas.cpp
        src/calculation/Calculations.cpp)

add_library(ShapesLib ${Shapes_SOURCE_FILES})
target_include_directories(ShapesLib PUBLIC include)

# SDL2
find_package(SDL2 CONFIG REQUIRED)

# SDL2 GFX
find_package(sdl2-gfx CONFIG REQUIRED)

target_link_libraries(ShapesLib PUBLIC SDL2::SDL2 SDL2::SDL2main)
target_link_libraries(ShapesLib PRIVATE SDL2::SDL2_gfx)

add_subdirectory(src)
add_subdirectory(tests)