class Solution {
    using LL = long long;
public:
    int arrangeCoins(int n) {
        return (-1 + sqrt(1 + (LL)8*n)) / 2;
    }
};