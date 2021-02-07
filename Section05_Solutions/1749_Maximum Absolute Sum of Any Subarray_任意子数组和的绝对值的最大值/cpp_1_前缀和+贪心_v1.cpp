#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> s(n + 1);
        for (int i = 1; i <= n; ++i)  s[i] = s[i - 1] + nums[i - 1];
        int res = 0, minv = 0, maxv = 0;
        for (int i = 1; i <= n; ++i) {
            res = max(res, abs(s[i] - minv));
            res = max(res, abs(s[i] - maxv));
            minv = min(minv, s[i]);
            maxv = max(maxv, s[i]);
        }
        return res;
    }
};