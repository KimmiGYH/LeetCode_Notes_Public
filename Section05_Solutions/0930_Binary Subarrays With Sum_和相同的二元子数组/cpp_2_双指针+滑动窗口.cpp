class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size(), res = 0;
        int l1 = 0, l2 = 0, r = 0;
        int sum1 = 0, sum2 = 0;
        while (r < n) {
            sum1 += nums[r];
            while (l1 <= r && sum1 > goal) {
                sum1 -= nums[l1];
                l1++;
            }
            sum2 += nums[r];
            while (l2 <= r && sum2 >= goal) {
                sum2 -= nums[l2];
                l2++;
            }
            res += l2 - l1;
            r++;
        }
        return res;
    }
};