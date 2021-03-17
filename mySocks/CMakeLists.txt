cmake_minimum_required(VERSION 3.17)
project(mySocks)

set(CMAKE_CXX_STANDARD 14)

add_executable(mySocks main.cpp common.cpp common.h client.cpp client.h server.cpp server.h socks5.cpp socks5.h exception.h config.cpp config.h aes/aes.hpp aes/aes.h aes/aes.c)