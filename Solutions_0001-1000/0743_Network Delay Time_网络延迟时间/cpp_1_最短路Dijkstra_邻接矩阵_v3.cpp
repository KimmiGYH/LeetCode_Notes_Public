class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        const int INF = 0X3F3F3F3F;
        vector<int> dist(n, INF);
        vector<bool> st(n);
        int g[n][n];

        memset(g, 0x3f, sizeof g);
        for (auto& t : times) {
            int x = t[0] - 1, y = t[1] - 1;
            g[x][y] = t[2];
        }

        dist[k - 1] = 0;

        for (int i = 0; i < n; ++i) {
            int t = -1;
            for (int j = 0; j < n; ++j) {
                if (!st[j] && (t == -1 || dist[t] > dist[j]))
                    t = j;
            }
            st[t] = true;

            for (int j = 0; j < n; ++j)
                dist[j] = min(dist[j], dist[t] + g[t][j]);
        }

        int res = *max_element(dist.begin(), dist.end());
        if (res == 0x3f3f3f3f) return -1;
        return res;
    }
};
// 存在邻接矩阵中，将节点编号减小了 1，从而使节点编号位于 [0,n-1] 范围。
