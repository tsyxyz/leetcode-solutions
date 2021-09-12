#include <gtest/gtest.h>

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> leftProducts(nums.size(), 0);
        vector<int> rightProducts(nums.size(), 0);
        vector<int> result(nums.size(), 0);

        for (size_t i = 0; i < nums.size(); ++i) {
            if (i == 0) {
                leftProducts[i] = 1;
            } else {
                leftProducts[i] = leftProducts[i - 1] * nums[i - 1];
            }
        }
        for (int i = static_cast<int>(nums.size()) - 1; i >= 0; --i) {
            if (i == static_cast<int>(nums.size()) - 1) {
                rightProducts[i] = 1;
            } else {
                rightProducts[i] = rightProducts[i + 1] * nums[i + 1];
            }
        }
        for (size_t i = 0; i < nums.size(); ++i) {
            result[i] = leftProducts[i] * rightProducts[i];
        }
        return result;
    }
};

TEST(Test_238, case_01) {
    vector<int> nums = {1,2,3,4};
    Solution s;
    auto ret = s.productExceptSelf(nums);
}