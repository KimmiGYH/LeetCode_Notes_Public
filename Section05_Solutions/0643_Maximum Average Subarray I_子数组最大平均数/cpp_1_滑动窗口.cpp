#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double res = -1e5;
        for (int i = 0, j = 0, s = 0; i < nums.size(); ++i)
        {
            s += nums[i];
            if (i - j + 1 > k) s -= nums[j++];
            if (i >= k - 1) res = max(res, s / double(k));
        }
        return res;
    }
};