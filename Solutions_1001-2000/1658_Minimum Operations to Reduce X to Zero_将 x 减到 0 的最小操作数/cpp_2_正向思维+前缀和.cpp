class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int suffix = 0, n = nums.size(), j = n;
        while (j > 0 && suffix + nums[j - 1] <= x) //计算最长后缀
            suffix += nums[--j];
        if (j == 0 && suffix < x) return -1; //全部移除也无法满足
        int res = INT_MAX;
        if (suffix == x)  res = n - j;

        int sum = suffix;
        for (int i = 0; i < n; i ++) {
            sum += nums[i];
            while (j < n && sum > x) {
                sum -= nums[j ++];
            }
            if (sum > x) break;
            if (sum == x)
                res = min(res, i + 1 + n - j);
        }
        if (res == INT_MAX) return -1;
        return res;
    }
};