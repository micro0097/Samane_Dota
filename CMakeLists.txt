cmake_minimum_required(VERSION 3.27)
project(samanedota)

set(CMAKE_CXX_STANDARD 17)

add_executable(new_target
        main.cpp
        Admin.cpp
        Admin.h
        Course.cpp
        Course.h
        Professor.cpp
        Professor.h
        Person.cpp
        Person.h
        Student.cpp
        Student.h
        homework.cpp
        homework.h
)
