#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int s = 0, minv = 0, maxv = 0;
        for (int& x : nums) {
            s += x;
            minv = min(s, minv);
            maxv = max(s, maxv);
        }
        return maxv - minv;
    }
};