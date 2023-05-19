#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        typedef long long LL;
        vector<LL> exp;
        bool is_negative = false;
        if (dividend < 0 && divisor > 0 || dividend > 0 && divisor < 0) is_negative = true;
        
        LL a = abs((LL)dividend), b = abs((LL)divisor);
        for (LL i = b; i <= a; i = i + i) exp.push_back(i);
        
        /*处理
        -2147483648 注：INT_MAX = 2^31 - 1 = 2147483647
        -1
        */        
        LL res = 0;
        for (int i = exp.size() - 1; i >= 0; i--)
            if (a >= exp[i]) {
                a -= exp[i];
                res += 1ll << i; // 1 << 31 会溢出
            }
        
        if (is_negative)  res = - res;
        if (res > INT_MAX || res < INT_MIN) res = INT_MAX;

        return res;
    }
};

/*
For instance, a = 37;
exp = {3, 6, 12, 24}, exp.size()=4;
for (i=3; i>=0; i--) {
    if (a >= 24) {          if (a >= 12) {          也即 12 + 24
        a -= 24;                a -= 12;                = 3 * 2^2 + 3 * 2^3
        a = 13;                 a = 1;                  = 3 * (2^2 + 2^3)
        res += 1 << 3 → 8       res += 1 << 2           = 3 * 12
    }                               = 8 + 4 = 12;       = 36
}                               12*3 = 36 < 37
*/