#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<char>> g;

    int numIslands(vector<vector<char>>& grid) {
        g = grid;
        int islands = 0;
        for (int i = 0; i < g.size(); i++) {
            for (int j = 0; j < g[i].size(); j++) {
                if (g[i][j] == '1') {
                    g[i][j] = '0';
                    islands++;
                    bfs(i, j);
                }
            }
        }
        return islands;
    }

    void bfs(int x, int y) {
        queue<pair<int, int>> q;
        q.push({x, y});
        int dirs[] = {0, 1, 0, -1, 0};
        while (!q.empty()) {
            pair<int, int> t = q.front();
            q.pop();
            for (int k = 0; k < 4; k++) {
                int a = t.first + dirs[k], b = t.second + dirs[k + 1];
                if (a >= 0 && a < g.size() && b >= 0 && b < g[0].size() && g[a][b] == '1') {
                    g[a][b] = '0';
                    q.push({a, b});
                }
            }
        }
    }
};