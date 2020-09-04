#include <deque>

#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        deque<int> seq;
        deque<int> seq_rev;
        while (x != 0) {
            int remainder = x % 10;
            x = x / 10;
            seq.push_back(remainder);
            seq_rev.push_front(remainder);
        }
        for (size_t i = 0; i < seq.size(); ++i) {
            if (seq[i] != seq_rev[i]) {
                return false;
            }
        }

        return true;
    }
};

TEST(TestPalindromeNumber, case0) {
    int input = 121;
    bool answer = true;
    Solution solution;
    bool output = solution.isPalindrome(input);
    EXPECT_EQ(output, answer);
}

TEST(TestPalindromeNumber, case1) {
    int input = -121;
    bool answer = false;
    Solution solution;
    bool output = solution.isPalindrome(input);
    EXPECT_EQ(output, answer);
}