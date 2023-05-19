#include <iostream>
#include <vector>
#include <queue>

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
                    int next = getBoardValue(board, num + i);
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

    int getBoardValue(vector<vector<int>>& board, int num) {
        int n = board.size();
        int x = (num - 1) / n, y = (num - 1) % n;
        int row = 0, col = 0;
        if (x % 2) col = (n - 1) - y;
        else col = y;
        row = (n - 1) - x;
        return board[row][col];
    }
};