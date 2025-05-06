cmake_minimum_required(VERSION 3.16)
project(SudokuSolver)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES
        main.cpp
        generator.cpp
        sudoku.cpp
        sudoku_io.cpp
        utils.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

# Remove this line ↓ (not needed on macOS or modern compilers)
# target_link_libraries(${PROJECT_NAME} stdc++fs)
