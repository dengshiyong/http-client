cmake_minimum_required(VERSION 2.8)
project(http_client)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c99 -Wall -Wextra -Werror -pedantic")

add_subdirectory(src/)
add_subdirectory(test/)
