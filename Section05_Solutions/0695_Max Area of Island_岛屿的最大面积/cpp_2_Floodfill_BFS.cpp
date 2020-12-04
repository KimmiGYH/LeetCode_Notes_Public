#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        vector<vector<int>> ds{{0,-1}, {-1,0}, {0,1}, {1,0}};
        int m = grid.size(), n = grid[0].size(), res = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] != 1)  continue;
                int cnt = 0;
                queue<pair<int,int>> q{{{i, j}}};
                grid[i][j] *= -1;
                while (!q.empty()) {
                    auto t = q.front(); q.pop();
                    res = max(res, ++cnt);
                    for (auto d : ds) {
                        int x = t.first + d[0], y = t.second + d[1];
                        if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] <= 0) continue;
                        grid[x][y] *= -1;
                        q.push({x, y});
                    }
                }
            }
        }
        return res;
    }
};