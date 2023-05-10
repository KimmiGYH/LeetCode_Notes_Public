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
        while (l < r) {
            int mid = l + r >> 1;
            if (nums[mid] >= target) r = mid;
            else l = mid + 1;
        }
        return nums[r] == target ? r : -1; // 这里代码写成了一行，跟上面无异
    }
};

// ----------------------------------------------

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l < r)
        {
            int mid = l + r + 1>> 1;
            if (nums[mid] <= target) l = mid; // 另一种写法，check的左半边
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
/*
因为 r 表示的是右边界的下一个位置，所以它应该被初始化为 nums.size()。如果将 r 初始化为 nums.size() - 1，则在搜索时，右边界将不包含最后一个元素，因此可能会导致无法找到目标元素，或者返回错误的位置。

例如，当 target 是最后一个元素时，如果 r 被初始化为 nums.size() - 1，则在搜索时，右边界将不包括最后一个元素，导致搜索失败。

因此，正确的初始化方式应该是 r = nums.size();，这样才能保证在搜索时不访问数组越界并且能正确找到目标元素。
*/

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

