#include <gtest/gtest.h>

#include <map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return nullptr;

        path_[root->val] = nullptr;

        dfs(root);

        while (p != nullptr) {
            check_[p->val] = true;
            p = path_[p->val];
        }

        while (q != nullptr) {
            if (check_[q->val]) return q;
            q = path_[q->val];
        }
        return nullptr;
    }

private:
    void dfs(TreeNode* root) {
        if (root->left) {
            path_[root->left->val] = root;
            dfs(root->left);
        }
        if (root->right) {
            path_[root->right->val] = root;
            dfs(root->right);
        }
    }

    map<int, TreeNode*> path_;
    map<int, bool> check_;
};