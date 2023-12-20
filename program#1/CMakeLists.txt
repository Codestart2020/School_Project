cmake_minimum_required(VERSION 3.26)
project(program_1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(program_1
        csc331_prog1_nixon.cpp
        personType.h)
