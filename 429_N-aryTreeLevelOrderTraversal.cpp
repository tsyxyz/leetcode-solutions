#include <gtest/gtest.h>

#include <vector>
#include <queue>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if (!root) return {};

        queue<Node*> q;
        q.push(root);

        vector<vector<int>> levels;
        while (!q.empty()) {
            vector<int> level;
            int levelCount = q.size();
            for (int i = 0; i < levelCount; ++i) {
                Node* front = q.front();
                q.pop();
                level.push_back(front->val);
                for (int j = 0; j < static_cast<int>(front->children.size()); ++j) {
                    if (front->children[j]) {
                        q.push(front->children[j]);
                    }
                }
            }
            levels.push_back(level);
        }
        return levels;
    }
};