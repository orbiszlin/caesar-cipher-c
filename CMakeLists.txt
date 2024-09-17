cmake_minimum_required(VERSION 3.29)
project(cesarova C)

set(CMAKE_C_STANDARD 11)

add_executable(cesarova main.c
        caesar.c
        caesar.h)
