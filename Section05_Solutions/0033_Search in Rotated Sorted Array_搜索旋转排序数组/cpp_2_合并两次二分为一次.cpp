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

/* 【如果二分的位置在 target 右侧，则染成蓝色，三种情况】：主要看二分的位置是否在target右侧（蓝色）
(1) 数组元素、target 都在左侧，且 nums[i] >= target
(2) 数组元素在右侧，target 在左侧，肯定满足蓝色
(3) 数组元素、target都在右侧，且 nums[i] >= target
*/

// 
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = -1, r = nums.size();
        while (l + 1 < r) {
            int mid = l + r >> 1;
            if (nums[mid] > nums.back()) {
                if (target > nums.back() && nums[mid] >= target) r = mid;
                else l = mid;
            } else {
                if (target > nums.back() || nums[mid] >= target) r = mid;
                else l = mid;
            }
        }
        if (r == nums.size() || nums[r] != target) return -1;
        return r;
    }
};

// 将左开右开区间 改写成 左闭右开区间
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size();
        while (l < r) {
            int mid = l + r >> 1;
            if (nums[mid] >= nums.front()) {
                if (target >= nums.front() && nums[mid] >= target) r = mid;
                else l = mid + 1;
            } else {
                if (target >= nums.front() || nums[mid] >= target) r = mid;
                else l = mid + 1;
            }
        }
        if (r == nums.size() || nums[r] != target) return -1;
        return r;
    }
};

// 改成 左闭右闭区间

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = l + r >> 1;
            if (nums[mid] == target) return mid;
            else if (nums[mid] >= nums.front()) {
                if (target >= nums.front() && nums[mid] > target) r = mid;
                else l = mid + 1;
            } else {
                if (target >= nums.front() || nums[mid] > target) r = mid;
                else l = mid + 1;
            }
        }
        if (nums[r] != target) return -1;
        return r;
    }
};