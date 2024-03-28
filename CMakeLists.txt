cmake_minimum_required(VERSION 3.27)
project(Schiffe_versenken)

set(CMAKE_CXX_STANDARD 17)

add_executable(Schiffe_versenken main.cpp
        Source/Gameboard.cpp
        Header/Gameboard.h
        Header/Spieler.h
        Source/Spieler.cpp)
