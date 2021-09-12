#include <gtest/gtest.h>

#include <vector>

using namespace std;

//// !!答案不对
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        size_t rows = board.size();
        size_t cols = board[0].size();
        for (size_t r = 0; r < rows; ++r) {
            for (size_t c = 0; c < cols; ++c) {
                if (board[r][c] == '.') {
                    allIndexToFill_.push_back(vector<size_t>{r, c});
                }
            }
        }
        dfs(0, board);
    }

private:
    void dfs(size_t indexToFillInd, vector<vector<char>>& board) {
        if (indexToFillInd == allIndexToFill_.size()) {
            return;
        }
        for (char ch = '1'; ch <= '9'; ++ch) {
            size_t row = allIndexToFill_[indexToFillInd][0];
            size_t col = allIndexToFill_[indexToFillInd][1];
            if (checkFill(board, row, col, ch)) {
                fillBoard(board, row, col, ch);
                dfs(indexToFillInd + 1, board);
                revertBoard(board, row, col);
            }
        }
    }

    bool checkFill(const vector<vector<char>>& board, size_t row, size_t col, char ch) {
        for (size_t i = 0; i < 9; ++i) {
            if (board[row][i] == ch ||
                board[i][col] == ch) {
                return false;
            }
        }

        size_t gridRow = row / 3;
        size_t gridCol = col / 3;
        for (size_t j = 0; j < 3; ++j) {
            for (size_t k = 0; k < 3; ++k) {
                if (board[gridRow + j][gridCol + k] == ch) {
                    return false;
                }
            }
        }
        return true;
    }

    void fillBoard(vector<vector<char>>& board, size_t row, size_t col, char ch) {
        board[row][col] = ch;
    }

    void revertBoard(vector<vector<char>>& board, size_t row, size_t col) {
        board[row][col] = '.';
    }
private:
    vector<vector<size_t>> allIndexToFill_;
};

TEST(Test_37, case_01) {
    vector<vector<char>> board = {
            {'5','3','.','.','7','.','.','.','.'},
            {'6','.','.','1','9','5','.','.','.'},
            {'.','9','8','.','.','.','.','6','.'},
            {'8','.','.','.','6','.','.','.','3'},
            {'4','.','.','8','.','3','.','.','1'},
            {'7','.','.','.','2','.','.','.','6'},
            {'.','6','.','.','.','.','2','8','.'},
            {'.','.','.','4','1','9','.','.','5'},
            {'.','.','.','.','8','.','.','7','9'}
    };

    Solution s;
    s.solveSudoku(board);
    cout << endl;
}