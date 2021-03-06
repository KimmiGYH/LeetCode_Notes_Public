#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int m, n;
    vector<vector<int>> g;
    vector<vector<int>> res;

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        g = matrix;
        if (g.empty() || g[0].empty())  return res;
        m = g.size(), n = g[0].size();
        queue<pair<int, int>> qPacific;
        queue<pair<int, int>> qAtlantic;
        vector<vector<bool>> visitedPacific(m, vector<bool>(n));
        vector<vector<bool>> visitedAlantic(m, vector<bool>(n));

        for (int i = 0; i < m; i++)  {
            qPacific.push({i, 0}); // left
            qAtlantic.push({i, n - 1}); // right
        }
        for (int j = 0; j < n; j++)  {
            qPacific.push({0, j}); // top
            qAtlantic.push({m - 1, j}); // down
        }
        bfs(qPacific, visitedPacific);
        bfs(qAtlantic, visitedAlantic);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (visitedPacific[i][j] && visitedAlantic[i][j])
                    res.push_back({i, j});
            }
        }
        return res;
    }

    void bfs(queue<pair<int, int>>& q, vector<vector<bool>> &visited) {
        int dirs[] = {0, 1, 0, -1, 0};
        while (!q.empty()) {
            pair<int, int> t = q.front(); q.pop();
            int tx = t.first, ty = t.second;
            visited[tx][ty] = true;
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