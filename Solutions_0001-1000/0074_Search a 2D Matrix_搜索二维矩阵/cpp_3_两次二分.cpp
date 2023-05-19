class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        
        // 第一次二分：定位到所在行（从上往下，找到最后一个满足 mat[x]][0] <= t 的行号）
        int l = 0, r = m - 1;
        while (l < r) {
            int mid = l + r + 1 >> 1;
            if (matrix[mid][0] <= target) l = mid;
            else r = mid - 1;
        }
        int row = r;
        if (matrix[row][0] == target) return true;
        if (matrix[row][0] > target) return false;

        // 第二次二分：从所在行中定位到列（从左到右，找到最后一个满足 mat[row][x] <= t 的列号）
        l = 0; r = n - 1;
        while (l < r) {
            int mid = l + r + 1 >> 1;
            if (matrix[row][mid] <= target) l = mid;
            else r = mid - 1;
        }
        int col = r;
        
        return matrix[row][col] == target;
    }
};