#include <cmath>

#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        vector<int> bits;
        for (;;) {
            int remainder = x % 10;
            bits.push_back(remainder);
            x = x / 10;
            if (x == 0) {
                break;
            }
        }
        long long result = 0;
        for (size_t i = 0; i < bits.size(); ++i) {
            result += bits[i] * pow(10, bits.size() - i - 1);
        }

        if (result > MAX_INT || result < static_cast<signed int>(MIN_INT)) {
            result = 0;
        }

        return static_cast<int>(result);
    }

    static const int MAX_INT = 0x7fffffff;
    static const int MIN_INT = 0x80000000;
};

TEST(test_reverse_integer, case0) {
    int input = 123;
    int output = 321;
    Solution solution;
    int answer = solution.reverse(input);
    EXPECT_EQ(answer, output);
}

TEST(test_reverse_integer, case1) {
    int input = -123;
    int output = -321;
    Solution solution;
    int answer = solution.reverse(input);
    EXPECT_EQ(answer, output);
}

TEST(test_reverse_integer, case2) {
    int input = 120;
    int output = 21;
    Solution solution;
    int answer = solution.reverse(input);
    EXPECT_EQ(answer, output);
}

TEST(test_reverse_integer, case3) {
    int input = Solution::MAX_INT;
    int output = 0;
    Solution solution;
    int answer = solution.reverse(input);
    EXPECT_EQ(answer, output);
}

TEST(test_reverse_integer, case4) {
    int input = Solution::MIN_INT;
    int output = 0;
    Solution solution;
    int answer = solution.reverse(input);
    EXPECT_EQ(answer, output);
}