class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        return solve(nums, 2);
    }
    
    int solve(vector<int>& nums, int k) {
        int idx = 0;
        for (auto& x : nums) {
            if (idx < k || nums[idx-k] != x)
                nums[idx++] = x;
        }
        return idx;
    }
};
