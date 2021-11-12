#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row[9][9];
        int col[9][9];
        int box[3][3][9];

        memset(row, 0, sizeof row);
        memset(col, 0, sizeof row);
        memset(box, 0, sizeof row);

        for (int i = 0; i < 9; i ++) {
            for (int j = 0; j < 9; j ++) {
                if (board[i][j] != '.') {
                    int t = board[i][j] - '1';
                    row[i][t] ++;
                    col[j][t] ++;
                    box[i/3][j/3][t] ++;
                    if (row[i][t] > 1 || col[j][t] > 1 || box[i/3][j/3][t] > 1)
                        return false;
                }
            }
        }
        return true;
    }
};