#ifndef SUDOKU_IO_H
#define SUDOKU_IO_H

#include <string>

void printBoard(int board[9][9]);
bool loadBoardFromFile(const std::string& filename, int board[9][9]);
bool saveBoardToFile(const std::string& filename, int board[9][9]);

#endif // SUDOKU_IO_H
