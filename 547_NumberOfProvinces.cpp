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

private:
    int count_;
    vector<int> parent_;
    vector<int> size_;
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int rows = isConnected.size();
        int cols = isConnected[0].size();
        UnionFind uf(rows);
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (isConnected[r][c]) {
                    uf.unite(r, c);
                }
            }
        }
        return uf.count();
    }
};

TEST(Test_547, case_01) {
    vector<vector<int>> isConnected = {{1,1,0},{1,1,0},{0,0,1}};
    Solution s;
    int result = s.findCircleNum(isConnected);
    ASSERT_EQ(result, 2);
}

TEST(Test_547, case_02) {
    vector<vector<int>> isConnected = {{1,0,0},{0,1,0},{0,0,1}};
    Solution s;
    int result = s.findCircleNum(isConnected);
    ASSERT_EQ(result, 3);
}