#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int res = INT_MAX;
        for (int i = 0, j = 0, sum = 0; i < nums.size(); i++) {
            sum += nums[i];
            while (sum - nums[j] >= s)  sum -= nums[j++];
            if (sum >= s)  res = min(res, i - j + 1); // 因为是 [j, i]，所以要 + 1
        }
        if (res == INT_MAX)  res = 0;
        return res;
    }
};