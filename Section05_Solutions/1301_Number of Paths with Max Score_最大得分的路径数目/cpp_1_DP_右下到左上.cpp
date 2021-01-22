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
        vector<vector<int>> f(n + 1, vector<int>(n + 1)); // 得分 最大值
        vector<vector<int>> g(n + 1, vector<int>(n + 1)); // 路径数
        board[n - 1][n - 1] = board[0][0] = '0';
        g[n - 1][n - 1] = 1;
        for (int i = n - 1; i >= 0; --i)
            for (int j = n - 1; j >= 0; --j) {
                if (board[i][j] != 'X') {
                    int m = max({f[i + 1][j], f[i][j + 1], f[i + 1][j + 1]});
                    f[i][j] = (board[i][j] - '0') + m;
                    if (f[i + 1][j] == m)       g[i][j] = (g[i][j] + g[i + 1][j]) % MOD;
                    if (f[i][j + 1] == m)       g[i][j] = (g[i][j] + g[i][j + 1]) % MOD;
                    if (f[i + 1][j + 1] == m)   g[i][j] = (g[i][j] + g[i + 1][j + 1]) % MOD;
                }
            }
        // return {g[0][0] ? f[0][0] : 0, g[0][0]}; // 看有没有路径
        if (!g[0][0]) return {0, 0};
        return {f[0][0], g[0][0]};
    }
};