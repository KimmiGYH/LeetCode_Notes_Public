#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool check[9];

        // 判断行
        for (int i = 0; i < 9; i++) {
            memset(check, 0, sizeof check);
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int t = board[i][j] - '1';
                    if (check[t]) return false;
                    check[t] = true;
                }
            }
        }

        // 判断列
        for (int i = 0; i < 9; i++) {
            memset(check, 0, sizeof check);
            for (int j = 0; j < 9; j++) {
                if (board[j][i] != '.') {
                    int t = board[j][i] - '1';
                    if (check[t]) return false;
                    check[t] = true;
                }
            }
        }

        // 判断九宫格
        for (int i = 0; i < 9; i += 3)
            for (int j = 0; j < 9; j += 3) {
                memset(check, 0, sizeof check);
                for (int x = 0; x < 3; x++)
                    for (int y = 0; y < 3; y++) {
                        if (board[i + x][j + y] != '.') {
                            int t = board[i + x][j + y] - '1';
                            if (check[t])  return false;
                            check[t] = true;
                        }
                    }
            }
        return true;
    }
};