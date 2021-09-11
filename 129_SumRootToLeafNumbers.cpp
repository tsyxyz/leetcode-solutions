#include <gtest/gtest.h>

#include <vector>
#include <unordered_map>

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
    int sumNumbers(TreeNode* root) {
        if (!root) return 0;
        return dfs(root, 0);
    }

private:
    int dfs(TreeNode* root, int preSum) {
        if (!root) return 0;
        preSum = preSum * 10 + root->val;
        if (root->left == nullptr && root->right == nullptr) {
            return preSum;
        }
        return dfs(root->left, preSum) + dfs(root->right, preSum);
    }
};