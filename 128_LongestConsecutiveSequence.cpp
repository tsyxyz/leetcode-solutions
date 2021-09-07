#include <gtest/gtest.h>

#include <vector>
#include <unordered_map>

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

private:
    int count_;
    vector<int> parent_;
    vector<int> size_;
};

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;

        unordered_map<int, int> valIndex;
        vector<int> numsClean;
        for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
            int val = nums[i];
            // remove repeated
            if (valIndex.count(val) == 0) {
                numsClean.push_back(val);
                valIndex[val] = numsClean.size() - 1;
            }
        }

        UnionFind uf(numsClean.size());
        for (int i = 0; i < static_cast<int>(numsClean.size()); ++i) {
            int num = numsClean[i];
            if (valIndex.find(num - 1) != valIndex.end()) {
                uf.unite(i, valIndex[num - 1]);
            }
            if (valIndex.find(num + 1) != valIndex.end()) {
                uf.unite(i, valIndex[num + 1]);
            }
        }
        int result = uf.maxSize();
        return result;
    }
};

TEST(Test_128, case_01) {
    vector<int> nums = {100,4,200,1,3,2};
    Solution s;
    int result = s.longestConsecutive(nums);
    ASSERT_EQ(result, 4);
}

TEST(Test_128, case_02) {
    vector<int> nums = {0,3,7,2,5,8,4,6,0,1};
    Solution s;
    int result = s.longestConsecutive(nums);
    ASSERT_EQ(result, 9);
}