#include <vector>

#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        for (size_t i = 0; i < nums.size(); ++i) {
            for (size_t j = i + 1; j < nums.size(); ++j) {
                if (nums[i] + nums[j] == target) {
                    result.push_back(i);
                    result.push_back(j);
                    return result;
                }
            }
        }
        return result;
    }
};

TEST(testTwoSum, simple) {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> answer = {0, 1};

    Solution solution;
    vector<int> result = solution.twoSum(nums, target);
    EXPECT_EQ(result, answer);
}
