#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        const int n = nums.size();
        const int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum < S) return 0;
        const int offset = sum;
        vector<vector<int>> f(n + 1, vector<int>(sum + offset + 1, 0));
        f[0][offset] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = -offset; j <= offset; j++) {
                if (j - nums[i] >= -offset)
                    f[i + 1][j + offset] += f[i][j - nums[i] + offset];
                if (j + nums[i] <= offset)
                    f[i + 1][j + offset] += f[i][j + nums[i] + offset];
            }
        }
        return f[n - 1][sum + offset];
    }
};