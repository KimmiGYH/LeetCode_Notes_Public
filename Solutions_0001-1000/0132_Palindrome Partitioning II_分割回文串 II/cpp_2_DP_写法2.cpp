#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        s = ' ' + s;
        // g(i,j) 表示从 i 到 j 是不是回文串
        vector<vector<bool>> g(n + 1, vector<bool>(n + 1));
        // f[i] 表示把前 i 个字符划分成回文串，最少划分成几部分
        vector<int> f(n + 1, 1e8);
        
        for (int j = 1; j <= n; j++)
            for (int i = 1; i <= n; i++)
                if (i == j) g[i][j] = true;
                else if (s[i] == s[j]) {
                    if (i + 1 > j - 1 || g[i + 1][j - 1])
                        g[i][j] =  true;
                }
        f[0] = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= i; j++)
                if (g[j][i]) // 注意这里应该 g[j][i] 而不是 g[i][j]
                    f[i] = min(f[i], f[j - 1] + 1);
        
        return f[n] - 1; // 如果分成五部分只需要砍四刀
    }
};