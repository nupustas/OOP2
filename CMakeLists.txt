cmake_minimum_required(VERSION 3.10)
project(OOP)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)



include_directories(include)

add_executable(OOP src/main.cpp)


add_executable(tests
    src/tests.cpp
)

include_directories(include/catch.hpp)


enable_testing()
add_test(NAME UnitTest COMMAND UnitTest)