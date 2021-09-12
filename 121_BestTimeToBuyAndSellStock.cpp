#include <gtest/gtest.h>

#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT32_MAX;
        int result = 0;
        for (size_t i = 0; i < prices.size(); ++i) {
            result = max(result, prices[i] - minPrice);
            minPrice = min(minPrice, prices[i]);
        }
        return result;
    }
};

TEST(Tesst_121, case_01) {
    vector<int> prices = {7,1,5,3,6,4};
    Solution s;
    int result = s.maxProfit(prices);
    ASSERT_EQ(result, 5);
}