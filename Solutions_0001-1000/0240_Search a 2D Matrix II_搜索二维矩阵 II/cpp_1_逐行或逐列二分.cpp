class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        if (!m || !n) return false;
        for (int i = 0; i < m; i++) {
            int l = 0, r = n - 1;
            while (l < r) {
                int mid = l + r + 1 >> 1;
                if (matrix[i][mid] <= target) l = mid;
                else r = mid - 1;
            }
            if (matrix[i][r] == target) return true;
        }
        return false;
    }
};