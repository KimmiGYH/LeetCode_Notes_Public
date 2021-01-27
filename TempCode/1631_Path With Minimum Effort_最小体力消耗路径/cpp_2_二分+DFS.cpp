#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        int left = 0, right = 1e6;
        while (left < right) {
            int mid = left + right >> 1;
            vector<vector<bool>> visited(m, vector<bool>(n));
            if (dfsValid(heights, visited, 0, 0, mid))
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }
    
    bool dfsValid(vector<vector<int>>&heights, vector<vector<bool>>& visited, int tx, int ty, int limit) {
        int m = heights.size(), n = heights[0].size();
        if (tx == m - 1 && ty == n - 1)  return true;
        vector<int> dirs{0, 1, 0, -1, 0};
        visited[tx][ty] = true;
        
        for (int k = 0; k < 4; ++k) {
            int x = tx + dirs[k], y = ty + dirs[k + 1];
            if (x < 0 || x >= m || y < 0 || y >= n) continue;
            if (visited[x][y]) continue;
            if (abs(heights[x][y] - heights[tx][ty]) > limit) continue;
            if (dfsValid(heights, visited, x, y, limit)) return true;
        }
        return visited[m - 1][n - 1];
    }
};