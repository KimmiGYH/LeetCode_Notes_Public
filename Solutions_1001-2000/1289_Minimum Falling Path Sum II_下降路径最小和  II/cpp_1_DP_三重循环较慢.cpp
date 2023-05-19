#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& arr) {
        int m = arr.size(), n = arr[0].size();
        vector<vector<int>> f(m, vector<int>(n, INT_MAX));
        
        for (int j = 0; j < n; j++)
            f[0][j] = arr[0][j];
        
        for (int i = 1; i < m; i++)
            for (int j = 0; j < n; j++)
                for (int k = 0; k < m; k++)
                    if (j != k)
                        f[i][j] = min(f[i][j], f[i - 1][k] + arr[i][j]);
        
        int res = INT_MAX;
        for (int j = 0; j < n; j++)
            res = min(res, f[m - 1][j]);
        
        return res;        
    }
};