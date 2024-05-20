cmake_minimum_required(VERSION 3.25.0)

set(This Main_CMakeLists)

project(Program)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()

add_subdirectory(googletest)

set(Headers 
    Studentas.h
    MainHeader.h
    vectorClass.h
)

set(Source 
    Studentas.cpp
    Main.cpp
    vectorClass.cpp
)

add_library(${This} STATIC ${Source} ${Headers})

add_subdirectory(Unit_Tests)
add_executable(Program Main.cpp Studentas.cpp)