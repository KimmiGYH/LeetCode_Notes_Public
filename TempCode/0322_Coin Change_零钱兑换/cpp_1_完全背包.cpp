#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 完全背包问题：f(i, j) = max{ f(i-1, j), f(i, j - v) + w };

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        for (auto v : coins)
            for (int j = v; j <= amount; j++)
                dp[j] = min(dp[j], dp[j - v] + 1);
        if (dp[amount] == INT_MAX) return -1;
        return dp[amount];
    }
};