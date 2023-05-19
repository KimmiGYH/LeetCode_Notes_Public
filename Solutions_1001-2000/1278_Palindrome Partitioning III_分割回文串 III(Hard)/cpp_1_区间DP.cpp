#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Time complexity: O(n*k*n) <= O(n^3)
// Space complexity: O(n*k)

class Solution {
public:
    int palindromePartition(string s, int K) {
        int n = s.length();
        vector<vector<int>> cost(n, vector<int>(n));
        for (int l = 2; l <= n; ++l)
            for (int i = 0, j = l - 1; j < n; ++i, ++j)
                cost[i][j] = (s[i] != s[j]) + cost[i + 1][j - 1];
        
        // dp[i][k] := min cost to make k strings using first i letters
        // Init: dp[i][1] = cost(0, i)
        // res: dp[n -1][K]
        vector<vector<int>> dp(n, vector<int>(K + 1, INT_MAX / 2));
        for (int i = 0; i < n; ++i) {
            dp[i][1] = cost[0][i];
            for (int k = 2; k <= K; ++k)
                for (int j = 0; j < i; ++j)
                    dp[i][k] = min(dp[i][k], dp[j][k - 1] + cost[j + 1][i]);
        }
        return dp[n - 1][K];
    }
};