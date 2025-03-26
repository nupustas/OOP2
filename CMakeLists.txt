cmake_minimum_required(VERSION 3.10)
project(OOP)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Optimization flags based on compiler
if (MSVC)
    set(CMAKE_CXX_FLAGS_DEBUG "/O2")  # Use /O2 for MSVC
else()
    set(CMAKE_CXX_FLAGS_DEBUG "-O3")  # Use -O3 for GCC/Clang
endif()

include_directories(include)

add_executable(OOP src/main.cpp)
