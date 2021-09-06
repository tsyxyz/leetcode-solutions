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
        bool result = isValidBST(root, nullptr, nullptr);
        return result;
    }

private:
    bool isValidBST(TreeNode* root, TreeNode* min, TreeNode* max) {
        if (!root) return true;

        if (min && (root->val <= min->val)) return false;
        if (max && (root->val >= max->val)) return false;
        return isValidBST(root->left, min, root) && isValidBST(root->right, root, max);
    }
};

TEST(Test_98, case_01) {
    TreeNode n3(3);
    TreeNode n6(6);
    TreeNode n4(4, &n3, &n6);
    TreeNode n1(1);
    TreeNode n5(5, &n1, &n4);

    Solution s;
    bool result = s.isValidBST(&n5);
    EXPECT_FALSE(result);
}