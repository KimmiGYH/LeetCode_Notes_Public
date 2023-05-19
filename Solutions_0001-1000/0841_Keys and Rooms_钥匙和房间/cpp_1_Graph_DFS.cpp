#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;


class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_set<int> visited;
        dfs(rooms, 0, visited);
        return visited.size() == rooms.size(); // 如果每个节点都访问过的话，那么hashset的size就是rooms的size，否则返回false
    }
    
    void dfs(const vector<vector<int>>& rooms, int cur, unordered_set<int>& visited) {
        if (visited.count(cur)) return;
        visited.insert(cur);
        for (int nxt : rooms[cur]) // 遍历当前房间的钥匙
            dfs(rooms, nxt, visited); // 打开下一个房间
    }
};