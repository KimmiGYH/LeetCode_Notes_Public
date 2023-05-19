class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int dist[n+1];
        int g[n+1][n+1];
        bool st[n+1];

        memset(g, 0x3f, sizeof g);
        for (auto& t : times) {
            int x = t[0], y = t[1];
            g[x][y] = t[2];
        }

        memset(dist, 0x3f, sizeof dist);
        dist[k] = 0;
        
        memset(st, 0, sizeof st);
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
        
        int res = *max_element(dist+1, dist+n+1);
        if (res == 0x3f3f3f3f) return -1;
        return res;
    }
};

// 开了 n+1 长度，节点编号从 1 开始，位于 [1,n] 范围内
// 普通数组求最大值，语法为
a[] = {1,2,3,4,5,6};
最大值：int maxValue = *max_element(a, a+6);
最小值：int minValue = *min_element(a, a+6);

