#include <iostream>

using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num) {
        int l = 1, r = num;
        while (l < r) {
            int mid = l + 1ll + r >> 1;
            if (mid <= num / mid) l = mid;
            else r = mid - 1;
        }
        return r * r == num;
    }
};