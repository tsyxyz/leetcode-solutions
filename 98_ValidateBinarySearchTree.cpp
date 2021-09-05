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
    bool isValidBST(TreeNode* root) {
        if (!root) return true;

        bool validLeft = isValidBST(root->left);
        bool validRight = isValidBST(root->right);
        bool validCurrent = true;
        if (root->left && root->left->val >= root->val) {
            validCurrent = false;
        }
        if (root->right && root->right->val <= root->val) {
            validCurrent = false;
        }

        if (root->left) {
            TreeNode* p = root->left;
            while (!p->right) {
                p = p->right;
            }
            if (p->val >= root->val) {
                validCurrent = false;
            }
        }

        if (root->right) {
            TreeNode* p = root->right;
            while (!p->left) {
                p = p->left;
            }
            if (p->val <= root->val) {
                validCurrent = false;
            }
        }

        return validCurrent && validLeft && validRight;
    }
};