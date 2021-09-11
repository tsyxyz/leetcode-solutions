#include <gtest/gtest.h>

#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int minimumSemesters(int n, vector<vector<int>>& relations) {
        inDegree_.resize(n + 1, 0);
        graph_.resize(n + 1);
        for (int i = 0; i < static_cast<int>(relations.size()); ++i) {
            vector<int> relation = relations[i];
            graph_[relation[0]].push_back(relation[1]);
            inDegree_[relation[1]] += 1;
        }

        queue<int> q;
        for (int i = 1; i <= n; ++i) {
            if (inDegree_[i] == 0) {
                q.push(i);
            }
        }

        int step = 0;
        while (!q.empty()) {
            int queueSize = q.size();
            for (int j = 0; j < queueSize; ++j) {
                int front = q.front();
                q.pop();
                for (int i = 0; i < static_cast<int>(graph_[front].size()); ++i) {
                    int successor = graph_[front][i];
                    inDegree_[successor]--;
                    if (inDegree_[successor] == 0) {
                        q.push(successor);
                    }
                }
            }
            step++;
        }

        for (int i = 1; i < n; ++i) {
            if (inDegree_[i] > 0) {
                return -1;
            }
        }
        return step;
    }

private:
    vector<int> inDegree_;
    vector<vector<int>> graph_;
};

TEST(Test_1136, case_01) {
    vector<vector<int>> relations = {{1,3},{2,3}};
    Solution s;
    int result = s.minimumSemesters(3, relations);
    ASSERT_EQ(result, 2);
}