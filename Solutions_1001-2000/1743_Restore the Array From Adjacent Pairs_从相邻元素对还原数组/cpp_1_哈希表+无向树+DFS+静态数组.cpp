const int N = 2e5 + 10, offset = 1e5;
int h[N], e[N], ne[N], idx;
int cnt[N];

class Solution {
public:
    vector<int> path;
    
    void add (int a, int b) {
        e[idx] = b, ne[idx] = h[a], h[a] = idx++;
    }
    
    void dfs(int u, int father) {
        path.push_back(u - offset);
        for (int i = h[u]; i != -1; i = ne[i]) {
            int j = e[i];
            if (j != father)
                dfs(j, u);
        }
    }
    
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        memset(cnt, 0, sizeof cnt);
        memset(h, -1, sizeof h);
        idx = 0;
        for (auto& e : adjacentPairs) {
            int a = e[0] + offset, b = e[1] + offset;
            add(a, b), add(b, a);
            cnt[a]++, cnt[b]++;
        }
        
        int root = 0;
        for (int i = 0; i < N; i++)
            if (cnt[i] == 1) {
                root = i;
                break;
            }
        
        dfs(root, -1);
        return path;
    }
};
