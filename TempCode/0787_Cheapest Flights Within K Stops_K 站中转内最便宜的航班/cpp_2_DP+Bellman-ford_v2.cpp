class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dp(n, 0x3f3f3f3f);
        dp[src] = 0;
        k++;
        while (k--) {
            vector<int> cur = dp;
            for (auto& e : flights) {
                int a = e[0], b = e[1], w = e[2];
                cur[b] = min(cur[b], dp[a] + w);
            }
            dp = cur;
        }
        if (dp[dst] == 0x3f3f3f3f) return -1;
        return dp[dst];
    }
};
