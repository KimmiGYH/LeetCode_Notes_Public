class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        //dp[i][j]表示最多飞 i 次航班到达目的地 j 位置时的最小价格
        vector<vector<int>> dp(k+2, vector<int>(n, 0x3f3f3f3f));
        dp[0][src] = 0;
        for (int i = 1; i <= k+1; ++i) {
            dp[i][src] = 0;
            for (auto& e : flights) {
                int a = e[0], b = e[1], w = e[2];
                dp[i][b] = min(dp[i][b], dp[i-1][a] + w);
            }
        }
        if (dp[k+1][dst] == 0x3f3f3f3f) return -1;
        return dp[k+1][dst];
    }
};