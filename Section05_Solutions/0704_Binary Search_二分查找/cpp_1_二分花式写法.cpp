// 双闭区间，l<=r 写法一：
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int mid = l + r >> 1;
            if (nums[mid] == target) return mid;
            else if (nums[mid] > target) r = mid - 1;
            else l = mid + 1;
        }
        return -1;
    }
};

// 或者
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int mid = l + r >> 1;
            if (nums[mid] >= target) r = mid - 1;
            else l = mid + 1;
        }
        if (l == nums.size() || nums[l] != target) return -1;
        return l; // 或者 r+1
    }
};


// 双闭区间，l<r 写法二：★
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = l + r >> 1;
            if (nums[mid] >= target) r = mid;
            else l = mid + 1;
        }
        if (nums[l] != target) return -1;
        return l;
    }
};

// 左闭右开区间，l<r 写法三：
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

// 或者
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size();
        while (l < r) {
            int mid = l + r >> 1;
            if (nums[mid] >= target) r = mid;
            else l = mid + 1;
        }
        if (l == nums.size() || nums[l] != target) return -1;
        return l;
    }
};


// 左开右闭区间，l<r 写法四：
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

// 或者
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = -1, r = nums.size() - 1;
        while (l < r) {
            int mid = l + r + 1 >> 1;
            if (nums[mid] <= target) l = mid;
            else r = mid - 1;
        }
        if (r == -1 || nums[r] != target) return -1;
        return r;
    }
};

// 双开区间，l<r 写法五：
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = -1, r = nums.size();
        while (l + 1 < r) {
            int mid = l + r >> 1;
            if (nums[mid] == target) return mid;
            else if (nums[mid] > target) r = mid;
            else l = mid;
        }
        return -1;
    }
};

// 或者
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = -1, r = nums.size();
        while (l + 1 < r) {
            int mid = l + r >> 1;
            if (nums[mid] >= target) r = mid;
            else l = mid;
        }
        if (l == nums.size() - 1 || r == -1 
            || nums[r] != target) return -1;
        return r; // 或者 l+1
    }
};
