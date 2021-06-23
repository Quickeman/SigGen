cmake_minimum_required(VERSION 3.2)

# Project name
project(SigGen)

string(TOLOWER ${CMAKE_PROJECT_NAME} LIB_NAME)

# Generate compile_commands.json for clangd
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

enable_testing()

# Request C++ 11 standard features
set(CMAKE_CXX_STANDARD 11)

# Make sure the compiler looks here for source files
include_directories(/usr/local/include)
link_directories(/usr/local/lib)

include_directories(include/*/)
add_subdirectory(src)
add_subdirectory(test)
