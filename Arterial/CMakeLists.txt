# cmake_minimum_required(VERSION <specify CMake version here>)
project(Arterial)

set(CMAKE_CXX_STANDARD 14)
add_executable(Arterial main.cpp config.cpp config.h server.cpp server.h client.cpp client.h)