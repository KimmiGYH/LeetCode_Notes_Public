#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1; //这里有点阴差阳错搞了个左开右闭区间而不自知
        if (nums[r] >= nums[l])
            return nums[0]; //数组完全单调的特殊情况，数组升序
        while (l < r) {
            int mid = l + r >> 1;
            if (nums[mid] < nums[0]) r = mid;
            else l = mid + 1;
        }
        return nums[r];
    }
};