class Solution {
public:
    const int p = 1337;
    
    int superPow(int a, vector<int>& b) {
        int res = 1;
        for (int& x : b) {
            res = binpow(res, 10) * binpow(a, x) % p;
        }
        return res;
    }
    
    int binpow(int a, int b) {
        a %= p;
        int res = 1;
        while (b) {
            if (b & 1) res = res * a % p;
            a = a * a % p;
            b >>= 1;
        }
        return res;
    }
};