#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int m, n;
    vector<vector<int>> g;
    vector<vector<int>> visited;
    vector<vector<int>> res;

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        g = matrix;
        if (g.empty() || g[0].empty())  return res;
        m = g.size(), n = g[0].size();
        visited = vector<vector<int>>(m, vector<int>(n));

        for (int i = 0; i < m; i++)  {
            visited[i][0] |= 1;
            visited[i][n-1] |= 2;
            bfs(i, 0, 1); // Left
            bfs(i, n - 1, 2); // Right
        }
        for (int j = 0; j < n; j++)  {
            visited[0][j] |= 1;
            visited[m-1][j] |= 2;
            bfs(0, j, 1); // Top
            bfs(m - 1, j, 2); // Down
        }

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (visited[i][j] == 3)
                    res.push_back({i, j});
        return res;
    }
    
    void bfs(int x, int y, int status) {
        queue<pair<int, int>> q;
        q.push({x, y});
        int dirs[] = {0, 1, 0, -1, 0};
        while (!q.empty()) {
            pair<int, int> t = q.front();
            int tx = t.first, ty = t.second;
            q.pop();
            for (int k = 0; k < 4; k++) {
            int a = tx + dirs[k], b = ty + dirs[k + 1];
            if (a >= 0 && a < m && b >= 0 && b < n && g[a][b] >= g[tx][ty] && !(visited[a][b] & status))
                visited[a][b] |= status;
                q.push({a, b});
            }
        }
    }
};