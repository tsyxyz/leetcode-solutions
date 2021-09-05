#include <gtest/gtest.h>

#include <queue>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) return {};

        auto levels = levelTraverse(root);
        vector<vector<int>> result;
        for (size_t i = 0; i < levels.size(); ++i) {
            vector<int> level;
            if (i % 2 == 0) {
                for (size_t j = 0; j < levels[i].size(); ++j) {
                    level.push_back(levels[i][j]);
                }
            } else {
                for (int j = static_cast<int>(levels[i].size()) - 1; j >= 0; --j) {
                    level.push_back(levels[i][j]);
                }
            }
            result.push_back(level);
        }
        return result;
    }

private:
    vector<vector<int>> levelTraverse(TreeNode* root) {
        if (!root) return {};

        vector<vector<int>> result;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            vector<int> level;
            size_t levelCount = q.size();
            for (size_t i = 0; i < levelCount; ++i) {
                TreeNode* front = q.front();
                q.pop();
                level.push_back(front->val);
                if (front->left) q.push(front->left);
                if (front->right) q.push(front->right);
            }
            result.push_back(level);
        }
        return result;
    }
};

TEST(Test_103, case_01) {
    TreeNode n15(15);
    TreeNode n7(7);
    TreeNode n20(20, &n15, &n7);
    TreeNode n9(9);
    TreeNode n3(3, &n9, &n20);

    Solution s;
    auto result = s.zigzagLevelOrder(&n3);
    for (size_t i = 0; i < result.size(); ++i) {
        for (size_t j = 0; j < result[i].size(); ++j) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}