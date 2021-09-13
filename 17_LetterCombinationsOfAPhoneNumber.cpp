#include <gtest/gtest.h>

#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }
        for (char digit = '2', ch = 'a'; digit <= '9'; ++digit) {
            vector<char> content;
            int loopCount = 3;
            if (digit == '7' || digit == '9') {
                loopCount = 4;
            }
            for (int i = 0; i < loopCount; ++i) {
                content.push_back(ch);
                ch++;
            }
            dialPanel_[digit] = content;
        }

        digits_ = digits;
        string str;
        backtrack(0, str);
        return result_;
    }

private:
    void backtrack(int numIndex, string& str) {
        if (str.size() == digits_.size()) {
            result_.push_back(str);
            return;
        }
        vector<char> candidates = dialPanel_[digits_[numIndex]];
        for (auto ch : candidates) {
            str.push_back(ch);
            backtrack(numIndex + 1, str);
            str.pop_back();
        }
    }

private:
    string digits_;
    vector<string> result_;
    unordered_map<char, vector<char>> dialPanel_;
};

TEST(Test_17, case_01) {
    string str("23");
    Solution s;
    auto ret = s.letterCombinations(str);
    for (auto st : ret) {
        cout << st << " ";
    }
}