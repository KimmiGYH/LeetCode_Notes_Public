#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:    
    int quick_sort(vector<int>& nums, int l, int r, int k) {
        if (l == r) return nums[l];
        
        int i = l - 1, j = r + 1, x = nums[(l + r)/2];
        while (i < j)
        {
            while (nums[++i] < x);
            while (nums[--j] > x);
            if (i < j) swap(nums[i], nums[j]);
        }
        
        int sl = j - l + 1;
        if (k <= sl) return quick_sort(nums, l, j, k);
        else return quick_sort(nums, j + 1, r, k - sl);
    }
    
    
    int findKthLargest(vector<int>& nums, int k) {
        return quick_sort(nums, 0, nums.size() - 1, nums.size() - k + 1);
    }
};