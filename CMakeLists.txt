cmake_minimum_required(VERSION 3.10)
# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)

# Set the project name
project(MyProject)

# Add include directories
include_directories(include)

# Define your executable
add_executable(MyProject src/main.cpp)


