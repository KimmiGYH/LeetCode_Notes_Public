#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n, 1);
        int res = 1; // 考虑到 [0] 的 output 为 1 的情况
        
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};