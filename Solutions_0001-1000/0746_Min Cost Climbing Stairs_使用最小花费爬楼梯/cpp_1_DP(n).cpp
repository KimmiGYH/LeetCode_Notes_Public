#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n + 1); // dp[i] 表示爬到第i层的最小 cost
        for (int i = 2; i < n + 1; ++i)
            dp[i] = min(dp[i-2] + cost[i-2], dp[i-1] + cost[i-1]);
        return dp.back();
    }
};