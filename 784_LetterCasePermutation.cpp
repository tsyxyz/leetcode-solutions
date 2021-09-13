#include <gtest/gtest.h>

#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        s_ = s;
        string str;
        backtrack(0, str);
        return result_;
    }

private:
    void backtrack(int index, string& str) {
        if (str.size() == s_.size()) {
            result_.push_back(str);
            return;
        }
        char ch = s_[index];
        vector<char> candidates = {ch};
        if (isalpha(ch)) {
            if (ch >= 'a' && ch <= 'z') {
                candidates.push_back(toupper(ch));
            } else {
                candidates.push_back(tolower(ch));
            }
        }
        for (auto c : candidates) {
            str.push_back(c);
            backtrack(index + 1, str);
            str.pop_back();
        }
    }

private:
    string s_;
    vector<string> result_;
};

TEST(Test_784, case_01) {
    string str = "a1b2";
    Solution s;
    auto ret = s.letterCasePermutation(str);
    for (auto st : ret) {
        cout << st << " ";
    }
}