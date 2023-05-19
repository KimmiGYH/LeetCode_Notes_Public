#include <iostream>

using namespace std;

const int N = 5e6 + 10;
int primes[N];
bool is_prime[N];

class Solution {
public:
    int countPrimes(int n) {
        if (n < 3)  return 0;
        int cnt = 0;
        memset(is_prime, true, sizeof(is_prime));
        is_prime[0] = is_prime[1] = false;
        for (int i = 2; i < n; ++ i) {
            if (is_prime[i])  primes[cnt ++] = i;
            for (int j = 0; primes[j] * i < n; ++ j) {
                is_prime[primes[j] * i] = false;
                if (i % primes[j] == 0) break;
            }
        }
        return cnt;
    }
};