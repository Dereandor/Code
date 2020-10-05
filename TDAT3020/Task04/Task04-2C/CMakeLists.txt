cmake_minimum_required(VERSION 3.17)
project(Task04_2 C)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c11 -Wall -Wextra")

add_executable(Task04_2 main.c tests/utility_fuzzer_test.c tests/utility_test.c utility.h)