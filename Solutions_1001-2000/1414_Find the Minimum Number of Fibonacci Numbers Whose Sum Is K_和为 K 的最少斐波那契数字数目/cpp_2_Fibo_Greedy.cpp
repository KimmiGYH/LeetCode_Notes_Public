#include <vector>

using namespace std;

class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        int a = 1, b = 1;
        vector<int> fibo = {a, b};
        while (a + b <= k) {
            fibo.push_back(a + b);
            swap(a, b);
            b += a;
        }
        int res = 0;
        for (int i = fibo.size() - 1; i >= 0; --i) {
            if (k >= fibo[i]) {
                ++res;
                k -= fibo[i];
            }
        }
        return res;
    }
};