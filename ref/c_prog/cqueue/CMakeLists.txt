cmake_minimum_required(VERSION 3.29)
project(cqueue C)

set(CMAKE_C_STANDARD 11)

add_executable(cqueue main.c
        queue.c
        queue.h)
