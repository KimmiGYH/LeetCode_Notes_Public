class Solution {
public:
    bool check(vector<vector<int>>& matrix, int mid, int k, int n) {
        int i = n - 1;
        int j = 0;
        int cnt = 0;
        while (i >= 0 && j < n) {
            if (matrix[i][j] <= mid) {//左下角开始数
                cnt += i + 1;
                j++;
            } else {
                i--;
            }
        }
        return cnt >= k;
    }

    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int l = matrix[0][0];
        int r = matrix[n - 1][n - 1];
        while (l < r) {
            int mid = l + r >> 1;
            if (check(matrix, mid, k, n)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};