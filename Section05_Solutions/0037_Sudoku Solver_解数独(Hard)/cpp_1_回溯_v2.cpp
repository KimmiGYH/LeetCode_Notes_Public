#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool row[9][9], col[9][9], box[9][9]; //和v1的区别在于这里box三维数组写成了二维
    
    void solveSudoku(vector<vector<char>>& board) {        
        memset(row, 0, sizeof row);
        memset(col, 0, sizeof col);
        memset(box, 0, sizeof box);
        
        for (int i = 0; i < 9; i ++)
            for (int j = 0; j < 9; j ++)
                if (board[i][j] != '.') {
                    int t = board[i][j] - '1';
                    int idx = (i / 3) * 3 + j / 3;
                    row[i][t] = col[j][t] = box[idx][t] = true;
                }
        dfs(board, 0, 0);
    }
    
    bool dfs(vector<vector<char>>& board, int x, int y) {
        if (y == 9) x ++, y = 0;
        if (x == 9) return true;
        
        if (board[x][y] != '.') return dfs(board, x, y + 1);
        for (int t = 0; t < 9; t ++)
            if (!row[x][t] && !col[y][t] && !box[(x/3)*3 + y/3][t]) {
                board[x][y] = '1' + t;
                row[x][t] = col[y][t] = box[(x/3)*3 + y/3][t] = true;
                if (dfs(board, x, y + 1)) return true;
                board[x][y] = '.';
                row[x][t] = col[y][t] = box[(x/3)*3 + y/3][t] = false;
            }
        return false;
    }
};