// Nick White: https://youtu.be/ZwDDLAeeBM0

class Solution {
    public int rob(int[] nums) {
        if (nums.length == 0) return 0;

        int dp[] = new int[nums.length + 1];
        dp[0] = 0;
        dp[1] = nums[0];

        for (int i = 1; i < nums.length; i++) {
            dp[i+1] = Math.max(dp[i], dp[i-1] + nums[i]);
        }
        return dp[nums.length];
    }
}

/**
[1, 2, 3, 1]
dp [0, 1, 2, 4, 4]
dp[2] = max(dp[1], dp[0] + nums[1]) = max(1, 0 + 2) = 2;
dp[3] = max(dp[2], dp[1] + nums[2]) = max(2, 1 + 3) = 4;
dp[4] = max(dp[3], dp[2] + nums[3]) = max(4, 2 + 1) = 4;
*/