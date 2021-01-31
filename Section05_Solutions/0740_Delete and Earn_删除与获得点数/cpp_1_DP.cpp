#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        const int N = 1e4 + 10;
        vector<int> sums(N, 0);
        int m = 0;
        for (int x : nums) {
            sums[x] += x;
            m = max(m, x);
        }
        // f(i)表示遍历了 1~i 种数字，取当前数字和时的最大值
        // g(i)表示遍历了 1~i 种数字，且不取当前数字和时的最大值；
        vector<int> f(m + 1), g(m + 1);
        for (int i = 1; i <= m; ++i) {
            f[i] = g[i - 1] + sums[i];
            g[i] = max(f[i - 1], g[i - 1]);
        }
        return max(f[m], g[m]);
    }
};