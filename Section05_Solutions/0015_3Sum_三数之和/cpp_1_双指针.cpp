class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i <= n-1; i++) {
            if (i >= 1 && nums[i] == nums[i-1]) continue;
            for (int j = i+1, k = n-1; j < k; j++) {
                if (j >= i+2 && nums[j] == nums[j-1]) continue;
                while (j <= k-2 && nums[i] + nums[j] + nums[k] > 0) k--;
                if (nums[i] + nums[j] + nums[k] == 0)
                    res.push_back({nums[i], nums[j], nums[k]});
            }
        }
        return res;
    }
};