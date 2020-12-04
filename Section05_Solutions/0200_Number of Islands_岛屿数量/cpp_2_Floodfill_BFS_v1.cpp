#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int islands = 0;
        int dirs[] = {0, 1, 0, -1, 0};
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    islands++;
                    grid[i][j] = '0';
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    while (!q.empty()) {
                        pair<int, int> t = q.front();
                        q.pop();
                        for (int k = 0; i < 4; k++) {
                            int a = t.first + dirs[k], b = t.second + dirs[k + 1];
                            if (a >= 0 && a < m && b >= 0 && b < n && grid[a][b] == '1') {
                                grid[a][b] = '0';
                                q.push({a, b});
                            }
                        }
                    }
                }
            }
        }
        return islands;
    }
};