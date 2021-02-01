#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        if (m == 0 || n == 0)  return false;

        int l = 0, r = m * n - 1;
        while (l < r) {
            int mid = l + r >> 1;
            if (matrix[mid / n][mid % n] >= target) r = mid;
            else l = mid + 1;
        }
        return matrix[r / n][r % n] == target;
        // return matrix[l / n][l % n] == target;
    }
};

// 写法二：

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        if (!m || !n) return false;
        
        int l = 0,  r = m * n - 1;
        while (l < r) {
            int mid = l + r + 1>> 1;
            if (matrix[mid/n][mid%n] <= target) l = mid;
            else r = mid - 1;
        }
        return matrix[r/n][r%n] == target;
    }
};