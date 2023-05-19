#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {

        int n = nums.size();
        if (n == 0)
            return 0;
        
        // dp[i] 表示考虑抢劫 nums[i...n-1] 所能获得的最大收益
        vector<int> dp(n, -1);

        dp[n-1] = nums[n-1]; // n >= 1
        for (int i = n - 2; i >= 0; i--) 
            for (int j = i; j < n; j++)
                dp[i] = max( dp[i], nums[j] + (j+2 < n ? dp[j+2] : 0) );
        return dp[0];
    }
};