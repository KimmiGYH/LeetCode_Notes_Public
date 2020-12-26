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
        if (binary_search(matrix[x].begin(), matrix[x].end(), target)) return true;
        int l, h, new_x, new_y;
        l = x, h = matrix.size();
        while (l < h) {
            int m = (l + h) >> 1;
            if (matrix[m][y] >= target)  h = m;
            else l = m + 1;
        }
        new_x = l;
        l = y, h = matrix[0].size();
        while (l < h) {
            int m = (l + h + 1) >> 1;
            if (matrix[new_x][m] <= target) l = m;
            else h = m - 1;
        }
        new_y = l;

        if (y == 0)  return new_x < matrix.size() && matrix[new_x][y] == target;
        return search(matrix, new_x, new_y, target);
    }
};