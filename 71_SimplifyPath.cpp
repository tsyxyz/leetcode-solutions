#include <gtest/gtest.h>

#include <string>
#include <stack>

using namespace std;

/*
 * 如果是字符，入栈
 * 如果前一个也是字符、字符串，那就在前一个尾部添加当前字符
 * 如果是/：如果前一个也是/，那就不入栈，如果前一个不是/，那就入栈
 * 如果是.：出栈一个
 * 如果出栈后栈为空，就入栈一个/
 * 结束后，将栈内元素全部pop出
 * 如果最后一个是/就删掉
 *
 */

class Solution {
public:
    string simplifyPath(string path) {
        stack<string> elements;
        for (auto it : path) {
            if (it == '.') {
                if (!elements.empty()) {
                    elements.pop();
                }
            } else if (it == '/') {
                if (elements.empty() || elements.top() != string(1, '/')) {
                    elements.push(string(1, it));
                }
            } else {
                if (elements.empty()) {
                    elements.push(string(1, it));
                } else {
                    string top = elements.top();
                    if (top != string(1, '/')) {
                        top += string(1, it);
                        elements.pop();
                    } else {
                        top = string(1, it);
                    }
                    elements.push(top);
                }
            }
        }

        if (elements.empty()) {
            return "/";
        }

        if (elements.size() > 2 && elements.top() == string(1, '/')) {
            elements.pop();
        }
        stack<string> reverseElements;
        size_t elementsNum = elements.size();
        for (size_t i = 0; i < elementsNum; ++i) {
            reverseElements.push(elements.top());
            elements.pop();
        }
        string result;
        for (size_t i = 0; i < elementsNum; ++i) {
            result += reverseElements.top();
            reverseElements.pop();
        }
        return result;
    }
};

TEST(TestSimplifyPath, case01) {
    Solution solution;
    string input = "/home//foo/a//b////c/d//././/..";
    string output = solution.simplifyPath(input);
    EXPECT_EQ("/home/foo/a/b/c", output);
}

TEST(TestSimplifyPath, case02) {
    Solution solution;
    string input = "/a//b////c/d//././/..";
    string output = solution.simplifyPath(input);
    EXPECT_EQ("/a/b/c", output);
}

TEST(TestSimplifyPath, case03) {
    Solution solution;
    string input = "/a/../../b/../c//.//";
    string output = solution.simplifyPath(input);
    EXPECT_EQ("/c", output);
}

TEST(TestSimplifyPath, case04) {
    Solution solution;
    string input = "/a/./b/../../c/";
    string output = solution.simplifyPath(input);
    EXPECT_EQ("/c", output);
}

TEST(TestSimplifyPath, case05) {
    Solution solution;
    string input = "/home//foo/";
    string output = solution.simplifyPath(input);
    EXPECT_EQ("/home/foo", output);
}

TEST(TestSimplifyPath, case06) {
    Solution solution;
    string input = "/../";
    string output = solution.simplifyPath(input);
    EXPECT_EQ("/", output);
}

TEST(TestSimplifyPath, case07) {
    Solution solution;
    string input = "/..";
    string output = solution.simplifyPath(input);
    EXPECT_EQ("/", output);
}