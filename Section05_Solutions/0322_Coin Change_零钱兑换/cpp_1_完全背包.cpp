#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 完全背包问题：f(i, j) = max( f(i-1, j), f(i, j - v) + w );
// 完全背包一维：f[j] = min( f[j], f[j - coins[i]] + 1 )

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, 1e8);
        dp[0] = 0;
        for (auto v : coins)
            for (int j = v; j <= amount; j++)
                dp[j] = min(dp[j], dp[j - v] + 1);
        if (dp[amount] == 1e8) return -1;
        return dp[amount];
    }
};