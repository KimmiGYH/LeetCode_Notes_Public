#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        if (m == 0 || n == 0)  return 0;

        vector<vector<int>> dp(m, vector<int>(n));

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                if (obstacleGrid[i][j] == 0) {
                    if (!i && !j) dp[i][j] = 1;
                    else {
                        if (i > 0) dp[i][j] += dp[i - 1][j];
                        if (j > 0) dp[i][j] += dp[i][j - 1];
                    }
                }
            }
        return dp[m - 1][n - 1];
    }
};