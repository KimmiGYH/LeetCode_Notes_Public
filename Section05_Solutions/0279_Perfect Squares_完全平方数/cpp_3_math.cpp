#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    bool check(int x) {
        int r = sqrt(x);
        return r * r == x;
    }

    int numSquares(int n) {
        // 能表示成一个数的平方，返回 1
        if (check(n))  return 1;

        // 能表示成两个数的平方，返回 2
        for (int a = 1; a <= n / a; a++)
            if (check(n - a * a))
                return 2;

        // n != 4^a * (8b + 7)，返回 3
        // 否则返回 4 
        while (n % 4 == 0)  n /= 4;
        if (n % 8 != 7)  return 3;
        return 4;
    }
};