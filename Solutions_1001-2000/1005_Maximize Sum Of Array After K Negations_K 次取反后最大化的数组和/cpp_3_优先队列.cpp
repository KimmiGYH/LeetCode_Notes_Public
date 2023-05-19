class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        int res = 0, n = nums.size(), minm = INT_MAX;
        priority_queue<int> q;
        for (int& x : nums) {
            if (x < 0) q.push(-x);
            res += x;
            minm = min(minm, abs(x));
        }
        while (!q.empty() && k > 0) {
            res += 2 * q.top();
            q.pop();
            k--;
        }
        return res - (k % 2) * 2 * minm;
    }
};