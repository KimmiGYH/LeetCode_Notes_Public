#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int n = A.size(), m = A[0].size();
        vector<vector<int>> f(n, vector<int>(m, INT_MAX));
        
        for (int j = 0; j < m; j++)
            f[0][j] = A[0][j];
        
        for (int i = 1; i < n; i++)
            for (int j = 0; j < m; j++) {
                f[i][j] = f[i - 1][j] + A[i][j];
                if (j > 0)
                    f[i][j] = min(f[i][j], f[i - 1][j - 1] + A[i][j]);
                if (j < m - 1)
                    f[i][j] = min(f[i][j], f[i - 1][j + 1] + A[i][j]);
            }
        
        int res = INT_MAX;
        for (int j = 0; j < m; j++)
            res = min(res, f[n - 1][j]);
        
        return res;
    }
};