class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double res = INT_MIN;
        for (int i = 0, j = 0, sum = 0; j < nums.size(); j++) {
            sum += nums[j];
            if (j - i + 1 > k) sum -= nums[i++];
            if (j >= k - 1) res = max(res, (double)sum / k);
        }
        return res;
    }
};
