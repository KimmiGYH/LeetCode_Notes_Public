#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        if (m == 0 || n == 0)  return false;
        int up = 0, down = m - 1, left = 0, right = n - 1;
        int new_up = 0, new_right = 0;
        int l, r;
        while(left < right || up < down) {
            // new_right: 找到最后一个小于等于 target 的数
            l = left, r = right;
            while (l <= r) {
                int mid = l + r >> 1;
                if (matrix[new_up][mid] <= target) l = mid + 1;
                else r = mid - 1;
            }
            new_right = r;
            if (new_right < left) return false;

            // new_up：找第一个大于等于 target 的数
            l = up, r = down;
            while (l <= r) {
                int mid = l + r >> 1;
                if (matrix[mid][new_right] >= target) r = mid - 1;
                else l = mid + 1;
            }
            new_up = l;
            if (new_up > down) return false;
            
            if (right == new_right && up == new_up)
                return true;
            
            right = new_right;
            up = new_up;
        }
        return matrix[new_up][new_right] == target;
    }
};