#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = l + r + 1 >> 1;
            if (nums[mid] >= nums[0]) l = mid; // 找到大于nums[0]的最后一个数的下标
            else r = mid - 1;
        }
        // cout << "l: " << l << " " << "r: " << r << endl; // l: 3 r: 3
        
        if (target >= nums[0]) l = 0; // r 是上面二分之后的 r
        else l = r + 1, r = nums.size() - 1;  // 如果target < nums[0]，就在下半段找
        // cout << "l: " << l << " " << "r: " << r << endl; // l: 4 r: 6
        
        while (l < r) {
            int mid = l + r >> 1;
            if (nums[mid] >= target) r = mid; // 找到第一个数大于等于target的数的下标
            else l = mid + 1;
        }
        // cout << "l: " << l << " " << "r: " << r << endl; // l: 4 r: 4
        
        if (nums[r] == target) return r;
        return -1;
    }
};