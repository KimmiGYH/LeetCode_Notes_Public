#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        const int N = 1e4 + 10;
        vector<int> sums(N, 0);
        int take = 0, skip = 0, m = 0;
        for (int x : nums) {
            sums[x] += x;
            m = max(m, x);
        }
        for (int i = 0; i <= m; ++i) {
            int takei = skip + sums[i];
            int skipi = max(skip, take);
            take = takei; skip = skipi;
        }
        return max(skip, take);
    }
};