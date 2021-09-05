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
    vector<int> rightSideView(TreeNode* root) {
        auto levels = levelTraverse(root);
        vector<int> result;
        for (size_t i = 0; i < levels.size(); ++i) {
            int val = levels[i].back();
            result.push_back(val);
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

TEST(Test_199, case_01) {
    TreeNode n5(5);
    TreeNode n2(2, nullptr, &n5);
    TreeNode n4(4);
    TreeNode n3(3, nullptr, &n4);
    TreeNode n1(1, &n2, &n3);

    Solution s;
    vector<int> result = s.rightSideView(&n1);
    for (size_t i = 0; i < result.size(); ++i) {
        cout << result[i] << " ";
    }
}

TEST(Test_199, case_02) {
    TreeNode n5(5);
    TreeNode n2(2, nullptr, &n5);
    TreeNode n3(3, nullptr, nullptr);
    TreeNode n1(1, &n2, &n3);

    Solution s;
    vector<int> result = s.rightSideView(&n1);
    for (size_t i = 0; i < result.size(); ++i) {
        cout << result[i] << " ";
    }
}