#include <vector>

using namespace std;

class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        int a = 1, b = 1;
        int res = 0;
        while (b <= k) {
            swap(a, b);
            b += a;
        }
        // eg: k = 19, a = 13, b = 21
        while (k) {
            if (k >= a) {
                k -= a;
                ++res;
            }
            b -= a;
            swap(a, b);
        }
        return res;
    }
};