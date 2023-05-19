#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
Input:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
Output: 7
*/

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(); // 行数
        if (!m) return 0;
        int n = grid[0].size(); // 求列数

        vector<vector<int>> f(m, vector<int>(n, INT_MAX)); // 状态数组
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                if (!i && !j)
                    f[i][j] = grid[i][j]; // 如果是起点
                else {
                    if (i)  f[i][j] = min(f[i][j], f[i - 1][j] + grid[i][j]);
                    if (j)  f[i][j] = min(f[i][j], f[i][j - 1] + grid[i][j]);
                }
            }
        return f[m - 1][n - 1];
    }
};