#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    double largestSumOfAverages(vector<int>& A, int K) {
        int n = A.size();
        // 把前 n 个元素划分成 K 组 能够取得的最大值是多少
        vector<vector<double>> dp(K + 1, vector<double>(n + 1, 0.0));
        vector<double> sums(n + 1, 0.0);
        for (int i = 1; i <= n; ++i) {
            sums[i] = sums[i - 1] + A[i - 1];
            dp[1][i] = sums[i] / i; // 把前 i 个元素划分成一组
        }
        
        for (int k = 2; k <= K; ++k)
            for (int i = k; i <= n; ++i) // 划分成 k 组至少需要 k 个元素
                for (int j = k - 1; j < i; ++j)
                    dp[k][i] = max(dp[k][i], dp[k - 1][j] + (sums[i] - sums[j]) / (i - j));
        
        return dp[K][n];
    }
};