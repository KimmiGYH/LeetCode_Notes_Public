// DP优化辅助空间，把迭代的值保存在 2 个变量中

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty())
            return 0;

        int size = nums.size();
        if (size == 1) {
            return nums[0];
        }

        int preMax = nums[0], curMax = max(nums[0], nums[1]);
        for (int i = 2; i < size; i++) {
            int temp = curMax;
            curMax = max(curMax, preMax + nums[i]);
            preMax = temp;
        }
        return curMax;
    }
};