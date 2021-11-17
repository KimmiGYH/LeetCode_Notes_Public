class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int l = matrix[0][0], r = matrix[n-1][n-1];
        while (l < r) {
            int mid = (long long)l + r >> 1;
            int cnt = search(matrix, n, mid);
            if (cnt >= k) r = mid;
            else l = mid + 1;
        }
        return r;
    }
    int search(vector<vector<int>>& matrix, int n, int target) {
        int cnt = 0;
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < n; j ++) {
                if (matrix[i][j] <= target) {
                    cnt ++;
                    continue;
                }
                break;
            }
        }
        return cnt;
    }
};