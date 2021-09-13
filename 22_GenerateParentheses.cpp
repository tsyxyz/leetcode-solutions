#include <gtest/gtest.h>

#include <vector>
#include <string>
#include <unordered_map>
#include <stack>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        n_ = n;
        count_['('] = n;
        count_[')'] = n;
        string str;
        backtrack(str);
        return result_;
    }

private:
    void backtrack(string& str) {
        if (static_cast<int>(str.size()) == 2 * n_) {
            if (checkValid(str)) {
                result_.push_back(str);
            }
            return;
        }
        vector<char> candidates = {'(', ')'};
        for (auto ch : candidates) {
            if (count_[ch] > 0) {
                str.push_back(ch);
                count_[ch]--;
                backtrack(str);
                str.pop_back();
                count_[ch]++;
            }
        }
    }

    bool checkValid(const string& str) {
        stack<char> s;
        for (auto ch : str) {
            if (ch == '(') {
                s.push(ch);
            } else {
                if (s.empty()) return false;
                s.pop();
            }
        }
        return s.empty();
    }

private:
    int n_;
    unordered_map<char, int> count_;
    vector<string> result_;
};

TEST(Test_22, case_01) {
    Solution s;
    auto ret = s.generateParenthesis(1);
    for (auto str : ret) {
        cout << str << " ";
    }
}