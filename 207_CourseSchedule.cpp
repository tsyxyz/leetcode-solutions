#include <gtest/gtest.h>

#include <vector>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        graph_.clear();
        marked_.clear();
        on_stack_.clear();
        graph_.resize(numCourses);
        marked_.resize(numCourses, false);
        on_stack_.resize(numCourses, false);

        buildGraph(prerequisites);
        for (int v = 0; v < graph_.size(); ++v) {
            if (!marked_[v]) {
                dfs(v);
            }
        }
        return !has_cycle_;
    }

private:
    void buildGraph(vector<vector<int>>& prerequisites) {
        for (size_t i = 0; i < prerequisites.size(); ++i) {
            auto edge = prerequisites[i];
            graph_[edge[0]].push_back(edge[1]);
        }
    }

    void dfs(int v) {
        on_stack_[v] = true;
        marked_[v] = true;
        for (int w : graph_[v]) {
            if (has_cycle_) return;
            if (!marked_[w]) {
                dfs(w);
            } else if (on_stack_[w]) {
                has_cycle_ = true;
                return;
            }
        }
        on_stack_[v] = false;
    }
private:
    vector<vector<int> > graph_;
    vector<bool> marked_;
    vector<bool> on_stack_;
    bool has_cycle_ = false;
};

TEST(TestCourseSchedule, case01) {
    vector<vector<int> > prerequisites = {{1, 0}};
    Solution solution;
    bool result = solution.canFinish(2, prerequisites);
    EXPECT_EQ(true, result);
}

TEST(TestCourseSchedule, case02) {
    vector<vector<int> > prerequisites = {{1, 0}, {0, 1}};
    Solution solution;
    bool result = solution.canFinish(2, prerequisites);
    EXPECT_EQ(false, result);
}

TEST(TestCourseSchedule, case03) {
    vector<vector<int> > prerequisites = {{0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 2}};
    Solution solution;
    bool result = solution.canFinish(5, prerequisites);
    EXPECT_EQ(false, result);
}

TEST(TestCourseSchedule, case04) {
    vector<vector<int> > prerequisites = {{0, 1}, {1, 2}, {2, 3}, {3, 4}};
    Solution solution;
    bool result = solution.canFinish(5, prerequisites);
    EXPECT_EQ(true, result);
}