cmake_minimum_required(VERSION 3.20)
project(rand C)

set(CMAKE_C_STANDARD 11)

add_executable(rand result.c ra.h ht.h)
