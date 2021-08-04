#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
    vector<int> f;
    vector<int> r;
    int n;
    
    int candy(vector<int>& ratings) {
        n = ratings.size();
        r = ratings;
        f.resize(n, -1);
        
        int res = 0;
        for (int i = 0; i < n; i ++)
            res += dp(i);
        return res;
    }
    
    int dp(int x) {
        if (f[x] != -1) return f[x];
        f[x] = 1;
        if (x && r[x] > r[x - 1])
            f[x] = max(f[x], dp(x - 1) + 1);
        if (x + 1 < n && r[x] > r[x + 1])
            f[x] = max(f[x], dp(x + 1) + 1);
        return f[x];
    }
};