class Solution {
    using LL = long long;
public:
    bool isPerfectSquare(int num) {
        int l = 1, r = num;
        while (l < r) {
            int mid = l + (LL)1 + r >> 1;
            if (mid <= num / mid) l = mid;
            else r = mid - 1;
        }
        return r * r == num;
    }
};