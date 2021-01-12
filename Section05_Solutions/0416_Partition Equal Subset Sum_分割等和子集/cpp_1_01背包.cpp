#include <iostream>
#include <vector>

using namespace std;

// 状态转移方程：F(i, c) =  F(i-1, c) || F(i-1, c - w(i))
// 如果 i-1 个物品可以填满背包，那么使用 i 个物品也可以填满背包；
// 或者已经可以用 i-1 个物品填满 c-w(i)，对于第 i 个物品使用它，整体也填满了容量为 c 的背包。

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size(), sum = 0;
        for (auto x : nums)  sum += x;
        if (sum % 2)  return false;
        sum /= 2;
        vector<int> f(sum + 1);
        f[0] = 1;
        for (auto x : nums)
            for (int j = sum; j >= x; j--)
                f[j] |= f[j - x];
        return f[sum];
    }
};