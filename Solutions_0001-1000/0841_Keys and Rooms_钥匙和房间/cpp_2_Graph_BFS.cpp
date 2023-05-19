#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_set<int> visited{0};
        // queue<int> q{{0}};
        queue<int> q;
        q.push(0);
        while (!q.empty()) {
            int t = q.front(); q.pop();
            for (int nxt : rooms[t]) {
                if (visited.count(nxt)) continue;
                visited.insert(nxt);
                q.push(nxt);
            }
        }
        return visited.size() == rooms.size();
    }
};