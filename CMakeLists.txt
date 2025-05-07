cmake_minimum_required(VERSION 3.16)
project(SudokuSolver)

# Use modern C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# List of source files
set(SOURCES
        main.cpp
        generator.cpp
        sudoku.cpp
        sudoku_io.cpp
        utils.cpp
)

# Create the executable from the sources
add_executable(${PROJECT_NAME} ${SOURCES})

# Add current source directory to the include path
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

# No need to link stdc++fs with C++20 or newer
