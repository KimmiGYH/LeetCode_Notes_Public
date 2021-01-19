#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    // numCourses = 2, prerequisites = [[1,0],[0,1]]
    // n = numCourses, edges = prerequisites
    bool canFinish(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n);
        vector<int> d(n); // 统计每个点的入度
        for (auto& e : edges) {
            int a = e[1], b = e[0];
            g[a].push_back(b); // 将所有边插入邻接表，插入a指向b的边
            d[b] ++; // 每条边 b 的入度加 1
        }
        
        queue<int> q;
        for (int i = 0; i < n; ++i)
            if (d[i] == 0) // 如果当前点入度为 0 说明当前点可以被遍历
                q.push(i);
        
        int cnt = 0; // 判断一共有多少个点被遍历过
        while (!q.empty()) {
            auto t = q.front(); q.pop();
            cnt ++;
            for (auto i : g[t]) // 枚举当前点的所有后继节点
                if (-- d[i] == 0)
                    q.push(i);
        }
        
        return cnt == n; // 如果遍历的点数量等于 n 的话 说明存在拓扑序，否则不存在拓扑序
    }
};