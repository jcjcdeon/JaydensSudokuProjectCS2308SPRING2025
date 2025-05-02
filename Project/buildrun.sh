#!/bin/bash

# Compiler and output
CXX=g++
OUT=main.out

# Source files
SRC="main.cpp generator.cpp sudoku.cpp sudoku_io.cpp utils.cpp"

# Default compilation flags
CXXFLAGS="-std=c++11 -Wall -Wextra"

# Check for DEBUG flag
if [[ "$1" == "debug" ]]; then
    echo "Compiling in DEBUG mode..."
    CXXFLAGS="$CXXFLAGS -DDEBUG"
else
    echo "Compiling in RELEASE mode..."
fi

# Create data folder if it doesn't exist
mkdir -p data

# Compile
echo "Building..."
$CXX $CXXFLAGS -o $OUT $SRC

# Check if build succeeded
if [ $? -eq 0 ]; then
    echo "Build succeeded. Running program..."
    echo "==========================="
    ./$OUT
else
    echo "Build failed."
    exit 1
fi
