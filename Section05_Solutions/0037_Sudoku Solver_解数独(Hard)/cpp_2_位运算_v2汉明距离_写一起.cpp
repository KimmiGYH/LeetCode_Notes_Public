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
        row[i] ^= 1 << t;
        col[j] ^= 1 << t;
        box[i / 3][j / 3] ^= 1 << t;
    }
    
    void dfs(vector<vector<char>>& board, int pos) {
        if (pos == spaces.size()) {
            finished = true;
            return;
        }
        
        auto [i, j] = spaces[pos];
        int mask = ~(row[i] | col[j] | box[i / 3][j / 3]) & 0x1ff;
        for (; mask && !finished; mask ^= mask & -mask) {
            int digitMask = mask & -mask;
            int cnt = 0; //最低位1后面有多少个0
            while (digitMask) {
                if (digitMask ^ 1)  ++cnt;
                digitMask >>= 1;
            }
            flip(i, j, cnt);
            board[i][j] = cnt + '1';
            dfs(board, pos + 1);
            flip(i, j, cnt);
        }
    }
};