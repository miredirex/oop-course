add_executable(ShapesTest ShapesTest.cpp)

target_link_libraries(ShapesTest PRIVATE ShapesLib)

# Include Catch2
target_include_directories(ShapesTest PRIVATE ../../../catch2)