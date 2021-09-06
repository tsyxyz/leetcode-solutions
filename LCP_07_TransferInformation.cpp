#include <gtest/gtest.h>

#include <vector>

using namespace std;

class Solution {
public:
    int numWays(int n, vector<vector<int>>& relation, int k) {
        graph_.resize(n);
        k_ = k;
        dest_ = n - 1;
        buildGraph(relation);
        dfs(0, 0);
        return ways_;
    }

private:
    void buildGraph(const vector<vector<int>>& relation) {
        for (size_t i = 0; i < relation.size(); ++i) {
            vector<int> edge = relation[i];
            int from = edge[0];
            int to = edge[1];
            graph_[from].push_back(to);
        }
    }

    void dfs(int v, int steps) {
        if (steps == k_) {
            if (v == dest_) {
                ways_ += 1;
            }
            return;
        }
        for (int w : graph_[v]) {
            dfs(w, steps + 1);
        }
    }

    vector<vector<int>> graph_;
    int ways_ = 0;
    int k_ = 0;
    int dest_ = 0;
};

TEST(Test_LCP_07, case_01) {
    vector<vector<int>> relation = {{0,2},{2,1},{3,4},{2,3},{1,4},{2,0},{0,4}};
    int n = 5, k = 3;
    Solution s;
    int result = s.numWays(n, relation, k);
    ASSERT_EQ(result, 3);
}