# Require CMake version 3.10 or higher
cmake_minimum_required(VERSION 3.10)

# Set the name of your project
project(Simpler-Mch)

# Specify the C++ standard to use (e.g., C++14)
# set(CMAKE_CXX_STANDARD 14)
# set(CMAKE_CXX_STANDARD_REQUIRED True)

# Tell CMake to create an executable named "hello" from main.cpp
add_executable(main src/main.cpp)
