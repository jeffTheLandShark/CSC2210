cmake_minimum_required(VERSION 3.29)
project(SPA6)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(SPA6
    cow_string.cpp
    cow_string.h
    main.cpp)
