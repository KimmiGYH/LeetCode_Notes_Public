class Solution {
public:
    unordered_set<int> hash;
    int m;
    const int N = 1e6;
    const int BASE = 131;

    int get(vector<int> pos) {
        return pos[0] * BASE + pos[1];
    }

    bool bfs(vector<int>& source, vector<int>& target) {
        unordered_set<int> visited = hash;
        queue<vector<int>> q;
        q.push(source);
        visited.insert(get(source));
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};
        int cnt = 1;
        
        while (!q.empty()) {
            auto t = q.front(); q.pop();
            for (int k = 0; k < 4; k++) {
                int x = t[0] + dx[k], y = t[1] + dy[k];
                if (x >= 0 && x < N && y >= 0 && y < N && !visited.count(get({x, y}))) {
                    cnt++;
                    if (cnt > m * (m - 1) / 2) return true;
                    if (x == target[0] && y == target[1]) return true;
                    q.push({x, y});
                    visited.insert(get({x, y}));
                }
            }
        }
        return false;
    }

    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        m = blocked.size();
        for (vector<int>& block : blocked)
            hash.insert(get(block));
        return bfs(source, target) && bfs(target, source);
    }
};