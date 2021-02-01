#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        int m = matrix.size(), n = matrix[0].size();
        int l, r;

        int up = 0, down = matrix.size() - 1, left = 0, right = matrix[0].size() - 1;

        while (left < right || up < down) {
            int new_right, new_up;

            // new_right: 找到最后一个小于等于 target 的数
            l = left, r = right;
            while (l < r) {
                int m = l + r + 1 >> 1;
                if (matrix[up][m] <= target) l = m;
                else r = m - 1;
            }
            new_right = l;

            // new_up：找第一个大于等于 target 的数
            l = up, r = down;
            while (l < r) {
                int m = l + r >> 1;
                if (matrix[m][new_right] >= target) r = m;
                else l = m + 1;
            }
            new_up = r;
            

            /*遇到的case为：单行单列以及下面的
                [[1,1],[2,2]]
                0
            这步的return true 改为break就能AC*/            
            if (right == new_right && up == new_up)  break;

            right = new_right;
            up = new_up;
        }
        return matrix[up][right] == target;
    }
};