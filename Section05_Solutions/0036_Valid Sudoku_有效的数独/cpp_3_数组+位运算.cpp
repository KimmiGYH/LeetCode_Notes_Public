#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<int> row(9), col(9), squ(9);
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.')  continue;
                // if (board[i][j] < '1' || board[i][j] > '9')  return false; //可以不写，默认1-9
                int num = board[i][j] - '0';
                
                // 以row[i] & (1 << num)为例，这是判断第i行中，num数字是否出现过。
                // 即row[i]值的二进制表示中，第num位是否是1。
                // 以下col和squ同理。
                
                if ((row[i] & (1 << num)) ||
                    (col[j] & (1 << num)) ||
                    (squ[(i / 3) * 3 + (j / 3)] & (1 << num)))
                    return false;
                
                row[i] |= (1 << num);
                col[j] |= (1 << num);
                squ[(i / 3) * 3 + (j / 3)] |= (1 << num);
            }
        return true;
    }
};