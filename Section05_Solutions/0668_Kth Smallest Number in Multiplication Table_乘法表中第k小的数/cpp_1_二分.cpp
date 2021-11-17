class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int l = 1, r = m * n;
        while (l < r) {
            int mid = l + r >> 1;
            if (cnt(m, n, mid) >= k) r = mid;
            else l = mid + 1;
        }
        return r;
    }
    
    int cnt(int m, int n, int mid) {
        int res = 0;
        for (int i = 1; i <= m; i ++)
            res += min(n, mid / i);
        return res;
    }
};