class Solution {
    const int MOD = 1e9 + 7;
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        int res = 0, n = nums1.size(), sum = 0, diff = 0, mx = 0;
        vector<int> rec(nums1);
        sort(rec.begin(), rec.end());
        for (int i = 0; i < n; i++) {
            int x = nums1[i], y = nums2[i];
            if (x == y) continue;
            diff = abs(x - y);
            sum = (sum + diff) % MOD;
            int j = lower_bound(rec.begin(), rec.end(), y) - rec.begin();
            if (j < n) mx = max(mx, diff - (rec[j] - y));
            if (j > 0) mx = max(mx, diff - (y - rec[j - 1]));
        }
        return (sum - mx + MOD) % MOD;
    }
};