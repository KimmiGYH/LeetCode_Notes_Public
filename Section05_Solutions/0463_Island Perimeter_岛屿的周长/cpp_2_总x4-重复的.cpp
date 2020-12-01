#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;
        int m = grid.size();
        int n = grid[0].size();
        int area = 0; // 陆地数量
        int conn = 0; // 相邻数量

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    ++area;
                    // 统计上边相邻陆地
                    if (i - 1 >= 0 && grid[i-1][j] == 1)  ++conn;
                    // 统计左边相邻陆地
                    if (j - 1 >= 0 && grid[i][j-1] == 1)  ++conn;
                }
            }
        }
        return area * 4 - conn * 2;
    }
};