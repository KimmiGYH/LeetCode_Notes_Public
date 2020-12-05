#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int m, n;
    vector<int> dirs{0, 1, 0, -1, 0};

    void solve(vector<vector<char>>& board) {
        m = board.size();
        if (!m)  return;
        n = board[0].size();

        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O')  dfs(board, i, 0);
            if (board[i][n - 1] == 'O')  dfs(board, i, n - 1);
        }

        for (int j = 0; j < n; j++) {
            if (board[0][j] == 'O')  dfs(board, 0, j);
            if (board[m - 1][j] == 'O')  dfs(board, m - 1, j);
        }

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (board[i][j] == '#')  board[i][j] = 'O';
                else board[i][j] = 'X';
    }

    void dfs(vector<vector<char>>& board, int x, int y) {
        board[x][y] = '#';
        for (int k = 0; k < 4; k++) {
            int a = x + dirs[k], b = y + dirs[k + 1];
            if (a >= 0 && a < m && b >= 0 && b < n && board[a][b] == 'O')
                dfs(board, a, b);
        }
    }
};