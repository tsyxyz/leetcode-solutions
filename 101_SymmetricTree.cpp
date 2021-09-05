#include <gtest/gtest.h>

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
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;

        bool result = check(root, root);
        return result;
    }

    bool check(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        if (!p || !q) return false;

        return (p->val == q->val) && check(p->left, q->right) && check(p->right, q->left);
    }
};