add_executable(MiniDictionaryTests DictionaryTests.cpp)

target_link_libraries(MiniDictionaryTests PRIVATE MiniDictionaryLib)

# Include Catch2
target_include_directories(MiniDictionaryTests PRIVATE ../../../catch2)