class Solution {
public:
    vector<string> path;
    vector<vector<string>> res;
    vector<bool> col, dg, udg;

    void backtracking(int r, int& n) {
        if (r == n) {
            res.push_back(path);
            return;
        }
        // 枚举第 r 行皇后可以放到哪几列位置，本质枚举的是列
        for (int i = 0; i < n; i++) {
            if (!col[i] && !dg[i + r] && !udg[i - r + n]) {
                col[i] = dg[i + r] = udg[i - r + n] = true;
                path[r][i] = 'Q';
                backtracking(r + 1, n);
                col[i] = dg[i + r] = udg[i - r + n] = false;
                path[r][i] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        col = vector<bool>(n);
        dg = udg = vector<bool>(n * 2);
        path = vector<string>(n, string(n, '.'));
        backtracking(0, n);
        return res;
    }
};