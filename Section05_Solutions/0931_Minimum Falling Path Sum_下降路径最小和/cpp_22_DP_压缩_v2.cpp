#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int n = A.size(), m = A[0].size();
        vector<int> f(n, INT_MAX);
        vector<int> cur(m, INT_MAX);
        int res = INT_MAX;

        for (int j = 0; j < m; j++)
            cur[j] = A[0][j];
        
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                f[j] = cur[j] + A[i][j];
                if (j > 0)     f[j] = min(f[j], cur[j - 1] + A[i][j]);
                if (j < m - 1) f[j] = min(f[j], cur[j + 1] + A[i][j]);
            }
            cur = f;
        }
        
        for (int j = 0; j < m; j++)
            res = min(res, cur[j]);
        
        return res;
    }
};