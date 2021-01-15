#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int maxWin = 0, sum = 0, curSum = 0, l = 0, r = 0;
        int n = nums.size();
        sum = accumulate(nums.begin(), nums.end(), 0);
        int target = sum - x;
        if (target == 0) return n; // 能全删掉的情况
        while (r < n) {
            curSum += nums[r++];
            while (curSum > target && l < r)
                curSum -= nums[l++];
            if (curSum == target)
                maxWin = max(maxWin, r - l);
        }
        if (maxWin == 0) return -1;
        return n - maxWin;
    }
};

/*
nums: [8828,9581,49,9818,9974,9869,9991,10000,10000,10000,9999,9993,9904,8819,1231,6309]
x: 134365
Expected: 16

sum(nums) = 134365
len(nums) = 16
这是能全删掉的情况，判断 target == 0
*/