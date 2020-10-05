cmake_minimum_required(VERSION 3.15)
project(Task02)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=thread -pthread -std=c++1y -Wall -Wextra")

add_executable(Task02 main.cpp Workers.cpp Workers.h)