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

        while (k) {
            int index = fibo.size() - 1;
            int i = idx(fibo, index, k);
            if (k >= fibo[i]) {
                ++res;
                k -= fibo[i];
            }
        }
        return res;
    }

    int idx(vector<int>& fibo, int& lastIndex, int& k) {
        int l = 0, r = lastIndex;
        while (l < r) {
            int m = l + r + 1 >> 1;
            if (fibo[m] <= k) l = m;
            else r = m - 1;
        }
        return l;
    }
};