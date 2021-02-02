#include <iostream>

using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        // 负数的定义就是补码，所以 x & -x = x & (~x + 1)
        int res = 0;
        while (n)  n -= n & -n, res++;
        return res;
    }
};