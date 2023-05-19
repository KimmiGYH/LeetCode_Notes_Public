class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size(), res = 0;
        for (int i = 1; i < n; i++) {
            int j = i, d = nums[i] - nums[i-1];
            while (j < n && nums[j] - nums[j-1] == d) j++;
            int k = j - i;
            res += k * (k - 1) / 2;
            i = j - 1;
        }
        return res;
    }
};