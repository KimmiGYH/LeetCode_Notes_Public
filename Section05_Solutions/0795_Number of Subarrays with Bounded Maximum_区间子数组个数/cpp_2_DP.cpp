#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        int res = 0, dp = 0;
        int pre = -1;
        for (int i = 0; i < A.size(); i++) {
            if (A[i] < L && i > 0)
                res += dp;
            if (L <= A[i] && A[i] <= R) {
                dp = i - pre;
                res += dp;
            }
            if (A[i] > R) {
                dp = 0;
                pre = i;
            }
        }
        return res;
    }
};