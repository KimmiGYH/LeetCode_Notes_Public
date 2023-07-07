class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;

    vector<vector<int>> combinationSum2(vector<int>& c, int target) {
        sort(c.begin(), c.end());
        dfs(c, 0, target);
        return res;        
    }
private:
    void dfs(vector<int>& c, int u, int target) {
        if (target == 0) {
            res.push_back(path);
            return;
        }
        if (u == c.size()) return;

        // 枚举当前这个数选几个
        int k = u + 1;
        while (k < c.size() && c[k] == c[u]) k ++;
        int cnt = k - u; //加了个数的限制，算出相同的数有几个

        for (int i = 0; c[u] * i <= target && i <= cnt; i ++) {
            dfs(c, k, target - c[u] * i);
            path.push_back(c[u]);
        }

        for (int i = 0; c[u] * i <= target && i <= cnt; i ++) {
            path.pop_back();
        }
    }
};