#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getRow(int n) {
        vector<int> res;
        long long val = 1;
        res.push_back(val);
        for (int m = n; m >= 1; --m) {
            val *= m;
            val /= n - m + 1;
            res.push_back(val);
        }
        return res;
    }
};