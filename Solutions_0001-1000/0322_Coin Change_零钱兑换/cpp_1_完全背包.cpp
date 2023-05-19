#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 完全背包问题：f(i, j) = max( f(i-1, j), f(i, j - v) + w );
// 完全背包一维：f[j] = min( f[j], f[j - coins[i]] + 1 )

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> f(amount + 1, 1e8);
        f[0] = 0;
        for (auto v : coins)
            for (int j = v; j <= amount; j++)
                f[j] = min(f[j], f[j - v] + 1);
        if (f[amount] == 1e8) return -1;
        return f[amount];
    }
};