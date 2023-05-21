class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        pair<int, int> res(INT_MAX, INT_MAX);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1, k = n - 1; j < k; j++) {
                int s = nums[i] + nums[j] + nums[k];
                while (j < k - 1 && s > target) k--;
                res = min(res, make_pair(abs(s - target), s));
                if (j < k - 1) {
                    s = nums[i] + nums[j] + nums[k - 1];
                    res = min(res, make_pair((target - s), s));
                }
            }
        }
        return res.second;
    }
};