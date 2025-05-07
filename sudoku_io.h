#ifndef SUDOKU_IO_H
#define SUDOKU_IO_H

#include <string>

/**
 * Reads a Sudoku board from a file.
 *
 * @param filename The name of the file to read from.
 * @param board The 9x9 Sudoku grid to fill.
 * @return true if the board was successfully loaded, false otherwise.
 */
bool readBoardFromFile(const std::string& filename, int board[9][9]);

/**
 * Writes a Sudoku board to a file.
 *
 * @param filename The name of the file to write to.
 * @param board The 9x9 Sudoku grid to write.
 */
void writeBoardToFile(const std::string& filename, int board[9][9]);

#endif // SUDOKU_IO_H
