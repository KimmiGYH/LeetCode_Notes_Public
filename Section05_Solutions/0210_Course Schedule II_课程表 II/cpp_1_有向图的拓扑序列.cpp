#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n);
        vector<int> d(n);
        for (auto& e : edges) {
            int a = e[1], b = e[0];
            g[a].push_back(b);
            d[b] ++;
        }
        
        queue<int> q;
        for (int i = 0; i < n; ++i)
            if (d[i] == 0)
                q.push(i);
        
        vector<int> res;
        while (!q.empty()) {
            auto t = q.front(); q.pop();
            res.push_back(t);
            for (int i : g[t]) // 遍历所有 t 的邻边
                if (-- d[i] == 0)
                    q.push(i);
        }
        if (res.size() < n)  res = {};
        return res;
    }
};