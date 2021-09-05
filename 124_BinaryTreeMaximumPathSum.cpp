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
    int maxPathSum(TreeNode* root) {
        count(root);
        return maxSum_;
    }

private:
    int count(TreeNode* root) {
        if (!root) return 0;

        int leftContribute = count(root->left);
        int rightContribute = count(root->right);

        int mayBeMax = root->val + max(0, leftContribute) + max(0, rightContribute);
        maxSum_ = max(mayBeMax, maxSum_);

        int contribute = root->val + max(0, max(leftContribute, rightContribute));
        return contribute;
    }

    int maxSum_ = INT32_MIN;
};

TEST(Test_124, case_01) {
    TreeNode n15(15);
    TreeNode n7(7);
    TreeNode n20(20, &n15, &n7);
    TreeNode n9(9);
    TreeNode n_10(-10, &n9, &n20);

    Solution s;
    int result = s.maxPathSum(&n_10);
    cout << result;
}