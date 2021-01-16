#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(n);
        int j = 0;
        for (int i = 0; i < n; i++) {
            if (!i) f[i] = 0;
            else {
                while (j + nums[j] < i) j++; // 找到第一个能跳到 i 的点 j
                f[i] = f[j] + 1; // 根据 f[j] 更新 f[i]
            }
        }
        return f[n - 1];
    }
};