#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size(), steps = 0;
        queue<int> q{{1}};
        vector<bool> visited(n * n + 1);

        while (!q.empty()) {
            int len = q.size();
            while (len--) {
                int num = q.front(); q.pop();
                if (num == n * n)  return steps;
                for (int i = 1; i <= 6 && num + i <= n * n; i++) {
                    vector<int> pos = getPosition(n, num + i);
                    int next = board[pos[0]][pos[1]] == -1 ? num + i : board[pos[0]][pos[1]];
                    if (visited[next])  continue;
                    visited[next] = true;
                    q.push(next);
                }
            }
            steps++;
        }
        return -1;
    }

    vector<int> getPosition(int &n, int num) {
        unordered_map<int, vector<int>> positions;
        if (positions.find(num) == positions.end()) {
            int row = 0, col = 0;
            int x = (num - 1) / n, y = (num - 1) % n;
            if (x % 2) col = (n - 1) - y;
            else col = y;
            row = (n - 1) - x;
            positions[num] = {row, col};
            return {row, col};
        } else return positions[num];
    }
};