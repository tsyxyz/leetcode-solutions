#include <gtest/gtest.h>

#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> input(heights);
        input.push_back(-1);
        int largest = 0;
        stack<int> st;
        for (size_t i = 0; i < input.size(); ++i) {
            while (!st.empty() && input[i] < input[st.top()]) {
                 int height = input[st.top()];
                 st.pop();
                 int left = st.empty() ? -1 : st.top();
                 int square = height * (i - left - 1);
                 largest = max(largest, square);
            }
            st.push(i);
        }
        return largest;
    }
};

TEST(TestLargestRectangleInHistogram, case01) {
    vector<int> heights = {2,1,5,6,2,3};
    Solution solution;
    int result = solution.largestRectangleArea(heights);
    cout << result << endl;
}