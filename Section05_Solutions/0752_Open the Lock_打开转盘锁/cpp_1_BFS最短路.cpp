#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        string start = "0000";
        if (start == target) return 0;
        unordered_set<string> deadset;
        for (auto& s: deadends) deadset.insert(s);
        if (deadset.count(start)) return -1;
        queue<string> q;
        q.push(start);
        unordered_map<string, int> dist; //距离数组
        dist[start] = 0;
        while(q.size()) {
            auto t = q.front();
            q.pop();
            for (int i = 0; i < 4; i ++) //四个方向
                for (int j = -1; j <= 1; j += 2) { //加一减一
                    auto state = t;
                    state[i] = (state[i] - '0' + j + 10) % 10 + '0';
                    if (!dist.count(state) && !deadset.count(state)) {
                        dist[state] = dist[t] + 1;
                        if (state == target) return dist[state];
                        q.push(state);
                    }
                }
        }
        return -1;
    }
};