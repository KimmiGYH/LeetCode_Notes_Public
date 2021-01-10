#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (!(-sum <= S && S <= sum)) return 0;
        vector<vector<int>> dp(n + 1, vector<int>(2*sum + 1, 0));
        dp[0][0 + sum] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = -sum; j <= sum; j++) {
                if (j - nums[i - 1] >= -sum)
                    dp[i][j + sum] += dp[i - 1][j - nums[i - 1] + sum];
                if (j + nums[i - 1] <= sum)
                    dp[i][j + sum] += dp[i - 1][j + nums[i - 1] + sum];
            }
        }
        return dp[n][S + sum];
    }
};