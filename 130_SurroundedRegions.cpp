#include <vector>

#include <gtest/gtest.h>

using namespace std;

class UnionFind {
public:
    UnionFind(const vector<vector<char>>& board) {
        parent_.resize(board.size() * board[0].size() + 1, 0);
        size_.resize(board.size() * board[0].size() + 1, 0);
        parent_[parent_.size() - 1] = parent_.size() - 1;
        size_[size_.size() - 1] = 1;
        count_ += 1;
        for (size_t i = 0; i < board.size(); ++i) {
            for (size_t j = 0; j < board[0].size(); ++j) {
                int index = i * board[0].size() + j;
                if (board[i][j] == 'O') {
                    if (i != 0 && i != board.size() - 1 && j != 0 && j != board[0].size() - 1) {
                        parent_[index] = index;
                        size_[index] = 1;
                        count_++;
                    } else {
                        parent_[index] = parent_.size() - 1;
                        size_[index] = 1;
                        size_[parent_.size() - 1] += size_[index];
                    }
                } else {
                    parent_[index] = -1;
                    size_[index] = 0;
                }
            }
        }
    }

    void Unite(int x, int y) {
        int root_x = Find(x);
        int root_y = Find(y);
        if (root_x == root_y) {
            return;
        }

        if (size_[root_x] > size_[root_y]) {
            parent_[root_y] = root_x;
            size_[root_x] += size_[root_y];
        } else {
            parent_[root_x] = root_y;
            size_[root_y] += size_[root_x];
        }
        count_--;
    }

    bool Connected(int x, int y) {
        int root_x = Find(x);
        int root_y = Find(y);
        return root_x == root_y;
    }

    int Find(int x) {
        while (parent_[x] != x) {
            parent_[x] = parent_[parent_[x]];
            x = parent_[x];
        }
        return x;
    }

    int Count() {
        return count_;
    }

private:
    vector<int> parent_;
    vector<int> size_;
    int count_ = 0;
};

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty()) {
            return;
        }

        UnionFind uf(board);
        for (size_t i = 0; i < board.size(); ++i) {
            for (size_t j = 0; j < board[0].size(); ++j) {
                int self = i * board[0].size() + j;
                if (board[i][j] == 'X') {
                    continue;
                }
                if (i > 0) {
                    int up = (i - 1) * board[0].size() + j;
                    if (board[i - 1][j] == 'O') {
                        uf.Unite(self, up);
                    }
                }
                if (i < board.size() - 1) {
                    int down = (i + 1) * board[0].size() + j;
                    if (board[i + 1][j] == 'O') {
                        uf.Unite(self, down);
                    }
                }
                if (j > 0) {
                    int left = i * board[0].size() + (j - 1);
                    if (board[i][j - 1] == 'O') {
                        uf.Unite(self, left);
                    }
                }
                if (j < board[0].size() - 1) {
                    int right = i * board[0].size() + (j + 1);
                    if (board[i][j + 1] == 'O') {
                        uf.Unite(self, right);
                    }
                }
            }
        }

        for (size_t i = 0; i < board.size(); ++i) {
            for (size_t j = 0; j < board[0].size(); ++j) {
                int self = i * board[0].size() + j;
                if (board[i][j] == 'O' && !uf.Connected(self, board.size() * board[0].size())) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};

TEST(TestSurroundedRegions, case01) {
    vector<vector<char>> input = {{'X', 'X', 'X', 'X'},
                                  {'X', 'O', 'O', 'X'},
                                  {'X', 'X', 'O', 'X'},
                                  {'X', 'O', 'X', 'X'}};
    Solution solution;
    solution.solve(input);
    for (size_t i = 0; i < input.size(); ++i) {
        for (size_t j = 0; j < input[0].size(); ++j) {
            cout << input[i][j];
        }
        cout << endl;
    }
}

TEST(TestSurroundedRegions, case02) {
    vector<vector<char>> input = {{'X', 'O', 'X'},
                                  {'O', 'X', 'O'},
                                  {'X', 'O', 'X'}};
    Solution solution;
    solution.solve(input);
    for (size_t i = 0; i < input.size(); ++i) {
        for (size_t j = 0; j < input[0].size(); ++j) {
            cout << input[i][j];
        }
        cout << endl;
    }
}