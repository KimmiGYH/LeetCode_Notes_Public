#include <iostream>
#include <vector>

using namespace std;

// 写法一：这个不用push_back一个数，也最好理解一些
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0, r = nums.size() / 2;
        while (l < r) {
            int mid = l + r >> 1;
            if (nums[mid*2] == nums[mid*2 + 1]) l = mid + 1;
            else r = mid;
        }
        return nums[l * 2];
    }
};


// 写法二
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0, r = nums.size() / 2; // 不用push_back一个数
        while (l < r) {
            int mid = l + r >> 1;
            if (nums[mid*2] != nums[mid*2 + 1]) r = mid;
            else l = mid + 1;
        }
        return nums[l * 2];
    }
};


// 写法三
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        nums.push_back(nums.back() + 1); // 需要push_back一个数
        int l = 0, r = nums.size() / 2 - 1; // r右边界也需要注意
        while (l < r) {
            int mid = l + r >> 1;
            if (nums[mid*2] != nums[mid*2 + 1]) r = mid;
            else l = mid + 1;
        }
        return nums[l * 2];
    }
};
