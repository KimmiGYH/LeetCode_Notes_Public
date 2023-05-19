class Solution {
    using LL = long long;
public:
    //a 乘数，b 被乘数
    LL quickMulti(LL a, LL b) {
        LL tot = 0;
        while (b > 0) {
            if (b & 1) tot += a;
            b >>= 1;
            a += a;
        }
        return tot;
    }
    
    int divide(int dividend, int divisor) { //x:dividend, y:divisor
        LL res = 0;
        LL x = dividend, y = divisor;
        bool is_negative = (x < 0 && y > 0) || (x > 0 && y < 0);
        if (x < 0) x = -x;
        if (y < 0) y = -y;
        
        LL l = 0, r = x;
        while (l < r) {
            LL mid = l + r + 1 >> 1;
            if (quickMulti(y, mid) <= x) l = mid;
            else r = mid - 1;
        }
        res = is_negative ? -r : r;
        if (res > INT_MAX || res < INT_MIN) res = INT_MAX;
        
        return res;
    }
};