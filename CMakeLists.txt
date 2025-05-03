cmake_minimum_required(VERSION 3.31)
project(SudokuSolverProject)

set(CMAKE_CXX_STANDARD 20)

add_executable(SudokuSolverProject main.cpp
        sudoku.h
        sudoku.cpp
        generator.h
        generator.cpp)
