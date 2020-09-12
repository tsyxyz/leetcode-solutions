#include <gtest/gtest.h>

#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> input;
        for (auto it : s) {
            if (it == '(' || it == '[' || it == '{') {
                input.push(it);
            } else if (it == ')') {
                if (input.empty())
                    return false;
                if (input.top() != '(')
                    return false;
                input.pop();
            } else if (it == ']') {
                if (input.empty())
                    return false;
                if (input.top() != '[')
                    return false;
                input.pop();
            } else if (it == '}') {
                if (input.empty())
                    return false;
                if (input.top() != '{')
                    return false;
                input.pop();
            }
        }

        if (input.empty()) {
            return true;
        }
        return false;
    }
};

TEST(TestValidParentheses, case01) {
    Solution solution;
    string input = "";
    bool output = solution.isValid(input);
    EXPECT_EQ(true, output);
}

TEST(TestValidParentheses, case02) {
    Solution solution;
    string input = "()";
    bool output = solution.isValid(input);
    EXPECT_EQ(true, output);
}

TEST(TestValidParentheses, case03) {
    Solution solution;
    string input = "()[]{}";
    bool output = solution.isValid(input);
    EXPECT_EQ(true, output);
}

TEST(TestValidParentheses, case04) {
    Solution solution;
    string input = "(]";
    bool output = solution.isValid(input);
    EXPECT_EQ(false, output);
}

TEST(TestValidParentheses, case05) {
    Solution solution;
    string input = "([)]";
    bool output = solution.isValid(input);
    EXPECT_EQ(false, output);
}

TEST(TestValidParentheses, case06) {
    Solution solution;
    string input = "{[]}";
    bool output = solution.isValid(input);
    EXPECT_EQ(true, output);
}

TEST(TestValidParentheses, case07) {
    Solution solution;
    string input = "])}";
    bool output = solution.isValid(input);
    EXPECT_EQ(false, output);
}

TEST(TestValidParentheses, case08) {
    Solution solution;
    string input = "(])";
    bool output = solution.isValid(input);
    EXPECT_EQ(false, output);
}