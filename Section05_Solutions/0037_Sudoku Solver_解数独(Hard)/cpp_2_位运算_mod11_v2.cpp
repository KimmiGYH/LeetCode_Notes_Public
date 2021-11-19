class Solution {
    int row[9] = {0}, col[9] = {0}, box[3][3] = {0};
    bool finished = false;
    std::vector<std::pair<int, int>> spaces;
    static char num_of[11];
public:
    void flip(int i, int j, int bit) {
        row[i] ^= bit;
        col[j] ^= bit;
        box[i/3][j/3] ^= bit;
    }
    
    inline static char get_num(int bit) {
        // assert(bit <= 0x100 && (bit & (bit - 1)) == 0);
        return num_of[bit % 11];
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

char Solution::num_of[] = {0, '1', '2', '9', '3', '5', 0, '8', '4', '7', '6'};
