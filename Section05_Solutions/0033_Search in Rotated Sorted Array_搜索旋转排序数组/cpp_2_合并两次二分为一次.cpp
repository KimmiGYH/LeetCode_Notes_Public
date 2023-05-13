class Solution {
public:
    bool is_blue(vector<int>& nums, int i, int target) {
        if (nums[i] > nums.back()) //元素和target都左
            return target > nums.back() && nums[i] >= target;
        else // target在左，二分在右     或 二分在右且大于等于target
            return target > nums.back() || nums[i] >= target;
    };

    int search(vector<int>& nums, int target) {
        // [0, n-1]
        // (-1, n) 开区间
        int l = -1, r = nums.size();
        while (l + 1 < r) {
            int mid = l + r >> 1;
            if (is_blue(nums, mid, target)) r = mid;
            else l = mid;
        }
        if (r == nums.size() || nums[r] != target)
            return -1;
        return r;
    }
};

/* 【蓝色的三种情况】：
(1) 数组元素、target 都在左侧，且 nums[i] >= target
(2) 数组元素在右侧，target 在左侧，肯定满足蓝色
(3) 数组元素、target都在右侧，且 nums[i] >= target
*/