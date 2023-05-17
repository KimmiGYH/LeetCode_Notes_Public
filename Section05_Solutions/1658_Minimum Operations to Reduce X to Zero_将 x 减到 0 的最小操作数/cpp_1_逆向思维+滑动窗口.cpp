class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int target = accumulate(nums.begin(), nums.end(), 0) - x;
        if (target < 0) return -1;
        int res = INT_MIN, sum = 0;
        for (int i = 0, j = 0; i < nums.size(); i ++) {
            sum += nums[i];
            while (sum > target) {
                sum -= nums[j];
                j ++;
            }
            if (sum == target)
                res = max(res, i - j + 1);
        }
        if (res < 0) return -1;
        return nums.size() - res;
    }
};