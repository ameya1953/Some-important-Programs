#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
private:
    bool isSafe(int row, int col, vector<vector<char>>& board, char val) {
        for (int i = 0; i < 9; i++) {
            // Row check
            if (board[row][i] == val) {
                return false;
            }
            // Column check
            if (board[i][col] == val) {
                return false;
            }
            // Checking 3x3 matrix
            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == val) {
                return false;
            }
        }
        return true;
    }

    bool solve(vector<vector<char>>& board) {
        int n = board.size();

        // All the empty places will have '.'
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == '.') {
                    for (char val = '1'; val <= '9'; val++) {
                        if (isSafe(i, j, board, val)) {
                            board[i][j] = val;

                            bool aageSolutionPossible = solve(board);
                            if (aageSolutionPossible) {
                                return true;
                            } else {
                                // Backtrack
                                board[i][j] = '.';
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

public:
    void solveSudoku(vector<vector<char>>& sudoku) {
        solve(sudoku);
    }
};