class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int sz = points.size();
        if (sz < 3) return sz;
        int res = 0;
        for (int i = 0; i < sz; ++i) {
            unordered_map<double, int> hash;
            for (int j = 0; j < sz; ++j) {
                if (i != j) {
                    int dx = points[i][0] - points[j][0];
                    int dy = points[i][1] - points[j][1];
                    double k = dy * 1.0 / dx; //dx=0时, k=inf或-inf
                    if (hash.count(k)) {hash[k]++;}
                    else {hash[k] = 2;}
                    res = max(res, hash[k]);
                }
            }
        }
        return res;
    }
};
/*
1) dx = 0, dy = 0
2) dx = 0, dy != 0
3) dx != 0, dy != 0
这里将 1) 2) 合并处理了
*/