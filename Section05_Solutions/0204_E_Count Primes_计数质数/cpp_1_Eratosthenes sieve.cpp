#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        if (n < 3) return 0;
        
        vector<unsigned char> is_prime(n, 1);
        is_prime[0] = is_prime[1] = 0;
        for (long i = 2; i <= n / i; ++i)
        {
            if (!is_prime[i]) continue;
            for (long j = i * i; j < n; j += i)
                is_prime[j] = 0;
        }
        
        int res = accumulate(is_prime.begin(), is_prime.end(), 0);
        
        return res;
    }
};