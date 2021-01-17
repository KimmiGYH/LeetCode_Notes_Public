#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> getRow(int n) {
        vector<int> res;
        for (int m = 0; m < n; ++m)
            res.push_back(combination(n, m));
        return res;
    }

    int combination(int& n, int& m) {
        int r = min(m, n - m); // 较小的那个
        int t = n - r; // 较大的那个
        int c = 1;
        for (int j = 0; j <= n; ++j) {
            c *= (t + j);
            c /= j;
        }
        return c;
    }
};