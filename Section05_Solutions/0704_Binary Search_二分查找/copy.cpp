// Solution 1
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l < r)
        {
            int mid = l + r >> 1;
            if (nums[mid] >= target) r = mid;
            else l = mid + 1;
        }
        if (nums[r] != target) return -1;
        return r;
    }
};
/* Solution 1 和 Solution 2 都是左闭右闭区间 */

// Solution 2
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l < r)
        {
            int mid = l + r + 1>> 1;
            if (nums[mid] <= target) l = mid;
            else r = mid - 1;
        }
        if (nums[r] != target) return -1; 
        return r;
    }
};

// ==============================================

// Solution 3
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size();
        while (l < r) {
            int mid = l + r >> 1;
            if (nums[mid] == target) return mid;
            else if (nums[mid] > target) r = mid;
            else l = mid + 1;
        }
        return -1;
    }
};

/* Solution 3 是左闭右开，Solution 4 左开右闭 */

// Solution 4
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = -1, r = nums.size() - 1;
        while (l < r) {
            int mid = l + r + 1 >> 1;
            if (nums[mid] == target) return mid;
            else if (nums[mid] < target) l = mid;
            else r = mid - 1;
        }
        return -1;
    }
};
