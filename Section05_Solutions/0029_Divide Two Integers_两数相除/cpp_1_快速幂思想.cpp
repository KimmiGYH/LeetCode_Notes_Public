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