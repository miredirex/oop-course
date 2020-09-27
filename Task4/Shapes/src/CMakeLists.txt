add_executable(Shapes main.cpp)

target_link_libraries(Shapes ShapesLib)

# Copy SDL2.dll to the build (executable location) folder
# (https://stackoverflow.com/questions/10671916)
add_custom_command(
        TARGET Shapes POST_BUILD        # Adds a post-build event to MyTest
        COMMAND ${CMAKE_COMMAND} -E copy_if_different  # which executes "cmake - E copy_if_different..."
        "${PROJECT_SOURCE_DIR}/SDL2/lib/x86/SDL2.dll"      # <--this is in-file
        $<TARGET_FILE_DIR:Shapes>)                 # <--this is out-file path