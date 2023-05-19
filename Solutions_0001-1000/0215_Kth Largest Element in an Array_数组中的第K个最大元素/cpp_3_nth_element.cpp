#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int p = nums.size() - k;
        nth_element(nums.begin(), nums.begin() + p, nums.end());
        return nums[p];
    }
};