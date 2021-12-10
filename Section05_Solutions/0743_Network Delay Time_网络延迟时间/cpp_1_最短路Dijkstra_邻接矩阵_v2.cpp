class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        const int INF = 0X3F3F3F3F;
        vector<int> dist(n+1, INF);
        vector<bool> st(n+1);
        int g[n+1][n+1];

        memset(g, 0x3f, sizeof g);
        for (auto& t : times) {
            int x = t[0], y = t[1];
            g[x][y] = t[2];
        }

        dist[k] = 0;

        for (int i = 0; i < n; ++i) {
            int t = -1;
            for (int j = 1; j <= n; ++j) {
                if (!st[j] && (t == -1 || dist[t] > dist[j]))
                    t = j;
            }
            st[t] = true;

            for (int j = 1; j <= n; ++j)
                dist[j] = min(dist[j], dist[t] + g[t][j]);
        }

        int res = *max_element(dist.begin()+1, dist.end());
        if (res == INF) return -1;
        return res;
    }
};
// 邻接矩阵存节点，节点编号位于 [1, n] 范围内，总共开了 n+1 的长度
