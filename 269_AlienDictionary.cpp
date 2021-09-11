#include <gtest/gtest.h>

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

//// !还没完成
class Solution {
public:
    string alienOrder(vector<string>& words) {
        for (int i = 0; i < static_cast<int>(words.size()) - 1; ++i) {
            string first = words[i];
            string second = words[i + 1];
            int minLen = min(first.size(), second.size());
            int j = 0;
            for (; j < minLen; ++j) {
                if (first[j] == second[j]) {
                    continue;
                } else {
                    graph_[first[j]].insert(second[j]);
                    break;
                }
            }
        }

        return 0;
    }

private:
    unordered_map<char, set<char>> graph_;
};

TEST(Test_269, case_01) {
    vector<string> words = {"wrt","wrf","er","ett","rftt"};
    Solution s;
    s.alienOrder(words);
}