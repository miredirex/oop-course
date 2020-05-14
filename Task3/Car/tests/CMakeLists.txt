add_executable(CarTests CarTest.cpp)

target_link_libraries(CarTests PRIVATE CarLib)

# Include Catch2
target_include_directories(CarTests PRIVATE ../../../catch2)