#include <gtest/gtest.h>

#include <stack>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> result_map;
        stack<int> s;
        for (int i = nums2.size() - 1; i >= 0; --i) {
            while (!s.empty() && nums2[i] > s.top()) {
                s.pop();
            }
            result_map[nums2[i]] = s.empty() ? -1 : s.top();
            s.push(nums2[i]);
        }

        vector<int> result(nums1.size(), -1);
        for (size_t i = 0; i < nums1.size(); ++i) {
            result[i] = result_map[nums1[i]];
        }

        return result;
    }
};

TEST(TestNextGreaterElementI, case01) {
    vector<int> nums1 = {4,1,2};
    vector<int> nums2 = {1,3,4,2};
    Solution solution;
    auto result = solution.nextGreaterElement(nums1, nums2);
    for (size_t i = 0; i < result.size(); ++i) {
        cout << result[i] << " ";
    }
}

TEST(TestNextGreaterElementI, case02) {
    vector<int> nums1 = {2,4};
    vector<int> nums2 = {1,2,3,4};
    Solution solution;
    auto result = solution.nextGreaterElement(nums1, nums2);
    for (size_t i = 0; i < result.size(); ++i) {
        cout << result[i] << " ";
    }
}