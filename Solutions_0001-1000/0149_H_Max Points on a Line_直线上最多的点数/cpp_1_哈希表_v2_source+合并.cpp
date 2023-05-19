class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int res = 0;
        for (vector<int>& p : points) {
            unordered_map<double, int> hash;
            int source = 0, cnt = 0;
            for (vector<int> q : points) {
                if (p == q) source++;
                else {
                    int dx = q[0] - p[0], dy = q[1] - p[1];
                    double k = dy * 1.0 / dx;
                    hash[k]++;
                    cnt = max(cnt, hash[k]);
                }
            }
            res = max(res, cnt + source);
        }
        return res;
    }
};

/*
将 source 单独算，将 vertical 合并到 hash[k] 里
*/