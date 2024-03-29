class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n - 1;
        while (l < n-1 && nums[l+1] >= nums[l]) l++;
        if (l == r) return 0;
        while (r > 1 && nums[r-1] <= nums[r]) r--;
        for (int i = l+1; i < n; i++)
            while (l >= 0 && nums[l] > nums[i])
                l--;
        for (int i = r-1; i >= 0; i--)
            while (r < n && nums[r] < nums[i])
                r++;
        return r - l - 1; 
    }
};