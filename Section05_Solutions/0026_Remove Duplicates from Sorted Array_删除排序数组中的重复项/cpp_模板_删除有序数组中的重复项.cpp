class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        return solve(nums, 1);
    }
    
    int solve(vector<int>& nums, int k) {
        int idx = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (idx < k || nums[idx-k] != nums[i])
                nums[idx++] = nums[i];
        }
        return idx;
    }
};