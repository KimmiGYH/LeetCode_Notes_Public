#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size(), steps = 0;
        queue<int> q{{1}};
        vector<bool> visited(n * n + 1);
        map<int, int> positions;
        for (int num = 1; num <= n * n; num++) {
            int x = (num - 1) / n, y = (num - 1) % n;
            if (x % 2) y = (n - 1) - y;
            x = (n - 1) - x;
            positions[num] = board[x][y];
        }
        while (!q.empty()) {
            int len = q.size();
            while (len--) {
                int num = q.front(); q.pop();
                if (num == n * n)  return steps;
                for (int i = 1; i <= 6 && num + i <= n * n; i++) {
                    int next = positions[num + i];
                    if (next == -1) next = num + i;
                    if (visited[next])  continue;
                    visited[next] = true;
                    q.push(next);
                }
            }
            steps++;
        }
        return -1;
    }
};