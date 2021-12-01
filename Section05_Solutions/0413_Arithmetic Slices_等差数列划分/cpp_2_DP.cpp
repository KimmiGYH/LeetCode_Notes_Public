class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int res = 0, n = nums.size();
        vector<int> dp(n, 0);
        for (int i = 2; i < n; ++i) {
            if (nums[i] - nums[i-1] == nums[i-1] - nums[i-2])            
                dp[i] = dp[i-1] + 1;
            res += dp[i];
        }
        return res;
    }
};