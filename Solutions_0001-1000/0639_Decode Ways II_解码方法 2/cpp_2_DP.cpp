#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int n = s.size(), MOD = 1e9 + 7;
        vector<long long> dp(n + 1);
        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= 26; j++) {
                char a = s[i - 1];
                if (j <= 9) {
                    if (a == '*' || a == j + '0')  dp[i] += dp[i - 1];
                } else if (i >= 2) {
                    char b = s[i - 2];
                    int y = j / 10, x = j % 10;
                    if ((b == y + '0' || b == '*' && y) && (a == x + '0' || a == '*' && x))
                        dp[i] += dp[i - 2];
                }
                dp[i] %= MOD;
            }
        }
        return dp[n];
    }
};