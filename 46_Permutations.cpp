#include <gtest/gtest.h>

#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        numsSize_ = nums.size();
        for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
            nums_.push_back(nums[i]);
            availableNums_.insert(nums[i]);
        }
        vector<int> arrange;
        dfs(0, arrange);
        return allArranges_;
    }

private:
    void dfs(int idx, vector<int>& arrange) {
        if (idx == numsSize_) {
            allArranges_.push_back(arrange);
            return;
        }

        for (int i = 0; i < numsSize_; ++i) {
            if (availableNums_.count(nums_[i]) > 0) {
                arrange.push_back(nums_[i]);
                availableNums_.erase(nums_[i]);
                dfs(idx + 1, arrange);
                availableNums_.insert(nums_[i]);
                arrange.pop_back();
            }
        }
    }

private:
    vector<int> nums_;
    vector<vector<int>> allArranges_;
    set<int> availableNums_;
    int numsSize_;
};

TEST(Test_46, case_01) {
    vector<int> nums = {1, 2, 3};
    Solution s;
    auto result = s.permute(nums);
    for (size_t i = 0; i < result.size(); ++i) {
        for (size_t j = 0; j < result[i].size(); ++j) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}