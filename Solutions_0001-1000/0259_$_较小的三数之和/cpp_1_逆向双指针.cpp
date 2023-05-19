class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        int res = 0, n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            for (int j = i + 1, k = n - 1; j < k; ) {
                if (nums[i] + nums[j] + nums[k] >= target) k--;
                else {
                    res += k - j;
                    j++;
                }
            }
        }
        return res;
    }
};