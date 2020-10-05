cmake_minimum_required(VERSION 2.8)

project(Solution08)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -Wall -Wextra")

find_package(OpenSSL REQUIRED)
include_directories(${OPENSSL_INCLUDE_DIR})

add_executable(Solution08 main.cpp)
target_link_libraries(Solution08 ${OPENSSL_CRYPTO_LIBRARY})
