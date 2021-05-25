#include <unordered_map>
#include <string>

#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> need, window;
        for (char c : t) need[c]++;

        int left = 0, right = 0;
        int valid = 0;
        int start = 0, len = INT32_MAX;
        while (right < static_cast<int>(s.size())) {
            char c = s[right];
            right++;

            if (need.count(c)) {
                window[c]++;
                if (window[c] == need[c]) {
                    valid++;
                }
            }

            while (valid == static_cast<int>(need.size())) {
                if (right - left < len) {
                    start = left;
                    len = right - left;
                }
                char d = s[left];
                left++;
                if (need.count(d)) {
                    if (window[d] == need[d]) {
                        valid--;
                    }
                    window[d]--;
                }
            }
        }
        return len == INT32_MAX ? "" : s.substr(start, len);
    }
};

TEST(TestMinimumWindowSubstring, case01) {
    Solution solution;
    string s = "ADOBECODEBANC", t = "ABC";
    string result = solution.minWindow(s, t);
    cout << result << endl;
}