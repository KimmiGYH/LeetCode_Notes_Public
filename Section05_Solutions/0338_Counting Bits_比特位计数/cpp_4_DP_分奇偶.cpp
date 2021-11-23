class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n, 0);
        res.push_back(0);
        if (!n) return res;
        for (int i = 1; i <= n; ++i) {
            if (i % 2 == 0)
                res[i] = res[i >> 1];
            else
                res[i] = res[i >> 1] + 1;
        }
        return res;
    }
};