cmake_minimum_required(VERSION 4.0)
project(Project)

set(CMAKE_CXX_STANDARD 11)

add_executable(Project
        constants.h
        Menu.cpp
        Menu.h
        Utils.h
        Utils.cpp
        Drink.cpp
        Drink.h
        Food.cpp
        Food.h
        Billable.cpp
        Billable.h
        Ordering.cpp
        Ordering.h
        ms56.cpp)
