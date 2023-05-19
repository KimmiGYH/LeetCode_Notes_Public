#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        const int MOD = 1e9 + 7;
        int n = board.size();
        vector<vector<int>> f(n, vector<int>(n, INT_MIN));
        vector<vector<int>> g(n, vector<int>(n));
        
        int dx[3] = {0, -1, -1};
        int dy[3] = {-1, -1, 0};
        
        board[n - 1][n - 1] = '0';
        f[0][0] = 0;
        g[0][0] = 1;
        
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'X')
                    continue;
                for (int k = 0; k < 3; k++) {
                    int x = i + dx[k], y = j + dy[k];
                    if (x < 0 || y < 0 || f[x][y] < 0)
                        continue;
                    if (f[i][j] < f[x][y] + board[i][j] - '0') {
                        f[i][j] = f[x][y] + board[i][j] - '0';
                        g[i][j] = g[x][y];
                    } else if (f[i][j] == f[x][y] + board[i][j] - '0') {
                        g[i][j] =  (g[i][j] + g[x][y]) % MOD;
                    }
                }
            }
        if (f[n - 1][n - 1] < 0)
            return {0, 0};
        return {f[n - 1][n - 1], g[n - 1][n - 1]};
    }
};