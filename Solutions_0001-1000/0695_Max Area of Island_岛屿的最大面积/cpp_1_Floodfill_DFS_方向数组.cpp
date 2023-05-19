#include <iostream>
#include <vector>
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
                    res = max(res, dfs(i, j));
                }
            }
        }
        return res;
    }

    int dfs(int x, int y) {
        int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
        g[x][y] = -1;
        int cnt = 1;
        for (int k = 0; k != 4; ++k) {
            int a = x + dx[k], b = y + dy[k];
            if (a >= 0 && a < g.size() && b >= 0 && b < g[a].size() && g[a][b] == 1)
                cnt += dfs(a, b);
        }
        return cnt;
    }
};