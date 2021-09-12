#include <gtest/gtest.h>

#include <vector>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> s;
        for (size_t i = 0; i < nums.size(); ++i) {
            s.insert(nums[i]);
        }
        return s.size() != nums.size();
    }
};