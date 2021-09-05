#include <gtest/gtest.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < static_cast<int>(inorder.size()); ++i) {
            inorderMap_[inorder[i]] = i;
        }

        TreeNode* root = buildTree(preorder, inorder,
                                   0, preorder.size() - 1,
                                   0, preorder.size() - 1);
        return root;
    }

private:
    TreeNode* buildTree(const vector<int>& preorder, const vector<int>& inorder,
                        int preorderLeft, int preorderRight,
                        int inorderLeft, int inorderRight) {
        if (preorderLeft > preorderRight) {
            return nullptr;
        }
        int rootVal = preorder[preorderLeft];
        int inorderRootIndex = inorderMap_[rootVal];

        int leftSize = inorderRootIndex - inorderLeft;

        TreeNode* root = new TreeNode(rootVal);
        root->left = buildTree(preorder, inorder,
                               preorderLeft + 1, preorderLeft + leftSize,
                               inorderLeft, inorderRootIndex - 1);
        root->right = buildTree(preorder, inorder,
                                preorderLeft + leftSize + 1, preorderRight,
                                inorderRootIndex + 1, inorderRight);
        return root;
    }

    map<int, int> inorderMap_;

};