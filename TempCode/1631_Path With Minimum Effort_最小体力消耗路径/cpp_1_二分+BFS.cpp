#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int left = 0, right = 1e6;
        while (left < right) {
            int mid = left + right >> 1;
            if (isValid(heights, mid))
                right = mid;
            else
                left = mid + 1;
        }
        return left;        
    }
    
    bool isValid(vector<vector<int>>&heights, int limit) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n));
        vector<int> dirs{0, 1, 0, -1, 0};
        queue<pair<int, int>> q;
        
        q.push({0, 0});
        visited[0][0] = true;
        while (!q.empty()) {
            int tx = q.front().first, ty = q.front().second;
            q.pop();
            for (int k = 0; k < 4; ++k) {
                int x = tx + dirs[k], y = ty + dirs[k + 1];
                if (x < 0 || x >= m || y < 0 || y >= n) continue;
                if (visited[x][y]) continue;
                if (abs(heights[x][y] - heights[tx][ty]) > limit) continue;
                q.push({x, y});
                visited[x][y] = true;
            }
        }
        return visited[m - 1][n - 1];
    }
};