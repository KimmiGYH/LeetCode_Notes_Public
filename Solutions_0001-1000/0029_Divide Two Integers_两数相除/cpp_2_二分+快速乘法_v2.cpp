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
        bool is_negative = false;
        if (dividend < 0 && divisor > 0 || dividend > 0 && divisor < 0)
            is_negative = true;
        LL x = abs((LL)dividend), y = abs((LL)divisor);
        
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