#include <iostream>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        int l = 0, r = x; //r不要取2^31-1 不然会错
        while (l < r) {
            int mid = l + 1ll + r >> 1; //l+r可能会溢出，取巧把 lll 插到中间变成 long long
            if (mid <= x / mid) l = mid; //mid*mid会溢出，取巧把mid放到右边
            else r = mid - 1;
        }
        return l;
    }
};