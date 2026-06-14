cmake_minimum_required(VERSION 4.2)
project(clox7 C)

set(CMAKE_C_STANDARD 23)

add_executable(clox7 main.c
        common.h
        chunk.h
        chunk.c
        memory.c
        memory.h
        debug.h
        debug.c)
