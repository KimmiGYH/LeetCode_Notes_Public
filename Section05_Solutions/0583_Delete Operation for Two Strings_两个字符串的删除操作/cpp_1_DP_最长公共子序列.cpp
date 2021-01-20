#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minDistance(string A, string B) {
        int m = A.size(), n = B.size();
        vector<vector<int>> f(m + 1, vector<int>(n + 1));
        // 边界 f[0][i] 相当于将 s2 的前 i 个字符变成 s1 的前 0 个字符，就是将所有字符都删掉
        for (int i = 0; i <= m; i++) f[i][0] = i;
        for (int j = 0; j <= n; j++) f[0][j] = j;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                f[i][j] = min(f[i - 1][j], f[i][j - 1]) + 1; // 中间两种情况
                if (A[i - 1] ==  B[j - 1]) // 最后一种情况：f(i-1, j-1)
                    f[i][j] = min(f[i][j], f[i - 1][j - 1]);
            }
        }
        return f[m][n];
    }
};