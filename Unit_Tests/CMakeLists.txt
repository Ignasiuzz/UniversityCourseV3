cmake_minimum_required(VERSION 3.25.0)

set(This Test_CMake)

set(Source 
    Unit_Test.cpp
)

add_executable(${This} ${Source})

target_link_libraries(${This} PUBLIC 
    gtest_main
    Main_CMakeLists
)

add_test(
    NAME ${This}
    COMMAND ${This}
)