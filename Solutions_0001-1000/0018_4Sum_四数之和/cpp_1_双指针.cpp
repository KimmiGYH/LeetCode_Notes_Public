class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; ++i) {
            if (i >= 1 && nums[i] == nums[i-1]) continue;
            for (int j = i+1; j < n; ++j) {
                if (j >= i+2 && nums[j] == nums[j-1]) continue;
                for (int k = j+1, u = n-1; k < u; k++) {
                    if (k >= j+2 && nums[k] == nums[k-1]) continue;
                    while (k <= u-2 && nums[k] + nums[u] > target - nums[i] - nums[j]) u--;
                    if (nums[k] + nums[u] == target - nums[i] - nums[j])
                        res.push_back({nums[i], nums[j], nums[k], nums[u]});
                }
            }
        }
        return res;
    }
};