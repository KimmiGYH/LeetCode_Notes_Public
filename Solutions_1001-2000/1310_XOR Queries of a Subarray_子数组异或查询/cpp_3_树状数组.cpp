class Solution {
public:
    int t[30005];
    int n;
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        n = arr.size();
        memset(t, 0, sizeof t);
        vector<int> res;
        for (int i = 0; i < n; ++i)
            add(i + 1, arr[i]);
        for (auto& q : queries) {
            int L = q[0], R = q[1];
            res.emplace_back(ask(R + 1) ^ ask(L));
        }
        return res;
    }
    
    int lowbit(int x) {
        return x & -x;
    }
    
    void add(int x, int y) {
        for (int i = x; i <= n; i += lowbit(i))
            t[i] ^= y;
    }
    
    int ask(int x) {
        int prexor = 0;
        for (int i = x; i; i -= lowbit(i))
            prexor ^= t[i];
        return prexor;
    }
};