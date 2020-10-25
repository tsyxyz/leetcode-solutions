#include <gtest/gtest.h>

#include <vector>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }

    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        for (int i = 0; i < kMaxNodeNum; ++i) {
            marked_create_nodes_[i] = false;
            marked_add_neighbors_[i] = false;
            nodes_[i] = nullptr;
        }

        DfsCreateNode(node);
        DfsAddNeighbors(node);

        return nodes_[node->val];
    }
private:
    void DfsCreateNode(Node* node) {
        marked_create_nodes_[node->val] = true;
        if (!nodes_[node->val]) {
            Node* n = new Node();
            n->val = node->val;
            nodes_[node->val] = n;
        }

        for (size_t i = 0; i < node->neighbors.size(); ++i) {
            if (!marked_create_nodes_[node->neighbors[i]->val]) {
                DfsCreateNode(node->neighbors[i]);
            }
        }
    }

    void DfsAddNeighbors(Node* node) {
        marked_add_neighbors_[node->val] = true;
        for (size_t i = 0; i < node->neighbors.size(); ++i) {
            nodes_[node->val]->neighbors.push_back(nodes_[node->neighbors[i]->val]);
        }

        for (size_t i = 0; i < node->neighbors.size(); ++i) {
            if (!marked_add_neighbors_[node->neighbors[i]->val]) {
                DfsAddNeighbors(node->neighbors[i]);
            }
        }
    }
private:
    enum {kMaxNodeNum = 101};
    bool marked_create_nodes_[kMaxNodeNum];
    bool marked_add_neighbors_[kMaxNodeNum];
    Node* nodes_[kMaxNodeNum];
};

TEST(TestCloneGraph, case01) {

}