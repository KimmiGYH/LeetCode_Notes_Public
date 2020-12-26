#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 1)  return binary_search(matrix[0].begin(), matrix[0].end(), target);
        return search(matrix, 0, matrix[0].size() - 1, target);
    }

    bool search(vector<vector<int>>& matrix, int x, int y, int target) {
        if (x >= matrix.size() || y < 0)  return false;
        if (matrix[x][y] == target) return true;
        int lo, hi;
        // new_right:
        lo = 0, hi = y;
        while (lo < hi) {
            int m = lo + hi >> 1;
            if (matrix[x][m] <= target) lo = m;
            else hi = m - 1;
        }
        int new_y = lo;

        vector<vector<int>> nums;
        for (int i = 0; i < matrix.size(); i++)
            nums[i] = matrix[i][0];
        if (binary_search(nums[x].begin(), nums[x].end(), target))  return true;
        auto it = lower_bound(matrix[x].rbegin(), matrix[x].rend(), target);
        int new_y = y - distance(matrix[x].rbegin(), it);
        if (y == 0) return new_x < matrix.size() && matrix[new_x][y] == target;
        return search(matrix, new_x, new_y, target);
    }
};