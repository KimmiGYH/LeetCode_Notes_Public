class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            if (i & 1)
                dp[i] = dp[i>>1] + 1; //或写成 dp[i] = dp[i - 1] + 1;
            else
                dp[i] = dp[i >> 1];
        }
        return dp;
    }
};

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n + 1, 0);
        for (int i = 1; i <= n; ++i)
            dp[i] = i & 1? dp[i-1] + 1 : dp[i>>1];
            // 等价于 dp[i] - dp[i & (i-1)] + 1;
        return dp;
    }
};