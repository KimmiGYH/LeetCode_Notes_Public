#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty())  return false;
        
        int up = 0, down = matrix.size() - 1, left = 0, right = matrix[0].size() - 1;
        int l, r;
        while(left < right || up < down) {
            int new_left, new_right, new_up, new_down;

            // new_right: find the last element in up row that is <= target
            l = left, r = right;
            while (l < r) {
                int m = l + r + 1 >> 1;
                if (matrix[up][m] <= target)
                    l = m;
                else
                    r = m - 1;
            }
            new_right = l;

            // new_up: find the first element in new_right column that is >= target
            l = up, r = down;
            while (l < r) {
                int m = l + r >> 1;
                if (matrix[m][new_right] >= target)
                    r = m;
                else
                    l = m + 1;
            }
            new_up = l;

            // if left, right, up, down stops updating. The whole square is target
            if (right == new_right && up == new_up)
                return true;

            right = new_right;
            up = new_up;
        }
        return matrix[up][right] == target;
    }
};