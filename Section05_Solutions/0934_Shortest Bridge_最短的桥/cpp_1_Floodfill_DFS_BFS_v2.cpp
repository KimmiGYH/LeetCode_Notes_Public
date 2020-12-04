#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> dirs{0, 1, 0, -1, 0};

    // 先 dfs 找到第一个岛屿，把节点标记成 2
    int shortestBridge(vector<vector<int>>& A) {
        queue<pair<int, int>> q;
        bool found = false;
        for (int i = 0; i < A.size() && !found; ++i)
            for (int j = 0; j < A[0].size() && !found; ++j) {
                if (A[i][j]) {
                    dfs(A, i, j, q);
                    found = true;
                }
            }
        return bfs(A, q);
    }

    // 再 bfs 搜寻最短的桥，算出标记为 2 的节点到值为 1 的节点之间的步数，求出steps
    int bfs(vector<vector<int>>& A, queue<pair<int, int>>& q) {
        int steps = 0;
        while (!q.empty()) {
            size_t size = q.size();
            while (size--) { // BFS模板，按层扩展，size是当前这层需要扩展的节点数量
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for (int k = 0; k < 4; ++k) {
                    int tx = x + dirs[k], ty = y + dirs[k + 1];
                    if (tx < 0 || ty < 0 || tx >= A.size() || ty >= A[0].size() || A[tx][ty] == 2) continue;
                    if (A[tx][ty] == 1)  return steps;
                    A[tx][ty] = 2;
                    q.emplace(tx, ty);
                }
            }
            ++steps;
        }
        return -1;
    }

    void dfs(vector<vector<int>>& A, int x, int y, queue<pair<int, int>>& q) {
        if (x < 0 || y < 0 || x >= A.size() || y >= A[0].size() || A[x][y] != 1)  return;
        A[x][y] = 2;
        q.emplace(x, y); // 把(纵,横)坐标加进去
        for (int k = 0; k < 4; ++k) {
            int a = x + dirs[k], b = y + dirs[k + 1];
            dfs(A, a, b, q);
        }
    }
};