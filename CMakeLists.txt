cmake_minimum_required(VERSION 2.8)
project(http_client)

set(CMAKE_C_FLAGS "${CMAKE_CXX_FLAGS} -std=c99 -Wall -Wextra -Werror -pedantic")

set(CMAKE_C_FLAGS_DEBUG "-O0 -g -D_DEBUG")
set(CMAKE_C_FLAGS_RELEASE "-O3")
set(CMAKE_C_FLAGS_MINSIZEREL "-Os")
set(CMAKE_C_FLAGS_RELWITHDEBINFO "-O2 -g")

add_subdirectory(src/)
add_subdirectory(test/)
