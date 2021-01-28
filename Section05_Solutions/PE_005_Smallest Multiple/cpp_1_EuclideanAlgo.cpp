#include <iostream>

typedef unsigned long long ULL;
using namespace std;


ULL gcd(ULL a, ULL b) {
    return b ? gcd(b, a % b) : a;
}

ULL lcm(ULL a, ULL b) {
    return a * b / gcd(a, b);
}

int main() {
    ULL res = 1;
    for (ULL i = 1; i <= 20; ++i)
        res = lcm(i, res);
    
    cout << res << endl;
    return 0;
}
// Output: 232792560