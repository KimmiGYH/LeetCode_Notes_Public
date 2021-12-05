class Solution {
public:
    int superPow(int a, vector<int>& b) {
        if (a == 1) return 1;
        typedef long long LL;
        int p = 1337;
        LL r = 0, res = 1;
        for (auto& x : b) {
            r = r * 10 + 1ll * x;
        }
        while (r) {
            if (r & 1) res = (LL)res * a % p;
            a = (LL)a * a % p;
            r >>= 1;
        }
        return res;
    }
};
//爆 long long 了