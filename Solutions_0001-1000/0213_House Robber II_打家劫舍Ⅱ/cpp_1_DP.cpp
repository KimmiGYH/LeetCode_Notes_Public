#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        // f(i) 必  选 i 终点  且不选 1 起点
        // g(i) 必不选 i 终点  且不选 1 起点
        // 1) 不选起点，终点可选可不选：max(f(n), g(n))
        // 2)   选起点，终点肯定不能选:          g'(n)
        int n = nums.size();
        if (!n) return 0;
        if (n == 1) return nums[0];
        vector<int> f(n + 1), g(n + 1);
        // 不选 1
        for (int i = 2; i <= n; i++) {
            f[i] = g[i - 1] + nums[i - 1]; // nums从0开始有错位
            g[i] = max(f[i - 1], g[i - 1]);
        }
        int res = max(f[n], g[n]);
        
        // 必选 1
        f[1] = nums[0];
        g[1] = INT_MIN; // g必不选1，又必选1，所以 g[1]不合法，状态更新为负无穷
        for (int i = 2; i <= n; i++) {
            f[i] = g[i - 1] + nums[i - 1]; // nums从0开始有错位
            g[i] = max(f[i - 1], g[i - 1]);
        }
        return max(res, g[n]);
    }
};