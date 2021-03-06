#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    int minCut(string s) {
        int n = s.length();
        // valid[i][j] = 1 if s[i~j] is palindrome, otherwise 0
        vector<vector<int>> valid(n, vector<int>(n, 1));
        
        // dp[i] = min cuts of s[0~i]
        vector<int> dp(n, n); // 假设 n 刀
        
        for (int l = 2; l <= n; ++l)
            for (int i = 0, j = i + l - 1; j < n; ++i, ++j)
                valid[i][j] = s[i] == s[j] && valid[i + 1][j - 1];
        
        for (int i = 0; i < n; ++i) {
            if (valid[0][i]) { // 如果本身是回文字符串，则不需要切割
                dp[i] = 0;
                continue;
            }
            for (int j = 0; j < i; ++j)
                if (valid[j + 1][i]) // 如果右边部分合法
                    dp[i] = min(dp[i], dp[j] + 1);
        }
        
        return dp[n - 1];
    }
};