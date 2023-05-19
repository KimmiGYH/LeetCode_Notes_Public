#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        return count(A, R) - count(A, L - 1);
    }

    // 求出最大值在 [-∞, bound] 范围内的子数组的个数
    int count (vector<int>& A, int bound) {
        int res = 0, cur = 0;
        for (int x : A) {
            cur = (x <= bound) ? (++cur) : 0;
            res += cur;
        }
        return res;
    }
};