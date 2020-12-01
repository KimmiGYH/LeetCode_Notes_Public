#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> g;

    int closedIsland(vector<vector<int>>& grid) { 
        g = grid;
        int m = g.size();
        int n = g[0].size();
        int res = 0;

        // Eliminate all lands on the perimeter
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                if (g[i][j] == 0 && (i == 0 || j == 0 || i == m -1 || j == n - 1))
                    dfs(i, j);
            }

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                if (g[i][j] == 0) {
                    res++;
                    dfs(i, j);
                }
        }
        return res;
    }


    bool isOut(int x, int y) {
        return x < 0 || x >= g.size() || y < 0 || y >= g[x].size();
    }


    void dfs(int x, int y) {
        int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

        // -1 = visited; 1 = water; 0 = land
        g[x][y] = -1;
        for (int k = 0; k < 4; k++) {
            int a = x + dx[k], b = y + dy[k];
            if (!isOut(a, b) && g[a][b] == 0)
                dfs(a, b);
        }
    }
};