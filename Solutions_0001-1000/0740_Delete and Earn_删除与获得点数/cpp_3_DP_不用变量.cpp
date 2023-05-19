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
        for (int i = 2; i <= m; ++i)
            sums[i] = max(sums[i - 1], sums[i - 2] + sums[i]);
        return sums[m];
    }
};