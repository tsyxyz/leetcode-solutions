#include <gtest/gtest.h>

#include <vector>
#include <queue>
#include <stack>

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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (!root) return {};

        stack<vector<int>> levels;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int levelCount = q.size();
            vector<int> level;
            for (int i = 0; i < levelCount; ++i) {
                TreeNode* front = q.front();
                q.pop();
                level.push_back(front->val);
                if (front->left) q.push(front->left);
                if (front->right) q.push(front->right);
            }
            levels.push(level);
        }

        vector<vector<int>> result;
        while (!levels.empty()) {
            result.push_back(levels.top());
            levels.pop();
        }
        return result;
    }
};

TEST(Test_107, case_01) {
    TreeNode n15(15);
    TreeNode n7(7);
    TreeNode n20(20, &n15, &n7);
    TreeNode n9(9);
    TreeNode n3(3, &n9, &n20);

    Solution s;
    auto result = s.levelOrderBottom(&n3);
    for (int i = 0; i < static_cast<int>(result.size()); ++i) {
        for (int j = 0; j < static_cast<int>(result[i].size()); ++j) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}