#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // 从前往后找到第一个大于等于target的位置，性质是nums[i] >= target
        int l = 0, r = nums.size();
        
        while (l < r) {
            int mid = l + r >> 1;
            if (nums[mid] >= target) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};