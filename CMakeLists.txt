# Specify the minimum version for CMake

cmake_minimum_required(VERSION 2.8)

# Project's name

project(cpp_practice)


# Set the output folder where your program will be created
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/build)

# The following folders will be included
include_directories("${PROJECT_SOURCE_DIR}/src")
include_directories("${PROJECT_SOURCE_DIR}/include")


add_executable (
    cpp_practice 
    src/main.cpp
    src/exceptions.cpp
    src/files.cpp
    src/stl.cpp
    src/opoverload.cpp
    src/templates.cpp
    src/passingFunctions.cpp
    )