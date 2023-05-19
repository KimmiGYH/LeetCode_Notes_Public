class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        using PII = pair<int, int>;
        int dist[n+1];
        bool st[n+1];
        vector<vector<PII>> adj(n+1);
        for (auto& t : times) {
            int x = t[0], y = t[1];
            adj[x].push_back({y, t[2]});//adj[node]={dst, time}
        }
        
        memset(dist, 0x3f, sizeof dist);
        dist[k] = 0;
        priority_queue<PII, vector<PII>, greater<PII>> heap;
        heap.push({0, k}); // 初始{time, src}
        while (!heap.empty()) {
            auto t = heap.top();
            heap.pop();
            int time = t.first, node = t.second;
            // if (dist[node] < time)  continue;
            // for (auto& [next, time] : adj[node]) 
            for (auto& e : adj[node]) {
                int next = e.first, time = e.second;
                int cost = dist[node] +  time;
                if (dist[next] > cost) {
                    dist[next] = cost;
                    heap.push({cost, next});
                }
            }
        }
        
        int res = *max_element(dist+1, dist+n+1);
        if (res == 0x3f3f3f3f) return -1;
        return res;
    }
};

//times[i] = (ui, vi, wi)，其中 ui 是源节点，vi 是目标节点， wi 是一个信号从源节点传递到目标节点的时间。
//用数组存节点
