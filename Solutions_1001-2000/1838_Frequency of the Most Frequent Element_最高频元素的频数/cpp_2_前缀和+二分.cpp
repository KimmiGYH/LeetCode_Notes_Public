class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        using LL = long long;
        int n = nums.size(), res = 0;
        vector<LL> s(n + 1);
        sort(nums.begin(), nums.end());
        for (int j = 1; j <= n; j++)
            s[j] = s[j-1] + nums[j-1];
        for (int j = 1; j <= n; j++) {
            int l = 1, r = j;
            while (l < r) {
                int mid = l + r >> 1;
                if ((LL)(j - mid + 1) * nums[j-1] - (s[j] - s[mid-1]) <= k)
                    r = mid;
                else l = mid + 1;
            }
            res = max(res, j - r + 1);
        }
        return res;
    }
};
