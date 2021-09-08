#include <gtest/gtest.h>

#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        visited_.resize(n, false);
        graph_.resize(n);
        for (int i = 0; i < static_cast<int>(edges.size()); ++i) {
            vector<int> edge = edges[i];
            graph_[edge[0]].push_back(edge[1]);
            graph_[edge[1]].push_back(edge[0]);
        }

        int count = 0;
        for (int i = 0; i < n; ++i) {
            if (!visited_[i]) {
                bfs(graph_, i);
                count += 1;
            }
        }
        return count;
    }

    void bfs(const vector<vector<int>>& graph, int n) {
        visited_[n] = true;
        queue<int> q;
        q.push(n);

        while (!q.empty()) {
            int front = q.front();
            q.pop();
            vector<int> successors = graph[front];
            for (int j = 0; j < static_cast<int>(successors.size()); ++j) {
                if (!visited_[successors[j]]) {
                    q.push(successors[j]);
                    visited_[successors[j]] = true;
                }
            }
        }
    }

private:
    vector<vector<int>> graph_;
    vector<bool> visited_;
};

TEST(Test_323, case_01) {
    vector<vector<int>> edges = {{0,1},{1,2},{3,4}};
    Solution s;
    int result = s.countComponents(5, edges);
    ASSERT_EQ(result, 2);
}