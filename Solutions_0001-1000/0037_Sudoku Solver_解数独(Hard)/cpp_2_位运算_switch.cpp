class Solution {
    int row[9] = {0}, col[9] = {0}, box[3][3] = {0};
    bool finished = false;
    std::vector<std::pair<int, int>> spaces;
public:
    void flip(int i, int j, int bit) {
        row[i] ^= bit;
        col[j] ^= bit;
        box[i/3][j/3] ^= bit;
    }
    
    char get_num(int bit) {
        // assert(bit <= 0x100 && (bit & (bit - 1)) == 0);
        switch (bit) {
            case 0x1: return '1';
            case 0x2: return '2';
            case 0x4: return '3';
            case 0x8: return '4';
            case 0x10: return '5';
            case 0x20: return '6';
            case 0x40: return '7';
            case 0x80: return '8';
            case 0x100: return '9';
        }
        return 0;
    }
    
    void dfs(std::vector<std::vector<char>>& board, int pos) {
        if (pos == spaces.size()) {
            finished = true;
            return;
        }
        auto [i, j] = spaces[pos];
        int mask = ~(row[i] | col[j] | box[i/3][j/3]) & 0x1ff;
        while (mask && !finished) {
            int curbit = mask & -mask;
            flip(i, j, curbit);
            board[i][j] = get_num(curbit);
            dfs(board, pos + 1);
            flip(i, j, curbit);
            mask ^= curbit;
        }
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') {
                    spaces.emplace_back(i, j);
                } else {
                    flip(i, j, 1 << (board[i][j] - '1'));
                }
            }
        }
        dfs(board, 0);
    }
};