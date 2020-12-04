#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> g;

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        g = grid;
        int res = 0;
        for (int i = 0; i < g.size(); i++) {
            for (int j = 0; j < g[i].size(); j++) {
                if (g[i][j] == 1) {
                    res = max(res, bfs(i, j));
                }
            }
        }
        return res;
    }

    int bfs(int x, int y) {
        int dirs[] = {0, 1, 0, -1, 0};
        g[x][y] = 0;
        queue<pair<int, int>> q;
        q.push({x, y});
        int cnt = 1;
        while (!q.empty()) {
            pair<int, int> t = q.front();
            q.pop();
            for (int k = 0; k < 4; k++) {
                int a = t.first + dirs[k], b = t.second + dirs[k + 1];
                if (a >= 0 && a < g.size() && b >= 0 && b < g[0].size() && g[a][b] == 1) {
                    g[a][b] = 0;
                    q.push({a, b});
                    cnt++;
                }
            }
        }
        return cnt;
    }
};