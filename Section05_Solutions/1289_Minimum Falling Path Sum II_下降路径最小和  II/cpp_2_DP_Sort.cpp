#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// m*nlogn
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& arr) {
        int m = arr.size(), n = arr[0].size();
        
        vector<vector<int>> f(m, vector<int>(n, INT_MAX));
        
        for (int j = 0; j < n; j++)
            f[0][j] = arr[0][j];
        
        for (int i = 1; i < m; i++) {
            vector<pair<int, int>> temp;
            for (int k = 0; k < n; k++)
                temp.push_back({f[i - 1][k], k});
            sort(temp.begin(), temp.end());
            
            for (int j = 0; j < n; j++) {
                if (j != temp[0].second)
                    f[i][j] = temp[0].first + arr[i][j];
                else
                    f[i][j] = temp[1].first + arr[i][j];
            }
        }
        
        int res = INT_MAX;
        for (int j = 0; j < n; j++)
            res = min(res, f[m - 1][j]);
        
        return res;
    }
};