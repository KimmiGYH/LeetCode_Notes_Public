#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// m*nlogn
class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        int m = costs.size(), n = costs[0].size();
        if (!m || !n) return 0;

        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int j = 0; j < n; j++)
        dp[0][j] = costs[0][j];

        for (int i = 1; i < m; i++) {
            vector<pair<int, int>> temp;
            for (int k = 0; k < n; k++)
                temp.push_back({dp[i - 1][k], k});
            sort(temp.begin(), temp.end());

            for (int j = 0; j < n; j++) {
                if (j != temp[0].second)
                    dp[i][j] = temp[0].first + costs[i][j];
                else
                    dp[i][j] = temp[1].first + costs[i][j];
            }
        }
        
        int res = INT_MAX;
        for (int j = 0; j < n; j++)
            res = min(res, dp[m - 1][j]);
        
        return res;
    }
};