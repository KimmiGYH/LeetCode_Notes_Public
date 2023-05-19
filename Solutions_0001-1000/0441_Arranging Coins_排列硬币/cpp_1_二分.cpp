class Solution {
    using LL = long long;
public:
    int arrangeCoins(int n) {
        LL l = 1, r = n;
        while (l < r) {
            LL mid = l + r + 1 >> 1;
            if (mid * (mid + 1) / 2 <= n) l = mid;
            else r = mid - 1;
        }
        return r;
    }
};