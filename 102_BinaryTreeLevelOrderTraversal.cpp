#include <gtest/gtest.h>

#include <queue>

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) {
            return {};
        }

        queue<TreeNode*> q;
        vector<vector<int>> result;
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

TEST(Test_102, case_01) {
    TreeNode n15(15);
    TreeNode n7(7);
    TreeNode n20(20, &n15, &n7);
    TreeNode n9(9);
    TreeNode n3(3, &n9, &n20);

    Solution s;
    auto result = s.levelOrder(&n3);

    for (size_t i = 0; i < result.size(); ++i) {
        for (size_t j = 0; j < result[i].size(); ++j) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}
