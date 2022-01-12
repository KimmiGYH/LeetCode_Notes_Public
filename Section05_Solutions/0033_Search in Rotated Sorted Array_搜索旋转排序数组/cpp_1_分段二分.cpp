class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if (!n) return -1;
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = l + r + 1>> 1;
            if (nums[mid] >= nums[0]) l = mid;
            else r = mid - 1;
        }
        
        if (target >= nums[0]) l = 0;
        else l = r + 1, r = n - 1;
        while (l < r) {
            int mid = l + r >> 1;
            if (nums[mid] >= target) r = mid;
            else l = mid + 1;
        }
        
        return nums[r] == target ? r : -1;
    }
};