#include <iostream>
using namespace std;

class Solution {
public:
    int getSum(int a, int b) {
        if (!a) return b;
        int sum = a ^ b, carry = (unsigned)(a & b) << 1; // 无符号整数左移不会溢出爆int
        return getSum(carry, sum);
    }
};