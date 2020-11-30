#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<char>> g;
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

    int numIslands(vector<vector<char>>& grid) {
        g = grid;
        int cnt = 0;
        for (int i = 0; i < g.size(); i++)
            for (int j = 0; j < g[i].size(); j++)
                if (g[i][j] == '1') { // 如果未被标记过
                    dfs(i, j);
                    cnt++;
                }
        return cnt;
    }

    void dfs(int x, int y) {
        // 标记为已遍历，这样再继续循环时，对于同属于这块岛屿的其他陆地我们不会重复计算了
        g[x][y] = '0';
        for (int i = 0; i < 4; i++) {
            int a = x + dx[i], b = y + dy[i];
            if (a >= 0 && a < g.size() && b >= 0 && b < g[a].size() && g[a][b] == '1')
                dfs(a, b);
        }
    }
};