cmake_minimum_required(VERSION 2.8)

project(Task06)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -pthread -Wall -Wextra -Wno-unused-parameter")

add_executable(Task06 main.cpp)

find_package(Boost 1.54.0 COMPONENTS system REQUIRED)
include_directories(${Boost_INCLUDE_DIR})

add_executable(Webserver webserver.cpp)
target_link_libraries(Webserver ${Boost_LIBRARIES})