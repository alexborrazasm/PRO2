cmake_minimum_required(VERSION 3.27)
project(Rational C)

set(CMAKE_C_STANDARD 99)

add_executable(Rational main.c
        Rational_pointer.c
        Rational_pointer.h
        Rational_struct.c
        Rational_struct.h)
add_executable(Rational_struct main.c
        Rational_struct.c
        Rational_struct.h)
add_executable(Rational_pointer main.c
        Rational_pointer.c
        Rational_pointer.h)