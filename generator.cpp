#include "generator.h"
#include "sudoku.h"
#include "utils.h"  // ✅ include to use initializeBoard()
#include <algorithm>
#include <random>
#include <chrono>
#include <cstring>

/**
 * Fills the board with a complete valid solution using basic solving.
 */
void generateCompleteBoard(int board[9][9]) {
    initializeBoard(board);
    solveBasic(board);
    shuffleBoard(board);
}

/**
 * Generates a playable puzzle by removing a fixed number of cells from a full board.
 */
void generatePuzzle(int board[9][9], int clues) {
    generateCompleteBoard(board);

    int cellsToRemove = 81 - clues;
    std::vector<std::pair<int, int>> positions;
    for (int r = 0; r < 9; r++) {
        for (int c = 0; c < 9; c++) {
            positions.emplace_back(r, c);
        }
    }
    std::shuffle(positions.begin(), positions.end(), std::default_random_engine(std::random_device{}()));

    for (int i = 0; i < cellsToRemove; ++i) {
        board[positions[i].first][positions[i].second] = 0;
    }
}

/**
 * Randomly swaps rows and columns within 3x3 blocks to shuffle a board.
 */
void shuffleBoard(int board[9][9]) {
    std::random_device rd;
    std::mt19937 g(rd());

    for (int i = 0; i < 3; ++i) {
        int rows[3] = {i * 3, i * 3 + 1, i * 3 + 2};
        std::shuffle(rows, rows + 3, g);
        int temp[9][9];
        memcpy(temp, board, sizeof(temp));
        for (int r = 0; r < 3; ++r)
            memcpy(board[rows[r]], temp[i * 3 + r], sizeof(int) * 9);
    }

    for (int i = 0; i < 3; ++i) {
        int cols[3] = {i * 3, i * 3 + 1, i * 3 + 2};
        std::shuffle(cols, cols + 3, g);
        int temp[9][9];
        memcpy(temp, board, sizeof(temp));
        for (int r = 0; r < 9; ++r)
            for (int c = 0; c < 3; ++c)
                board[r][i * 3 + c] = temp[r][cols[c]];
    }
}
