#include <iostream>

using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) { //宽度恰为32位的无符号整数类型
        int res = 0;
        for (int i = 0; i < 32; ++i)
            res += n >> i & 1;
        return res;
    }
};