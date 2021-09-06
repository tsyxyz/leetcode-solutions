#include <gtest/gtest.h>

#include <vector>
#include <map>

using namespace std;

//// !!!还没完成，提交超时
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        buildGraph(matrix);

        for (int v = 0; v < static_cast<int>(graph_.size()); ++v) {
            dfs(v, 0);
        }
        return maxPath_;
    }

private:
    void buildGraph(const vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        graph_.resize(rows * cols);

        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                int selfIndex = r * cols + c;
                indexValue_[selfIndex] = matrix[r][c];

                if (r - 1 >= 0) {
                    int upIndex = (r - 1) * cols + c;
                    graph_[selfIndex].push_back(upIndex);
                }
                if (r + 1 < rows) {
                    int downIndex = (r + 1) * cols + c;
                    graph_[selfIndex].push_back(downIndex);
                }
                if (c - 1 >= 0) {
                    int leftIndex = r * cols + c - 1;
                    graph_[selfIndex].push_back(leftIndex);
                }
                if (c + 1 < cols) {
                    int rightIndex = r * cols + c + 1;
                    graph_[selfIndex].push_back(rightIndex);
                }
            }
        }
    }

    void dfs(int v, int steps) {
        int vVal = indexValue_[v];
        for (int w : graph_[v]) {
            int wVal = indexValue_[w];
            if (wVal > vVal) {
                dfs(w, steps + 1);
            } else {
                maxPath_ = max(maxPath_, steps + 1);
            }
        }
    }

    vector<vector<int>> graph_;
    map<int, int> indexValue_;
    int maxPath_ = 1;
};

TEST(Test_329, case_01) {
    vector<vector<int>> matrix = {{9,9,4},{6,6,8},{2,1,1}};
    Solution s;
    int result = s.longestIncreasingPath(matrix);
    ASSERT_EQ(result, 4);
}

TEST(Test_329, case_02) {
    vector<vector<int>> matrix = {{3,4,5},{3,2,6},{2,2,1}};
    Solution s;
    int result = s.longestIncreasingPath(matrix);
    ASSERT_EQ(result, 4);
}