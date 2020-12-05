#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int m, n;
    vector<vector<int>> g;
    vector<vector<int>> visited;

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        g = matrix;
        if (g.empty() || g[0].empty())  return {};
        m = g.size(), n = g[0].size();
        visited = vector<vector<int>>(m, vector<int>(n));

        for (int i = 0; i < m; i++)  dfs(i, 0, 1); // 太平洋 - 左
        for (int j = 0; j < n; j++)  dfs(0, j, 1); // 太平洋 - 上
        for (int i = 0; i < m; i++)  dfs(i, n - 1, 2); // 大西洋 - 右
        for (int j = 0; j < n; j++)  dfs(m - 1, j, 2); // 大西洋 - 下

        vector<vector<int>> res;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (visited[i][j] == 3)
                    res.push_back({i, j});
        return res;
    }
    
    void dfs(int x, int y, int t) {
        int dirs[] = {0, 1, 0, -1, 0};
        if (visited[x][y] & t) return; // 如果已被遍历 则return
        visited[x][y] |= t; // 标记, |= 按位或且赋值运算符
        for (int k = 0; k < 4; k++) {
            int a = x + dirs[k], b = y + dirs[k + 1];
            if (a >= 0 && a < m && b >= 0 && b < n && g[a][b] >= g[x][y])
                dfs(a, b, t);
        }
    }
};
