#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> f(amount + 1);
        f[0] = 1;
        for (auto v : coins)
            for (int j = v; j <= amount; j++)
                f[j] += f[j - v];
        return f[amount];
    }
};