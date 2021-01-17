#include <vector>

#include <gtest/gtest.h>

using namespace std;

class UnionFind {
public:
    UnionFind(const vector<vector<char>>& grid) {
        for (size_t i = 0; i < grid.size(); ++i) {
            for (size_t j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j] == '1') {
                    count_++;
                    parent_.push_back(i * grid[0].size() + j);
                    size_.push_back(1);
                } else {
                    parent_.push_back(-1);
                    size_.push_back(0);
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

    int Count() {
        return count_;
    }

private:
    int Find(int x) {
        while (parent_[x] != x) {
            parent_[x] = parent_[parent_[x]];
            x = parent_[x];
        }
        return x;
    }

private:
    int count_ = 0;
    vector<int> parent_;
    vector<int> size_;
};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        UnionFind uf(grid);
        for (size_t i = 0; i < grid.size(); ++i) {
            int row_num = grid.size();
            int col_num = grid[0].size();
            for (size_t j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j] == '0') {
                    continue;
                }

                int self = i * col_num + j;
                if (i > 0) {
                    int up = (i - 1) * col_num + j;
                    if (grid[i - 1][j] == '1' && !uf.Connected(self, up)) {
                        uf.Unite(self, up);
                    }
                }

                if (static_cast<int>(i) < row_num - 1) {
                    int down = (i + 1) * col_num + j;
                    if (grid[i + 1][j] == '1' && !uf.Connected(self, down)) {
                        uf.Unite(self, down);
                    }
                }

                if (j > 0) {
                    int left = i * col_num + (j - 1);
                    if (grid[i][j - 1] == '1' && !uf.Connected(self, left)) {
                        uf.Unite(self, left);
                    }
                }

                if (static_cast<int>(j) < col_num - 1) {
                    int right = i * col_num + (j + 1);
                    if (grid[i][j + 1] == '1' && !uf.Connected(self, right)) {
                        uf.Unite(self, right);
                    }
                }
            }
        }
        return uf.Count();
    }
};

TEST(TestNumberOfIslands, case01) {
    vector<vector<char>> input = {{'1', '1', '1', '1', '0'},
                                  {'1', '1', '0', '1', '0'},
                                  {'1', '1', '0', '0', '0'},
                                  {'0', '0', '0', '0', '0'}};
    Solution solution;
    int result = solution.numIslands(input);
    cout << result << endl;
}

TEST(TestNumberOfIslands, case02) {
    vector<vector<char>> input = {{'1', '1', '0', '0', '0'},
                                  {'1', '1', '0', '0', '0'},
                                  {'0', '0', '1', '0', '0'},
                                  {'0', '0', '0', '1', '1'}};
    Solution solution;
    int result = solution.numIslands(input);
    cout << result << endl;
}