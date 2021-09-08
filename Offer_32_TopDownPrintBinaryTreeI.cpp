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
    vector<int> levelOrder(TreeNode* root) {
        if (!root) return {};

        queue<TreeNode*> q;
        q.push(root);
        vector<int> result;
        while (!q.empty()) {
            int levelCount = q.size();
            for (int i = 0; i < levelCount; ++i) {
                TreeNode* front = q.front();
                q.pop();
                result.push_back(front->val);
                if (front->left) q.push(front->left);
                if (front->right) q.push(front->right);
            }
        }

        return result;
    }
};

TEST(Test_Offer_32_I, case_01) {
    TreeNode n15(15);
    TreeNode n7(7);
    TreeNode n20(20, &n15, &n7);
    TreeNode n9(9);
    TreeNode n3(3, &n9, &n20);

    Solution s;
    auto result = s.levelOrder(&n3);
    for (int i = 0; i < static_cast<int>(result.size()); ++i) {
        cout << result[i] << " ";
    }
}