#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    int quick_sort(vector<int>& nums, int l, int r, int k) {

        if (l == r) return nums[k];

        int i = l - 1, j = r + 1, x = nums[l + r >> 1];
        while (i < j) {
            // 因为求的是第k大个元素，而不是第k小个元素，所以这里符号要翻转一下
            do i++; while (nums[i] > x);
            do j--; while (nums[j] < x);
            if (i < j) swap(nums[i], nums[j]);
        }
        if (k <= j) return quick_sort(nums, l, j, k);
        else return quick_sort(nums, j+1, r, k);
    }

    int findKthLargest(vector<int>& nums, int k) {
        return quick_sort(nums, 0, nums.size() - 1, k - 1);
    }
};