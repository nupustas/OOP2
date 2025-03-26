cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)

project(OOP)

set(CMAKE_CXX_COMPILER g++)

include_directories(include)

add_executable(OOP src/main.cpp)
