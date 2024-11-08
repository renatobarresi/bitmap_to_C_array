# Minimum CMake version required
cmake_minimum_required(VERSION 3.30)

set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

# Project name and version
project(bitmapToCArray VERSION 1.1
    DESCRIPTION "Program that converts a bitmap to a C array"
    HOMEPAGE_URL "https://github.com/renatobarresi/bitmap_to_C_array"
    LANGUAGES CXX
)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the executable
add_executable(bitmapToCArray 
    ${PROJECT_SOURCE_DIR}/src/main.cpp
    ${PROJECT_SOURCE_DIR}/src/parser.cpp
    ${PROJECT_SOURCE_DIR}/src/arrayGenerator.cpp
)

# Add the headers directory to the include path
target_include_directories(bitmapToCArray PRIVATE
    ${PROJECT_SOURCE_DIR}/inc
)

target_compile_options(bitmapToCArray PRIVATE
    -g3 -ggdb
)
