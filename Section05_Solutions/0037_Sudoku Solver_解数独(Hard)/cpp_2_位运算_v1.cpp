class Solution {
private:
    int row[9], col[9], box[3][3];
    bool finished;
    vector<pair<int, int>> spaces;
    
public:
    void solveSudoku(vector<vector<char>>& board) {
        memset(row, 0, sizeof row);
        memset(col, 0, sizeof col);
        memset(box, 0, sizeof box);
        finished = false;
        
        for (int i = 0; i < 9; ++ i)
            for (int j = 0; j < 9; ++ j)
                if (board[i][j] == '.')
                    spaces.emplace_back(i, j);
                else {
                    int t = board[i][j] - '1';
                    flip(i, j, t);
                }
        
        dfs(board, 0);
    }
    
    void flip(int& i, int& j, int& t) {
        row[i] ^= (1 << t);
        col[j] ^= (1 << t);
        box[i / 3][j / 3] ^= (1 << t);
    }
    
    void dfs(vector<vector<char>>& board, int pos) {
        if (pos == spaces.size()) {
            finished = true;
            return;
        }
        
        auto [i, j] = spaces[pos];
        // 将3个异或结果 按位或，得到的结果取反；
        // 由于按位取反后这个数的高位也全部变成了1，且row,col,box都是9位数组，所以将这个数和(111111111)2 即 0x1FF 按位与，将所有无关的位设置为0
        int mask = ~(row[i] | col[j] | box[i / 3][j / 3]) & 0x1ff;
        for (; mask && !finished; mask &= (mask - 1)) { //将 mask 和 mask-1 按位与，从而枚举下一个1
            int digitMask = mask & (-mask); //得到 mask 二进制表示中最低位的 1
            int digit = __builtin_ctz(digitMask); //查看最低位1 后面有多少个0
            flip(i, j, digit);
            board[i][j] = digit + '1';
            dfs(board, pos + 1);
            flip(i, j, digit);
        }
    }
};