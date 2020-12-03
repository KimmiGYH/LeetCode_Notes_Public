#include <iostream>
#include <vector>

using namespace std;



class Solution {
public:
    #define x first
    #define y second
    typedef pair<int, int> PII;
    const int N = 300, M = N * N;
    PII q;
    vector<vector<char>> g;
    vector<vector<bool>> visited;
    int m = g.size(), n = g[0].size();    

    void bfs(int sx, int sy) {
        int hh = 0, tt = 0;
        q[0] = {sx, sy};
        visited[sx][sy] = true;

        while (hh <= tt) {
            PII t = q[hh ++];
            for (int i = t.x - 1; i <= t.x + 1; i++)
                for (int j = t.y - 1; j <= t.y + 1; j++)
                {
                    if (i == t.x && j == t.y)  continue; // 挖掉中间的
                    if (i < 0 || i >= n || j < 0 || j >= m) continue;
                    if (g[i][j] == '0' || visited[i][j]) continue;

                    q[++tt] = {i, j};
                    visited[i][j] = true;
                }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        g = grid;
        visited = vector<vector<bool>> (m, vector<bool> (n, false));
        int cnt = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (g[i][j] == '1' && !visited[i][j]) {
                    bfs(i, j);
                    cnt++;
                }
    }
};