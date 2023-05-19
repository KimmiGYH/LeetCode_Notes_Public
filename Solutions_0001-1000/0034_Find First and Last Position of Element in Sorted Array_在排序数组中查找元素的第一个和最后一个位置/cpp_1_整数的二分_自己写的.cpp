class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) return {-1, -1};
        
        vector<int> res;
        int idx_left = 0, idx_right = 0;
        
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = l + r >> 1;
            if (nums[mid] >= target) r = mid;
            else l = mid + 1;
        }
        idx_left = nums[r] == target ? r : -1;
        res.push_back(idx_left);
        
        l = r, r = nums.size() - 1; //这里l=r
        while (l < r) {
            int mid = l + r + 1 >> 1;
            if (nums[mid] <= target) l = mid;
            else r = mid - 1;
        }
        idx_right = nums[r] == target ? r : -1;
        res.push_back(idx_right);
        
        return res;
    }
};