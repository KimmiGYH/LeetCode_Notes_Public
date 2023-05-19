class Solution {
public:
    vector<string> g;
   
    int cnt(char c) {
        int res = 0;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (g[i][j] == c)
                    res ++;
        return res;
    }
    
    bool check(char c) {
        for (int i = 0; i < 3; i++) {
            if (g[i][0] == c && g[i][1] == c && g[i][2] == c) return true;
            if (g[0][i] == c && g[1][i] == c && g[2][i] == c) return true;
        }
        if (g[0][0] == c && g[1][1] == c && g[2][2] == c) return true;
        if (g[0][2] == c && g[1][1] == c && g[2][0] == c) return true;
        return false;
    }
    
    bool validTicTacToe(vector<string>& board) {
        g = board;
        int sx = cnt('X'), so = cnt('O');
        bool cx = check('X'), co = check('O');
        
        if (cx && co) return false;
        if (cx && sx != so + 1) return false;
        if (co && sx != so) return false;
        if (sx != so && sx != so + 1) return false;
        return true;
    }
};
