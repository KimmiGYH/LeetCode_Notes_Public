#include <iostream>
#include <queue>

using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int res = 0, fresh = 0;
        queue<pair<int, int>> q;
        vector<int> dirs{0, 1, 0, -1, 0};
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) ++fresh;
                else if (grid[i][j] == 2) q.push({i, j});
            }
        while (!q.empty() && fresh > 0) {
            int len = q.size();
            while (len --) {
                auto tx = q.front().first, ty = q.front().second;
                q.pop();
                for (int k = 0; k < 4; ++k) {
                    int x = tx + dirs[k], y = ty + dirs[k + 1];
                    if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] != 1) continue;
                    grid[x][y] = 2;
                    q.push({x, y});
                    --fresh;
                }
            }
            ++res;
        }
        if (fresh > 0) return -1;
        return res;
    }
};