class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size(), res = 0;
        vector<vector<int>> s(m + 1, vector<int>(n + 1));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                s[i][j] = s[i-1][j] + s[i][j-1] - s[i-1][j-1] + matrix[i-1][j-1];
            }
        }
        for (int x = 1; x <= m; x++) {
            for (int y = 1; y <= n; y++) {
                for (int p = 1; p <= x; p++) {
                    for (int q = 1; q <= y; q++) {
                        if (s[x][y] - s[p-1][y] - s[x][q-1] + s[p-1][q-1] == target)
                            res++;
                    }
                }
            }
        }
        return res;
    }
};