#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// O(m*n)
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& arr) {
        int m = arr.size(), n = arr[0].size();
        vector<vector<int>> f(m, vector<int>(n, INT_MAX));
        vector<vector<int>> left(m, vector<int>(n, INT_MAX));
        vector<vector<int>> right(m, vector<int>(n, INT_MAX));
        
        for (int j = 0; j < n; j++)
            f[0][j] = arr[0][j];
        
        for (int i = 1; i < n; i++) {
            
            left[i - 1][0] = f[i - 1][0];
            for (int j = 1; j < m; j++)
                left[i - 1][j] = min(left[i - 1][j - 1], f[i - 1][j]);
            
            right[i - 1][n - 1] = f[i - 1][n - 1];
            for (int j = m - 2; j >= 0; j--)
                right[i - 1][j] = min(right[i - 1][j + 1], f[i -1][j]);
            
            for (int j = 0; j < n; j++) {
                if (j > 0)
                    f[i][j] = min(f[i][j], left[i - 1][j - 1] + arr[i][j]);
                if (j < m - 1)
                    f[i][j] = min(f[i][j], right[i - 1][j + 1] + arr[i][j]);
            }        
        }
        
        int res = INT_MAX;
            
        for (int j = 0; j < m; j++)
            res = min(res, f[m - 1][j]);

        return res;   
    }
};