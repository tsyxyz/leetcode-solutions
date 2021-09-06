#include <gtest/gtest.h>

#include <vector>
#include <map>

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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for (int i = 0; i < static_cast<int>(inorder.size()); ++i) {
            inorderIndex_[inorder[i]] = i;
        }

        TreeNode* result = buildTree(inorder, postorder,
                                     0, inorder.size() - 1,
                                     0, postorder.size() - 1);
        return result;
    }


private:
    TreeNode* buildTree(const vector<int>& inorder, const vector<int>& postorder,
                        int inorderLeft, int inorderRight,
                        int postorderLeft, int postorderRight) {
        if (postorderRight < postorderLeft) return nullptr;

        int rootVal = postorder[postorderRight];
        int rootInorderIndex = inorderIndex_[rootVal];
        int rightCount = inorderRight - rootInorderIndex;

        TreeNode* root = new TreeNode(rootVal);
        root->right = buildTree(inorder, postorder,
                                rootInorderIndex + 1, inorderRight,
                                postorderRight - rightCount, postorderRight - 1);
        root->left = buildTree(inorder, postorder,
                               inorderLeft, rootInorderIndex - 1,
                               postorderLeft, postorderRight - rightCount - 1);
        return root;
    }

    map<int, int> inorderIndex_;
};

TEST(Test_106, case_01) {
    vector<int> inorder = {9,3,15,20,7};
    vector<int> postorder = {9,15,7,20,3};

    Solution s;
    TreeNode result = s.buildTree(inorder, postorder);
}