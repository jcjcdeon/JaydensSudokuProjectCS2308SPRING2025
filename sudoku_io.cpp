#include "sudoku_io.h"
#include <iostream>
#include <fstream>


void printBoard(int board[9][9]) {
    for (int row = 0; row < 9; ++row) {
        if (row % 3 == 0 && row != 0)
            std::cout << "------+-------+------\n";
        for (int col = 0; col < 9; ++col) {
            if (col % 3 == 0 && col != 0)
                std::cout << "| ";
            std::cout << board[row][col] << " ";
        }
        std::cout << "\n";
    }
}

// Load a board from a file (plain text: 81 integers)
bool loadBoardFromFile(const std::string& filename, int board[9][9]) {
    std::ifstream infile(filename);
    if (!infile.is_open()) return false;

    for (int row = 0; row < 9; ++row) {
        for (int col = 0; col < 9; ++col) {
            infile >> board[row][col];
            if (infile.fail()) return false;
        }
    }

    return true;
}

// Save a board to a file (plain text: 9x9 grid)
bool saveBoardToFile(const std::string& filename, int board[9][9]) {
    std::ofstream outfile(filename);
    if (!outfile.is_open()) return false;

    for (int row = 0; row < 9; ++row) {
        for (int col = 0; col < 9; ++col) {
            outfile << board[row][col] << " ";
        }
        outfile << "\n";
    }

    return true;
}
