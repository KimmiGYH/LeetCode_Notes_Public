#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if (nums.empty()) return false;
        int R = nums.size() - 1;
        while (R >= 0 && nums[R] == nums[0]) R--;
        if (R < 0) return nums[0] == target;
        
        int l = 0, r = R;
        while (l < r) {
            int mid = l + r + 1 >> 1;
            if (nums[mid] >= nums[0]) l = mid;
            else r = mid - 1 ;
        }
        
        if (target >= nums[0]) l = 0;
        else l = r + 1, r = R;
        
        while (l < r) {
            int mid = l + r >> 1;
            // 二分找大于等于target的第一个数
            if (nums[mid] >= target) r = mid;
            else l = mid + 1;
        }
        // cout << "l: " << l << " " << "r: " << r; // l: 2 r: 1 其中l越界，故最后一行不能写成 nums[l] == target
        return nums[r] == target;
    }
};