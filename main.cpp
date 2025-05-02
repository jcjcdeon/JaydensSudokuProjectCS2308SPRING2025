#include <iostream>
#include "generator.h"
#include "sudoku.h"

using namespace std;

#define DEBUG // Comment this line out to disable debug output

// Print the Sudoku board
void printBoard(int board[9][9]) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int board[9][9];

    cout << "Generating Sudoku puzzle..." << endl;
    generatePuzzle(board);

    cout << "\nGenerated Puzzle:\n";
    printBoard(board);

#ifdef DEBUG
    cout << "\n[DEBUG] Validating generated puzzle...\n";
    bool isValid = validatePuzzle(board);
    cout << "[DEBUG] Puzzle is " << (isValid ? "valid" : "invalid") << ".\n";
#endif

    cout << "\nSolving puzzle using basic solver...\n";
    if (solveBasic(board)) {
        cout << "\nSolved Puzzle:\n";
        printBoard(board);
    } else {
        cout << "Failed to solve the puzzle.\n";
    }

    return 0;
}
