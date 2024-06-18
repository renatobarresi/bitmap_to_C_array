# Minimum CMake version required
cmake_minimum_required(VERSION 3.10)

# Project name and version
project(bitmapToCArray VERSION 1.0)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the headers directory to the include path
include_directories(${PROJECT_SOURCE_DIR}/inc)

# Add the executable
add_executable(bitmapToCArray 
${PROJECT_SOURCE_DIR}/src/main.cpp
${PROJECT_SOURCE_DIR}/src/parser.cpp
${PROJECT_SOURCE_DIR}/src/arrayGenerator.cpp)

