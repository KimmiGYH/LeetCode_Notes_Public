#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty())  return "";
        int n = s.size(), left = 0, len = 1;
        vector<vector<bool>> dp(n, vector<bool>(n));
        for (int j = 0; j < n; ++j) {
            dp[j][j] = 1;
            for (int i = 0; i < j; ++i) {
                dp[i][j] = (s[j] == s[i] && (i + 1 > j - 1 || dp[i + 1][j - 1]));
                if (dp[i][j] && len < j - i + 1) {
                    len = j - i + 1;
                    left = i;
                }
            }
        }
        return s.substr(left, len);
    }
};