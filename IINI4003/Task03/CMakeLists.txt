cmake_minimum_required(VERSION 2.8)

project(Task03)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -Wall -Wextra")

add_executable(Task03 main.cpp)
add_executable(Commodity commoditytest.cpp)
add_executable(Oppgave4 oppg4.cpp)
