#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <queue>

#include <gtest/gtest.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        traverse(root);
        string ret("[");
        for (auto it = result_.begin(); it != result_.end() - 1; ++it) {
            ret += *it;
            ret += ",";
        }
        ret += *(result_.end() - 1);
        ret += "]";
        result_.clear();
        return ret;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.length() < 3) return NULL;
        string data_trunc = data.substr(1, data.length() - 2);
        queue<string> input = split(data_trunc, ',');
        TreeNode* root = addNode(input);
        return root;
    }
private:
    void traverse(TreeNode* root) {
        if (root == NULL) {
            result_.push_back("null");
            return;
        }
        result_.push_back(std::to_string(root->val));
        traverse(root->left);
        traverse(root->right);
    }

    TreeNode* addNode(queue<string>& q) {
        if (q.front() == string("null")) {
            q.pop();
            return NULL;
        }
        TreeNode* root = new TreeNode(stoi(q.front()));
        q.pop();
        root->left = addNode(q);
        root->right = addNode(q);
        return root;
    }

    std::queue<std::string> split(const string& str, char delimiter) {
        std::istringstream ss(str);
        std::string token;
        std::queue<std::string> result;
        while (std::getline(ss, token, delimiter)) {
            result.push(token);
        }
        return result;
    }

private:
    vector<string> result_;
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

TEST(TestSerializeDeserializeBinaryTree, serialize) {
    TreeNode n_1(1);
    TreeNode n_2(2);
    TreeNode n_3(3);
    TreeNode n_4(4);
    TreeNode n_5(5);
    n_1.left = &n_2;
    n_1.right = &n_3;
    n_3.left = &n_4;
    n_3.right = &n_5;

    Codec codec;
    string answer = "[1,2,null,null,3,4,null,null,5,null,null]";
    string result = codec.serialize(&n_1);
    EXPECT_EQ(answer, result);
}

TEST(TestSerializeDeserializeBinaryTree, deserialize) {
    Codec codec;
    string input = "[1,2,null,null,3,4,null,null,5,null,null]";
    TreeNode* result = codec.deserialize(input);
    string output = codec.serialize(result);
    EXPECT_EQ(input, output);
}