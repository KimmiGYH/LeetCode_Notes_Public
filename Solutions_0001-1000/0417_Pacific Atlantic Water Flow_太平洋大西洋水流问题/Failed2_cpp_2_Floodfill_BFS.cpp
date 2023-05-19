#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int m, n;
    vector<vector<int>> g;
    vector<vector<int>> visited;
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        g = matrix;
        if (g.empty() || g[0].empty()) return {};
        int m = g.size(), n = g[0].size();
        queue<pair<int, int>> q1, q2;
        vector<vector<int>> visited;
        vector<vector<int>> res;
        // for (int i = 0; i < m; i++)  bfs(i, 0, 1); // 太平洋 - 左
        // for (int j = 0; j < n; j++)  bfs(0, j, 1); // 太平洋 - 上
        // for (int i = 0; i < m; i++)  bfs(i, n - 1, 2); // 大西洋 - 右
        // for (int j = 0; j < n; j++)  bfs(m - 1, j, 2); // 大西洋 - 下
        for (int i = 0; i < m; i++) {
            visited[i][0] |= 1;
            q1.push({i, 0});
            q2.push({i, n - 1});
        }
        for (int j = 0; j < n; j++) {
            visited[0][j] |= 1;
            q1.push({0, j});
        }
        for (int i = 0; i < m; i++) {
            visited[i][n - 1] |= 2;
            q2.push({i, n - 1});
        }
        for (int j = 0; j < n; j++) {
            visited[m - 1][j] |= 2;
            q2.push({m - 1, j});
        }

        bfs(q1, 1);
        bfs(q2, 2);

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (visited[i][j] == 3)
                    res.push_back({i, j});
        return res;
    }
    
    void bfs(queue<pair<int, int>>& q, int status) {
        int dirs[] = {0, 1, 0, -1, 0};
        while (!q.empty()) {
            pair<int, int> t = q.front();
            int tx = t.first, ty = t.second;
            q.pop();
            for (int k = 0; k < 4; k++) {
            int a = tx + dirs[k], b = ty + dirs[k + 1];
            if (a >= 0 && a < m && b >= 0 && b < n && 
                g[a][b] >= g[tx][ty] && !(visited[a][b] & status))
                visited[a][b] |= status;
                q.push({a, b});
            }
        }
    }
};