#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int res = n * (n + 1) / 2;
        for (auto x : nums) res -= x;
        return res;
    }
};