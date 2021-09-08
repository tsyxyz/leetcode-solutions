#include <gtest/gtest.h>

#include <vector>

using namespace std;

class UnionFind {
public:
    UnionFind(int n) {
        count_ = n;
        size_.resize(n, 1);
        parent_.resize(n);
        for (int i = 0; i < n; ++i) {
            parent_[i] = i;
        }
    }

    int find(int x) {
        while (parent_[x] != x) {
            parent_[x] = parent_[parent_[x]];
            x = parent_[x];
        }
        return x;
    }

    void unite(int p, int q) {
        int root_p = find(p);
        int root_q = find(q);
        if (root_p == root_q) return;

        if (size_[root_p] > size_[root_q]) {
            parent_[root_q] = root_p;
            size_[root_p] += size_[root_q];
        } else {
            parent_[root_p] = root_q;
            size_[root_q] += size_[root_p];
        }
        count_--;
    }

    bool connected(int p, int q) {
        int root_p = find(p);
        int root_q = find(q);
        return root_p == root_q;
    }

    int count() {
        return count_;
    }

    int maxSize() {
        int result = INT32_MIN;
        for (auto i : size_) {
            result = max(i, result);
        }
        return result;
    }

    void reduce(int i) {
        size_[i]--;
        count_--;
    }

private:
    int count_;
    vector<int> parent_;
    vector<int> size_;
};

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        UnionFind uf(rows * cols);

        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                int selfIndex = r * cols + c;
                if (grid[r][c] == 0) {
                    uf.reduce(selfIndex);
                } else {
                    if (r - 1 >= 0 && grid[r - 1][c] == 1) {
                        int upIndex = (r - 1) * cols + c;
                        uf.unite(selfIndex, upIndex);
                    }
                    if (r + 1 < rows && grid[r + 1][c] == 1) {
                        int downIndex = (r + 1) * cols + c;
                        uf.unite(selfIndex, downIndex);
                    }
                    if (c - 1 >= 0 && grid[r][c - 1] == 1) {
                        int leftIndex = r * cols + c - 1;
                        uf.unite(selfIndex, leftIndex);
                    }
                    if (c + 1 < cols && grid[r][c + 1] == 1) {
                        int rightIndex = r * cols + c + 1;
                        uf.unite(selfIndex, rightIndex);
                    }
                }
            }
        }
        int result = uf.maxSize();
        return result;
    }
};