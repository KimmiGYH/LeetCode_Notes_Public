#include <iostream>

using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        if (n < 3) return 0;
        int primes[n + 1], cnt = 0;
        bool st[n + 1];
        memset(st, 0, sizeof(st));
        for (int i = 2; i < n; i ++)
        {
            if (!st[i]) primes[cnt ++] = i;
            for (int j = 0; primes[j] * i < n; j ++)
            {
                st[i * primes[j]] = true;
                if (i % primes[j] == 0)  break;
            }
        }
        return cnt;
    }
};