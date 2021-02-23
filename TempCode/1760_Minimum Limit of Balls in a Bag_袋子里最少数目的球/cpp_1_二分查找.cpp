#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int l = 1, r = *max_element(nums.begin(), nums.end());
        while (l < r) {
            int mid = l + r >> 1;
            if (check(nums, maxOperations, mid))  r = mid;
            else  l = mid + 1;
        }
        return l;
    }

    bool check(const vector<int>& nums, int& maxOperations, int penalty) {
        int ops = 0;
        for (int num : nums)
            // ops += (num + penalty - 1) / penalty - 1;
            ops += (num - 1) / penalty;
        return ops <= maxOperations;
    }
};
