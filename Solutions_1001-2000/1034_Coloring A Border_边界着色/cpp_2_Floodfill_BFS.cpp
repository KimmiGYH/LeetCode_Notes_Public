class Solution {
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> st(m, vector<int>(n));
        vector<pair<int, int>> borders;
        queue<pair<int, int>> q;
        q.push({row, col});
        st[row][col] = 1;
        
        while (!q.empty()) {
            auto t = q.front(); q.pop();
            int x = t.first, y = t.second;
            bool is_border = false;
            int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
            for (int i = 0; i < 4; ++i) {
                int a = x + dx[i], b = y + dy[i];
                if (a >= 0 && a < m && b >= 0 && b < n && grid[a][b]==grid[x][y]) {
                    if (!st[a][b]) {
                        st[a][b] = 1;
                        q.push({a, b});
                    }
                } else is_border = true;
            }
            if (is_border)
                borders.push_back({x, y});
        }
        
        for (auto& [x, y] : borders)
            grid[x][y] = color;
        
        return grid;
    }
};
