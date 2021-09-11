#include <gtest/gtest.h>

#include <vector>

using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (board[r][c] == '.') {
                    indexToFill_.push_back(r * cols + c);
                }
            }
        }

        for (int i = 0; i)
    }

private:
    vector<int> indexToFill_;
};