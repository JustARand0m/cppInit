cmake_minimum_required(VERSION 3.4)
project(ProjectName)

include_directories("./")
add_executable(executable main.cpp createFile.h createFile.cpp)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall")
