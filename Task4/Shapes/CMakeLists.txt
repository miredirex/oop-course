cmake_minimum_required(VERSION 3.16)
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

# SDL2 GFX
set(SDL2_GFX_SOURCE_FILES
        ${PROJECT_SOURCE_DIR}/SDL2_gfx/SDL2_gfxPrimitives.c
        ${PROJECT_SOURCE_DIR}/SDL2_gfx/SDL2_rotozoom.c
        ${PROJECT_SOURCE_DIR}/SDL2_gfx/SDL2_gfxPrimitives.h
        ${PROJECT_SOURCE_DIR}/SDL2_gfx/SDL2_rotozoom.h)

# SDL2
add_library(SDL2 ${SDL2_GFX_SOURCE_FILES})
set_target_properties(SDL2 PROPERTIES LINKER_LANGUAGE C)
target_include_directories(SDL2 PUBLIC ${PROJECT_SOURCE_DIR}/SDL2/include)
target_include_directories(SDL2 PUBLIC ${PROJECT_SOURCE_DIR}/SDL2_gfx)
target_link_libraries(SDL2 ${PROJECT_SOURCE_DIR}/SDL2/lib/x86/SDL2.lib ${PROJECT_SOURCE_DIR}/SDL2/lib/x86/SDL2main.lib)

# Link SDL2 to ShapesLib
target_link_libraries(ShapesLib SDL2)

add_subdirectory(src)
add_subdirectory(tests)