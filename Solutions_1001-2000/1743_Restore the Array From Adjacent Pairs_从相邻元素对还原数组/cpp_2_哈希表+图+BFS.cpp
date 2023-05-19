class Solution {
public:
    unordered_map<int, vector<int>> g;
    vector<int> path;
    queue<int> q;
    set<int> vis;
    
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, int> cnt;
        for (auto& e : adjacentPairs) {
            int a = e[0], b = e[1];
            g[a].push_back(b), g[b].push_back(a);
            cnt[a]++, cnt[b]++;
        }
        int root = 0;
        for (auto [k, v] : cnt)
            if (v == 1) {
                root = k;
                break;
            }
        q.push(root);
        vis.insert(root);
        while (!q.empty()) {
            auto t = q.front(); q.pop();
            path.push_back(t);
            for (int x : g[t]) {
                if (vis.find(x) == vis.end()) {
                    vis.insert(x);
                    q.push(x);
                }
            }
        }
        return path;
    }
};