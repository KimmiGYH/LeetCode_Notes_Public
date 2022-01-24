class Solution {
    const int MOD = 1e9 + 7;
public:
    int countPairs(vector<int>& deliciousness) {
        int res = 0;
        unordered_map<int, int> hash;
        for (int& x : deliciousness) {
            for (int i = 0; i <= 21; i++) {
                int t = (1 << i) - x;
                if (hash.count(t))
                    res = (res + hash[t]) % MOD;
            }
            hash[x]++; //需要放下面，因为判断是从 x 后面的数开始的，即求 S - x后面的数 是否等于x 的个数
        }
        return res;
    }
};