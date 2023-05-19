class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n = matrix[0].size(), res = INT_MIN;
        vector<vector<int>> s(m + 1, vector<int>(n + 1));
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                s[i][j] = s[i-1][j] + s[i][j-1] - s[i-1][j-1] + matrix[i-1][j-1];
            }
        }
        for (int x1 = 1; x1 <= m; ++ x1) {
            for (int y1 = 1; y1 <= n; ++ y1) {
                for (int x2 = x1; x2 <= m; ++ x2) {
                    for (int y2 = y1; y2 <= n; ++ y2) {
                        int cur = s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1];
                        if (cur <= k)
                            res = max(res, cur);
                    }
                }
            }
        }
        return res;
    }
};

// 朴素二维前缀和的这两种写法都TLE了

class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n = matrix[0].size(), res = INT_MIN;
        vector<vector<int>> s(m + 1, vector<int>(n + 1));
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                s[i][j] = s[i-1][j] + s[i][j-1] - s[i-1][j-1] + matrix[i-1][j-1];
            }
        }
        for (int x2 = 1; x2 <= m; ++x2) {
            for (int y2 = 1; y2 <= n; ++y2) {
                for (int x1 = 1; x1 <= x2; ++x1) {
                    for (int y1 = 1; y1 <= y2; ++y1) {
                        int cur = s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1];
                        if (cur <= k)
                            res = max(res, cur);
                    }
                }
            }
        }
        return res;
    }
};