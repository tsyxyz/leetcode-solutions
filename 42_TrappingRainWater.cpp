#include <gtest/gtest.h>

#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int pillarNum = height.size();
        if (pillarNum < 2) {
            return 0;
        }
        int highestHeight = getHighestHeight(height);
        int totalArea = pillarNum * highestHeight;
        int pillarArea = getPillarArea(height);
        int leakArea = getLeakArea(height);
        int result = totalArea - pillarArea - leakArea;

        return result;
    }

private:
    int getHighestHeight(const vector<int>& pillars) {
        int highest = 0;
        for (auto it : pillars) {
            if (it > highest)
                highest = it;
        }
        return highest;
    }

    int getPillarArea(const vector<int>& pillars) {
        int area = 0;
        for (auto it : pillars) {
            area += it;
        }
        return area;
    }

    int getLeakArea(const vector<int>& pillars) {
        return getLeftLeakArea(pillars) + getRightLeakArea(pillars);
    }

    int getLeftLeakArea(const vector<int>& pillars) {
        vector<int> higherPillarsIdx;
        int prevHeight = pillars[0];
        higherPillarsIdx.push_back(0);
        for (size_t i = 1; i < pillars.size(); ++i) {
            if (pillars[i] > prevHeight) {
                higherPillarsIdx.push_back(i);
                prevHeight = pillars[i];
            }
        }
        int area = 0;
        int startHeight = pillars[higherPillarsIdx[0]];
        for (size_t i = 0; i < higherPillarsIdx.size(); ++i) {
            int dx = higherPillarsIdx[i];
            int dy = pillars[higherPillarsIdx[i]] - startHeight;
            area += (dx * dy);
            startHeight = pillars[higherPillarsIdx[i]];
        }
        return area;
    }

    int getRightLeakArea(const vector<int>& pillars) {
        vector<int> higherPillarsIdx;
        int prevHeight = pillars[pillars.size() - 1];
        higherPillarsIdx.push_back(pillars.size() - 1);
        for (int i = static_cast<int>(pillars.size()) - 2; i >= 0; --i) {
            if (pillars[i] > prevHeight) {
                higherPillarsIdx.push_back(i);
                prevHeight = pillars[i];
            }
        }
        int area = 0;
        int startHeight = pillars[higherPillarsIdx[0]];
        for (size_t i = 0; i < higherPillarsIdx.size(); ++i) {
            int dx = static_cast<int>(pillars.size()) - 1 - higherPillarsIdx[i];
            int dy = pillars[higherPillarsIdx[i]] - startHeight;
            area += (dx * dy);
            startHeight = pillars[higherPillarsIdx[i]];
        }
        return area;
    }
};

/*
 * 单调栈
 */
class Solution2 {
public:
    int trap(vector<int>& height) {
        stack<int> s;
        int result = 0;
        for (int i = 0; i < static_cast<int>(height.size()); ++i) {
            while (!s.empty() && height[s.top()] < height[i]) {
                int top = s.top();
                s.pop();
                if (s.empty()) {
                    break;
                }
                int w = i - s.top() - 1;
                int h = min(height[s.top()], height[i]) - height[top];
                result += w * h;
            }
            s.push(i);
        }
        return result;
    }
};

TEST(TestTrappingRainWater, case01) {
    Solution solution;
    vector<int> input = {4, 0, 6, 0, 5, 0, 7, 0, 5, 0, 6, 0, 4, 0, 3};
    int result = solution.trap(input);
    EXPECT_EQ(37, result);
}

TEST(TestTrappingRainWater, case02) {
    Solution solution;
    vector<int> input = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int result = solution.trap(input);
    EXPECT_EQ(6, result);
}

TEST(TestTrappingRainWater, case03) {
    Solution2 solution;
    vector<int> input = {4, 0, 6, 0, 5, 0, 7, 0, 5, 0, 6, 0, 4, 0, 3};
    int result = solution.trap(input);
    EXPECT_EQ(37, result);
}

TEST(TestTrappingRainWater, case04) {
    Solution2 solution;
    vector<int> input = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int result = solution.trap(input);
    EXPECT_EQ(6, result);
}