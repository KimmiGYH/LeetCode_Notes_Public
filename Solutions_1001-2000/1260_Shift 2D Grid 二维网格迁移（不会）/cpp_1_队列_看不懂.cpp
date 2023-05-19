#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {

        queue<int> q;

        // 从 grid 末尾开始进队
        for (int i = grid.size() - 1; i >= 0; i--)
            for (int j = grid[0].size() - 1; j >= 0; j--)
                q.push(grid[i][j]);
        
        // 队列头出队，再入队
        for (k; k > 0; k--)
        {
            int n = q.front();
            q.pop();
            q.push(n);
        }

        // 以 grid 末尾对应队列队头，重组 grid
        for (int i = grid.size() - 1; i >= 0; i--)
            for (int j = grid[0].size() - 1; j >= 0; j--)
            {
                int n = q.front();
                q.pop();
                grid[i][j] = n;
            }
        
        return grid;
    }
};