cmake_minimum_required(VERSION 3.15)
project(Task01_1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -pthread -Wall -Wextra -Wno-unused-parameter")

add_executable(Task01_1 main.cpp)