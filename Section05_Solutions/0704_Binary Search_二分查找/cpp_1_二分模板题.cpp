#include <iostream>
#include <vector>

using namespace std;

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
// 出现了 nums[r] 所以如果 r=nums.size(); 会导致越界


// ----------------------------------------------

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

// ----------------------------------------------

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = l + r >> 1;
            if (nums[mid] >= target) r = mid;
            else l = mid + 1;
        }
        return nums[r] == target ? r : -1;
    }
};

// ----------------------------------------------

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size(); //为了覆盖到
        while (l < r) {
            int mid = l + r >> 1;
            if (nums[mid] == target) return mid;
            else if (nums[mid] > target) r = mid;
            else l = mid + 1;
        }
        return -1;
    }
};

// 解答错误 nums =[5]，target = 5，输出 -1，预期结果 0

// ----------------------------------------------

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty()) return -1;
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

// ----------------------------------------------

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) // 注意这里是小于等于号
        {
            int mid = l + r >> 1;
            if (nums[mid] == target) return mid;
            else if (nums[mid] > target) r = mid - 1; // 注意这里是r=mid-1
            else l = mid + 1;
        }
        return -1;
    }
};

