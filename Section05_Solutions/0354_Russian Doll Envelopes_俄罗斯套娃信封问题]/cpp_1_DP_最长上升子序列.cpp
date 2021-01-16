#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& e) {
        int n = e.size();
        sort(e.begin(), e.end());
        vector<int> f(n);

        int res = 0;
        for (int i = 0; i < n; ++i) {
            f[i] = 1;
            for (int j = 0; j < i; ++j)
                if (e[j][0] < e[i][0] && e[j][1] < e[i][1])
                    f[i] = max(f[i], f[j] + 1);
            res = max(res, f[i]);
        }
        return res;
    }
};