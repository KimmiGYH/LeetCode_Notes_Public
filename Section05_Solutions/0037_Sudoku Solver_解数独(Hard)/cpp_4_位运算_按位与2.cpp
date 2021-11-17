class Solution {
private:
    int row[9], col[9], box[3][3];
    vector<pair<int, int>> spaces;
    
public:
    void solveSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; ++ i)
            for (int j = 0; j < 9; ++ j)
                if (board[i][j] == '.')
                    spaces.emplace_back(i, j);
                else {
                    int t = board[i][j] - '1';
                    getOR(i, j, t);
                }
        dfs(board, 0);
    }
    
    void getOR(int i, int j, int t) {
        row[i] |= 1 << t;
        col[j] |= 1 << t;
        box[i / 3][j / 3] |= 1 << t;
    }
    
    int getBit(int x, int k) {
        return (x >> k) & 1;
    }
    
    bool dfs(vector<vector<char>>& board, int pos) {
        if (pos == spaces.size())  return true;
        
        auto [i, j] = spaces[pos];
        for (int val = 0; val < 9; ++ val) {
            if (getBit(row[i], val) || getBit(col[j], val) || getBit(box[i / 3][j / 3], val)) continue;
            board[i][j] = val + '1';
            int oldRow = row[i], oldCol = col[j], oldBox = box[i / 3][j / 3];
            getOR(i, j, val);
            if (dfs(board, pos + 1)) return true;
            row[i] = oldRow;
            col[j] = oldCol;
            box[i / 3][j / 3] = oldBox;
        }
        return false;
    }
};