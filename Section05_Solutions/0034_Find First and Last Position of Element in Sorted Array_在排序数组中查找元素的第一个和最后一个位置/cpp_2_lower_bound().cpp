// 左闭右闭区间，l<=r，写法一，能通过
class Solution {
public:
    int lower_bound(vector<int> &nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int mid = l + r >> 1;
            if (nums[mid] >= target)
                r = mid - 1;
            else
                l = mid + 1;
        }
        return l; // 或者 r+1
    }

    vector<int> searchRange(vector<int> &nums, int target) {
        int start = lower_bound(nums, target);
        if (start == nums.size() || nums[start] != target)
            return {-1, -1};
        // 如果 start 存在，那么 end 必定存在
        // 找 <= target 的数，即找 >= target+1 的数它左边的那个数
        int end = lower_bound(nums, target + 1) - 1;
        return {start, end};
    }
};

// ==============================================================

// 左闭右开区间，l<r，写法二，能通过
class Solution {
public:
    int lower_bound(vector<int> &nums, int target) {
        int l = 0, r = nums.size();
        while (l < r) {
            int mid = l + r >> 1;
            if (nums[mid] >= target) r = mid;
            else l = mid + 1;
        }
        return l;
    }

    vector<int> searchRange(vector<int> &nums, int target) {
        int start = lower_bound(nums, target);
        if (start == nums.size() || nums[start] != target)
            return {-1, -1};
        int end = lower_bound(nums, target + 1) - 1;
        return {start, end};
    }
};

// ==============================================================

// 左闭右开区间，l<r，写法三，报错

class Solution {
public:
    int lower_bound(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = l + r >> 1;
            if (nums[mid] >= target) r = mid;
            else l = mid + 1;
        }
        return r;
    }

    vector<int> searchRange(vector<int> &nums, int target) {
        int start = lower_bound(nums, target);
        if (start == nums.size() || nums[start] != target)
            return {-1, -1};
        int end = lower_bound(nums, target + 1) - 1;
        return {start, end};
    }
};
/* Runtime Error
Line 1034: Char 34: runtime error: applying non-zero offset 18446744073709551612 to null pointer (stl_vector.h)
SUMMARY: UndefinedBehaviorSanitizer: undefined-behavior /usr/bin/../lib/gcc/x86_64-linux-gnu/9/../../../../include/c++/9/bits/stl_vector.h:1043:34 */


// 根据给到的报错数据修改searchRange函数里的代码后，能通过，但是不能吃透为什么错。
class Solution {
public:
    int lower_bound(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = l + r >> 1;
            if (nums[mid] >= target) r = mid;
            else l = mid + 1;
        }
        return r;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int start = lower_bound(nums, target);
        if (nums.empty() || start == nums.size() || nums[start] != target)
            return {-1, -1};
        int end = lower_bound(nums, target + 1);
        if (end == nums.size() || nums[end] != target)
            end--;
        return {start, end};
    }
};