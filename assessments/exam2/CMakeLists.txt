cmake_minimum_required(VERSION 3.29)
project(Exam2)

set(CMAKE_CXX_STANDARD 20)

add_executable(exam2 main.cpp
        Person.cpp
        Person.h
        FloatVector.cpp
        FloatVector.h
)
