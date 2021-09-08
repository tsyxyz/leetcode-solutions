#include <gtest/gtest.h>

#include <vector>
#include <unordered_map>
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
    bool isCousins(TreeNode* root, int x, int y) {
        if (!root) return false;

        queue<TreeNode*> q;
        q.push(root);

        int curDepth = -1;
        while (!q.empty()) {
            curDepth += 1;
            int levelCount = q.size();
            for (int i = 0; i < levelCount; ++i) {
                TreeNode* front = q.front();
                q.pop();
                depth_[front->val] = curDepth;
                if (front->left) {
                    q.push(front->left);
                    parent_[front->left->val] = front->val;
                }
                if (front->right) {
                    q.push(front->right);
                    parent_[front->right->val] = front->val;
                }
            }
        }

        if (parent_.count(x) == 0 || parent_.count(y) == 0) return false;
        if (parent_[x] != parent_[y]) return false;
        if (depth_[x] != depth_[y]) return false;

        return true;
    }

private:
    unordered_map<int, int> parent_;
    unordered_map<int, int> depth_;
};