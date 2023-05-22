class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        // nums = [-2,-1,0,0,1,2]
        vector<vector<int>> res;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int a = 0; a < n; a++) {
            if (a > 0 && nums[a] == nums[a-1]) continue;
            for (int b = a + 1; b < n; b++) {
                if (b > a + 1 && nums[b] == nums[b-1]) continue;
                for (int c = b + 1, d = n - 1; c < d; c++) {
                    if (c > b + 1 && nums[c] == nums[c-1]) continue;
                    while (c < d - 1 && (long long) nums[a] + nums[b] + nums[c] + nums[d] > target) d--;
                    if ((long long) nums[a] + nums[b] + nums[c] + nums[d] == target)
                        res.push_back({nums[a], nums[b], nums[c], nums[d]});
                }
            }
        }
        return res;
    }
};