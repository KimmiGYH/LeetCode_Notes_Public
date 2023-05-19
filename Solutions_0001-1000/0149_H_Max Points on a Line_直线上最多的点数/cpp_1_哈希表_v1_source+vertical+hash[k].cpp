class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int res = 0;
        for (vector<int>& p : points) {
            unordered_map<double, int> hash;
            int source = 0, vertical = 0;
            for (vector<int> q : points) {
                if (p == q) source++;
                else if (p[0] == q[0]) vertical++;
                else {
                    int dx = q[0] - p[0], dy = q[1] - p[1];
                    double k = dy * 1.0 / dx;
                    hash[k]++;
                }
            }
            int cnt = vertical;
            for (auto& [k, v] : hash) cnt = max(cnt, v);
            res = max(res, cnt + source);
        }
        return res;
    }
};
/*
将 source、vertical、hash[k] 单独算
source 单独算能免去边界处理的麻烦
*/