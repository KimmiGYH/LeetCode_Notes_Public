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
            int l = 0, r = n; //注意边界问题
            while (l < r) {
                int mid = l + r >> 1;
                if (rec[mid] >= y) r = mid;
                else l = mid + 1;
            }
            if (r < n) mx = max(mx, diff - (rec[r] - y));
            if (r > 0) mx = max(mx, diff - (y - rec[r - 1]));
        }
        return (sum - mx + MOD) % MOD;
    }
};
