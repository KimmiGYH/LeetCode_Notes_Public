#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if (nums.empty()) return {};
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> f(n);

        int k  = 0; // k 表示最大值
        for (int i = 0; i < n; i++) {
            f[i] = 1;
            for (int j = 0; j < i; j++)
                if (nums[i] % nums[j] == 0)
                    f[i] = max(f[i], f[j] + 1);
            if (f[k] < f[i]) k = i;
        }

        vector<int> res(1, nums[k]);
        while (f[k] > 1) {
            for (int t = 0; t < k; t++)
                if (nums[k] % nums[t] == 0 && f[k] == f[t] + 1) {
                    res.push_back(nums[t]);
                    k = t;
                    break;
                }
        }
        return res;
    }
};