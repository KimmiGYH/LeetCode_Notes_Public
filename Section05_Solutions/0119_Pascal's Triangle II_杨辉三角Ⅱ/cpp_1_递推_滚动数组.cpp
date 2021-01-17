#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getRow(int n) {
        // 把第一维改成 2，其他所有的第一维改成 & 1
        vector<vector<int>> f(2, vector<int>(n + 1));
        for (int i = 0; i <= n; ++i) {
            f[i & 1][0] = f[i & 1][i] = 1;
            for (int j = 1; j < i; j++)
                f[i & 1][j] = f[i - 1 & 1][j - 1] + f[i - 1 & 1][j];
        }
        return f[n & 1];
    }
};