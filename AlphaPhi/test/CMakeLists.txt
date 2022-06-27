cmake_minimum_required(VERSION 3.5)
project(Test)
set(CMAKE_CXX_FLAGS "-O0 -std=c++17")
add_executable(mainTest test_tensor.cpp)

target_include_directories(mainTest PRIVATE ../)