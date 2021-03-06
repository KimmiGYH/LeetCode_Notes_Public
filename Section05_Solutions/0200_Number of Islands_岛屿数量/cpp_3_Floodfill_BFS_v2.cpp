#include <iostream>
#include <vector>
#include <queue>
using namespace std;


class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty())  return 0;
        int m = grid.size(), n = grid[0].size(), res = 0;
        vector<vector<bool>> visited(m, vector<bool>(n));
        // int dx = {-1, 0, 1, 0}, dy = {0, 1, 0, -1};
        // int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
        vector<int> dx{-1, 0, 1, 0}, dy{0, 1, 0, -1};
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '0' || visited[i][j])  continue;
                ++res;
                queue<int> q{{i * n + j}};
                while (!q.empty()) {
                    int t = q.front(); q.pop();
                    for (int k = 0; k < 4; ++k) {
                        int x = t / n + dx[k], y = t % n + dy[k];
                        if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == '0' || visited[x][y])  continue;
                        visited[x][y] = true;
                        q.push(x * n + y);
                    }

                }
            }
        }
        return res;
    }
};