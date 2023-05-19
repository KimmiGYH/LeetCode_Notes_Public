class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size(), tot = 0, cnt = 0;
        for (int& x : nums)
            tot += x;
        for (int i = 0; i < tot; i++)
            cnt += nums[i];
        int res = tot - cnt;
        for (int i = tot; i < n + tot; i++) {
            cnt += nums[i % n] - nums[i - tot];
            res = min(res, tot - cnt);
        }
        return res;
    }
};
