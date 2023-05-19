#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {    
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        // f(i) 表示 从 1~i 中选，必选 i
        // g(i) 表示 从 1~i 中选，必不选 i
        vector<int> f(n + 1), g(n + 1);
        for (int i = 1; i <= n; i++) {
            f[i] = g[i - 1] + nums[i - 1]; // nums下标是从0开始的，所以减去1错一位
            g[i] = max(f[i - 1], g[i - 1]);
        }
        return max(f[n], g[n]);
    }
};