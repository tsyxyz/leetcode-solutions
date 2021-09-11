#include <gtest/gtest.h>

#include <vector>

using namespace std;

using Graph = vector<vector<int>>;

//// !!还没完成
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        for (int red = edges.size() - 1; red >= 0; --red) {
            Graph graph;
            for (int i = 0; i < static_cast<int>(edges.size()); ++i) {
                if (i == red) continue;
                vector<int> edge = edges[i];

            }
        }
    }
};