cmake_minimum_required(VERSION 3.12.2)
project(Vacuum_Cleaner_AI)

set(CMAKE_CXX_STANDARD 17)

set(GCC_COVERAGE_COMPILE_FLAGS "-O3 -Wall")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")

add_executable(Vacuum_Cleaner_AI main.cpp
        Simulator.h Simulator.cpp
        Environment.h Environment.cpp
        Agent.h Agent.cpp
        Structs.h Enums.h
        Logger.h Logger.cpp)
