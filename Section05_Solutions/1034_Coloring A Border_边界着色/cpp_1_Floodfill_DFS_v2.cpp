class Solution {
public:
    vector<vector<int>> g;
    vector<vector<int>> st;
    vector<pair<int,int>> borders;
    int m, n;
    
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        g = grid;
        m = g.size(), n = g[0].size();
        st = vector<vector<int>>(m, vector<int>(n));
        st[row][col] = 1;        
        dfs(row, col);
        for (auto& [x,y] : borders)
            grid[x][y] = color;
        return grid;
    }
    
    void dfs(int x, int y) {
        bool is_border = false;
        int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
        for (int i = 0; i < 4; ++i) {
            int a = x + dx[i], b = y + dy[i];
            if (a >= 0 && a < m && b >= 0 && b < n && g[a][b]==g[x][y]) {
                if (!st[a][b]) {
                    st[a][b] = 1;
                    dfs(a, b);
                }
            } else is_border = true;
        }
        if (is_border)
            borders.push_back({x, y});
    }
};
