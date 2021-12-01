class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size(), res = 0, cnt = 0;
        for (int i = 2; i < n; ++i) {
            if (nums[i] - nums[i-1] == nums[i-1] - nums[i-2]) {
                cnt += 1;
                res += cnt;
            }
            else cnt = 0;
        }
        return res;
    }
};