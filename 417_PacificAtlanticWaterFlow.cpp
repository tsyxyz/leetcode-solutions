#include <gtest/gtest.h>

#include <vector>
#include <queue>

using namespace std;

//// ! 还没完成！
class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        rows_ = heights.size();
        cols_ = heights[0].size();
        visited_.resize(rows_ * cols_, false);
        canFlowUpLeft_.resize(rows_ * cols_, false);
        canFlowDownRight_.resize(rows_ * cols_, false);

        int r = 0, c = 0;
        for (; c < cols_; ++c) {
            bfs(heights, r, c, true);
        }
        c = 0;
        for (r = 1; r < rows_; ++r) {
            bfs(heights, r, c, true);
        }

        visited_.resize(rows_ * cols_, false);
        r = rows_ - 1;
        for (c = 0; c < cols_; ++c) {
            bfs(heights, r, c, false);
        }
        c = cols_ - 1;
        for (r = 0; r < rows_ - 1; ++r) {
            bfs(heights, r, c, false);
        }

        vector<vector<int>> result;
        for (int i = 0; i < rows_ * cols_; ++i) {
            if (canFlowUpLeft_[i] && canFlowDownRight_[i]) {
                vector<int> coord = {i / cols_, i % cols_};
                result.push_back(coord);
            }
        }
        return result;
    }

private:
    void bfs(const vector<vector<int>>& heights,
             int r, int c, bool checkUpLeft) {
        int curIndex = r * cols_ + c;
        queue<int> q;
        q.push(curIndex);
        visited_[curIndex] = true;
        if (checkUpLeft) {
            canFlowUpLeft_[curIndex] = true;
        } else {
            canFlowDownRight_[curIndex] = true;
        }

        while (!q.empty()) {
            int front = q.front();
            q.pop();
            r = front / cols_;
            c = front % cols_;
            int curHeight = heights[r][c];
            if (r - 1 >= 0 && heights[r - 1][c] >= curHeight) {
                int upIndex = (r - 1) * cols_ + c;
                if (!visited_[upIndex]) {
                    q.push(upIndex);
                    visited_[upIndex] = true;
                    if (checkUpLeft) {
                        canFlowUpLeft_[upIndex] = true;
                    } else {
                        canFlowDownRight_[upIndex] = true;
                    }
                }
            }
            if (r + 1 < rows_ && heights[r + 1][c] >= curHeight) {
                int downIndex = (r + 1) * cols_ + c;
                if (!visited_[downIndex]) {
                    q.push(downIndex);
                    visited_[downIndex] = true;
                    if (checkUpLeft) {
                        canFlowUpLeft_[downIndex] = true;
                    } else {
                        canFlowDownRight_[downIndex] = true;
                    }
                }
            }
            if (c - 1 >= 0 && heights[r][c - 1] >= curHeight) {
                int leftIndex = r * cols_ + c - 1;
                if (!visited_[leftIndex]) {
                    q.push(leftIndex);
                    visited_[leftIndex] = true;
                    if (checkUpLeft) {
                        canFlowUpLeft_[leftIndex] = true;
                    } else {
                        canFlowDownRight_[leftIndex] = true;
                    }
                }
            }
            if (c + 1 < cols_ && heights[r][c + 1] >= curHeight) {
                int rightIndex = r * cols_ + c + 1;
                if (!visited_[rightIndex]) {
                    q.push(rightIndex);
                    visited_[rightIndex] = true;
                    if (checkUpLeft) {
                        canFlowUpLeft_[rightIndex] = true;
                    } else {
                        canFlowDownRight_[rightIndex] = true;
                    }
                }
            }
        }
    }

private:
    int rows_ = 0;
    int cols_ = 0;
    vector<bool> visited_;
    vector<bool> canFlowUpLeft_;
    vector<bool> canFlowDownRight_;
};

TEST(Test_417, case_01) {
    vector<vector<int>> heights = {
        {1,2,2,3,5},
        {3,2,3,4,4},
        {2,4,5,3,1},
        {6,7,1,4,5},
        {5,1,1,2,4}
    };

    Solution s;
    auto result = s.pacificAtlantic(heights);
    cout << "1";
}