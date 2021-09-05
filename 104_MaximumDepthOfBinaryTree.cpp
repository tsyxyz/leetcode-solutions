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
    int maxDepth(TreeNode* root) {
        if (!root) return 0;

        int depth = 0;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            size_t levelCount = q.size();
            for (size_t i = 0; i < levelCount; ++i) {
                TreeNode* front = q.front();
                q.pop();
                if (front->left) q.push(front->left);
                if (front->right) q.push(front->right);
            }
            depth++;
        }

        return depth;
    }
};

TEST(Test_104, case_01) {
    TreeNode n15(15);
    TreeNode n7(7);
    TreeNode n20(20, &n15, &n7);
    TreeNode n9(9);
    TreeNode n3(3, &n9, &n20);

    Solution s;
    int result = s.maxDepth(&n3);
    cout << result;
}