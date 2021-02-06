#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        int l = 0, r = nums.size();
        while (l < r) {
            int m = l + r >> 1;
            // int n = m % 2 == 0 ? m + 1 : m - 1;
            int n = m ^ 1;
            if (nums[m] == nums[n]) l = m + 1;
            else r = m;
        }
        return nums[l];
    }
};