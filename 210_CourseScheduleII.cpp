#include <gtest/gtest.h>

#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
        graph_.clear();
        marked_.clear();
        on_stack_.clear();
        graph_.resize(numCourses);
        marked_.resize(numCourses);
        on_stack_.resize(numCourses);

        has_cycle_ = false;

        build_graph(prerequisites);
        for (size_t v = 0; v < graph_.size(); ++v) {
            if (!marked_[v]) {
                dfs(v);
            }
        }
        vector<int> result;
        if (!has_cycle_) {
            while (!reverse_order_.empty()) {
                int n = reverse_order_.top();
                result.push_back(n);
                reverse_order_.pop();
            }
        }
        return result;
    }

private:
    void build_graph(vector<vector<int> > &prerequisites) {
        for (size_t i = 0; i < prerequisites.size(); ++i) {
            auto edge = prerequisites[i];
            graph_[edge[1]].push_back(edge[0]);
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
        reverse_order_.push(v);
    }

private:
    vector<vector<int> > graph_;
    vector<bool> marked_;
    vector<bool> on_stack_;
    stack<int> reverse_order_;
    bool has_cycle_ = false;
};

TEST(TestCourseScheduleII, case01) {
    vector<vector<int> > prerequisites = {{1, 0}};
    Solution solution;
    vector<int> result = solution.findOrder(2, prerequisites);
    for (size_t i = 0; i < result.size(); ++i) {
        std::cout << result[i] << " ";
    }
}

TEST(TestCourseScheduleII, case02) {
    vector<vector<int> > prerequisites = {{1,0},{2,0},{3,1},{3,2}};
    Solution solution;
    vector<int> result = solution.findOrder(4, prerequisites);
    for (size_t i = 0; i < result.size(); ++i) {
        std::cout << result[i] << " ";
    }
}
