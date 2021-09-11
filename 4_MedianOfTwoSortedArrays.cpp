#include <gtest/gtest.h>

#include <vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0;
        vector<int> total;
        while (i < static_cast<int>(nums1.size()) &&
               j < static_cast<int>(nums2.size())) {
            if (nums1[i] < nums2[j]) {
                total.push_back(nums1[i]);
                i++;
            } else {
                total.push_back(nums2[j]);
                j++;
            }
        }
        if (i == static_cast<int>(nums1.size())) {
            for (; j < static_cast<int>(nums2.size()); ++j) {
                total.push_back(nums2[j]);
            }
        } else {
            for (; i < static_cast<int>(nums1.size()); ++i) {
                total.push_back(nums1[i]);
            }
        }

        if (total.size() == 0) {
            return 0.0;
        }

        if (total.size() == 1) {
            return total[0] * 1.0;
        }

        if (total.size() % 2 == 0) {
            int mid = total.size() / 2;
            double result = (total[mid] + total[mid - 1]) * 1.0 / 2;
            return result;
        } else {
            int mid = total.size() / 2;
            return total[mid] * 1.0;
        }
    }
};

TEST(Test_4, case_01) {
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};
    Solution s;
    double result = s.findMedianSortedArrays(nums1, nums2);
    cout << result;
}

TEST(Test_4, case_02) {
    vector<int> nums1 = {1, 2};
    vector<int> nums2 = {3, 4};
    Solution s;
    double result = s.findMedianSortedArrays(nums1, nums2);
    cout << result;
}