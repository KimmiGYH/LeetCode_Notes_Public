#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(n, 0x3f3f3f3f);
        for (int i = 0; i < n; i++) {
            if (!i) f[i] = 0; // 处理边界
            else {
                for (int j = 0; j < i; j++) { 
                    if (j + nums[j] >= i) { // 只要前面的点能跳到i点就更新最小值
                        f[i] = min(f[i], f[j] + 1);
                    }
                }
            }
        }
        return f[n - 1];
    }
};