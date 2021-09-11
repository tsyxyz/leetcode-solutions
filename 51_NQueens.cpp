#include <gtest/gtest.h>

#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        n_ = n;
        colAvailable_.resize(n, true);
        mainAvailable_.resize(2 * n - 1, true);
        subAvailable_.resize(2 * n - 1, true);

        vector<int> path;
        dfs(0, path);
        return result_;
    }

    void dfs(int row, vector<int>& colPath) {
        if (row == n_) {
            vector<string> board = pathToBoard(colPath);
            result_.push_back(board);
            return;
        }

        for (int c = 0; c < n_; ++c) {
            if (colAvailable_[c] && mainAvailable_[row - c + n_ - 1] && subAvailable_[row + c]) {
                colPath.push_back(c);
                colAvailable_[c] = false;
                mainAvailable_[row - c + n_ - 1] = false;
                subAvailable_[row + c] = false;
                dfs(row + 1, colPath);
                colAvailable_[c] = true;
                mainAvailable_[row - c + n_ - 1] = true;
                subAvailable_[row + c] = true;
                colPath.pop_back();
            }
        }
    }

    vector<string> pathToBoard(const vector<int>& path) {
        vector<string> board;
        for (int i = 0; i < static_cast<int>(path.size()); ++i) {
            string row;
            for (int j = 0; j < n_; ++j) {
                if (j == path[i]) row.push_back('Q');
                else row.push_back('.');
            }
            board.push_back(row);
        }
        return board;
    }

private:
    int n_;
    vector<bool> colAvailable_;
    vector<bool> mainAvailable_;
    vector<bool> subAvailable_;
    vector<vector<string>> result_;
};

TEST(Test_51, case_01) {
    Solution s;
    int n = 4;
    auto result = s.solveNQueens(n);
    for (int i = 0; i < static_cast<int>(result.size()); ++i) {
        for (int r = 0; r < n; ++r) {
            cout << result[i][r] << endl;
        }
        cout << "---" << endl;
    }
}