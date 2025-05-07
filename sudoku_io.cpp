#include "sudoku_io.h"
#include <fstream>
#include <iostream>

/**
 * Writes the Sudoku board to a file.
 * @param filename Path to the output file
 * @param board The 9x9 Sudoku grid
 */
void saveBoardToFile(const std::string& filename, const int board[9][9]) {
    std::ofstream out(filename);
    if (!out) {
        std::cerr << "Failed to open file: " << filename << '\n';
        return;
    }
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            out << board[i][j] << (j == 8 ? '\n' : ' ');
        }
    }
    out.close();
}

/**
 * Reads a Sudoku board from a file.
 * @param filename Path to the input file
 * @param board The 9x9 grid to fill with values
 */
void loadBoardFromFile(const std::string& filename, int board[9][9]) {
    std::ifstream in(filename);
    if (!in) {
        std::cerr << "Failed to open file: " << filename << '\n';
        return;
    }
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            in >> board[i][j];
        }
    }
    in.close();
}
