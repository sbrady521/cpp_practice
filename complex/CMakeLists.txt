# Specify the minimum version for CMake

cmake_minimum_required(VERSION 2.8)

# Project's name

project(complex)


# Set the output folder where your program will be created
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/build)

# The following folders will be included
include_directories("${PROJECT_SOURCE_DIR}")


add_executable (
    complex 
    main.cpp
    complex.cpp
    )