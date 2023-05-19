#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int m, n;
    vector<vector<int>> g;

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<vector<int>> res;
        g = matrix;
        if (g.empty() || g[0].empty())  return res;
        m = g.size(), n = g[0].size();
        vector<vector<bool>> visitedPacific(m, vector<bool>(n, false));
        vector<vector<bool>> visitedAlantic(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++)  {
            visitedPacific[i][0] = true;
            visitedAlantic[i][n-1] = true;
            bfs(i, 0, visitedPacific); // Left
            bfs(i, n - 1, visitedAlantic); // Right
        }
        for (int j = 0; j < n; j++)  {
            visitedPacific[0][j] = true;
            visitedAlantic[m-1][j] = true;
            bfs(0, j, visitedPacific); // Top
            bfs(m - 1, j, visitedAlantic); // Bottom
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (visitedPacific[i][j] && visitedAlantic[i][j])
                    res.push_back({i, j});
            }
        }
        return res;
    }

    void bfs(int x, int y, vector<vector<bool>> &visited) {
        int dirs[] = {0, 1, 0, -1, 0};
        queue<pair<int, int>> q;
        q.push({x, y});
        while (!q.empty()) {
            pair<int, int> t = q.front(); q.pop();
            int tx = t.first, ty = t.second;
            for (int k = 0; k < 4; k++) {
                int a = tx + dirs[k], b = ty + dirs[k + 1];
                if (a >= 0 && a < m && b >= 0 && b < n && (g[a][b] >= g[tx][ty]) && !visited[a][b]) {
                    visited[a][b] = true;
                    q.push({a, b});
                }
            }
        }
    }
};