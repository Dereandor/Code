cmake_minimum_required(VERSION 2.8)

project(Task04)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -Wall -Wextra -Wno-unused-parameter")

INCLUDE(FindPkgConfig)

pkg_check_modules(GTKMM gtkmm-3.0 REQUIRED)
include_directories(${GTKMM_INCLUDE_DIRS})
link_directories(${GTKMM_LIBRARY_DIRS})

add_executable(Task04 main.cpp)

add_executable(Oppgave2 oppg2.cpp)
target_link_libraries(Oppgave2 ${GTKMM_LIBRARIES})
