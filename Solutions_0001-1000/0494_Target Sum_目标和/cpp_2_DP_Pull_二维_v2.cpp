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
        for (int i = 1; i < dp.size(); i++) {
            for (int j = 0; j < dp[i].size(); j++) {
                if (j - nums[i - 1] >= 0)
                    dp[i][j] += dp[i - 1][j - nums[i - 1]];
                if (j + nums[i - 1] < dp[i].size())
                    dp[i][j] += dp[i - 1][j + nums[i - 1]];
            }
        }
        return dp[n][sum + S];
    }
};