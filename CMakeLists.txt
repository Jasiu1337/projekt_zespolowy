cmake_minimum_required(VERSION 3.26)
project(projekt_zespolowy)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(projekt_zespolowy
        Course.cpp
        Course.h
        Department.cpp
        Department.h
        main.cpp
        Student.cpp
        Student.h
        Teacher.cpp
        Teacher.h
        University.cpp
        University.h
        interface.cpp
        interface.h)
