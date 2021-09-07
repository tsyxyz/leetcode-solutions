#include <gtest/gtest.h>

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

    int find(int p) {
        while (parent_[p] != p) {
            parent_[p] = parent_[parent_[p]];
            p = parent_[p];
        }
        return p;
    }

    void unite(int p, int q) {
        int root_p = find(p);
        int root_q = find(q);
        if (root_p == root_q) {
            return;
        }

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
    int count_ = 0;
    vector<int> parent_;
    vector<int> size_;
};

class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int peopleCounts = row.size();
        int coupleCounts = peopleCounts / 2;
        UnionFind uf(coupleCounts);
        for (int i = 0; i < peopleCounts; i += 2) {
            uf.unite(row[i] / 2, row[i + 1] / 2);
        }
        int result = coupleCounts - uf.count();
        return result;
    }
};

TEST(Test_765, case_01) {
    vector<int> row = {0, 2, 1, 3};
    Solution s;
    int result = s.minSwapsCouples(row);
    ASSERT_EQ(result, 1);
}

TEST(Test_765, case_02) {
    vector<int> row = {3, 2, 0, 1};
    Solution s;
    int result = s.minSwapsCouples(row);
    ASSERT_EQ(result, 0);
}