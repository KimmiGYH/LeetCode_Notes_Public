class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n = matrix[0].size();
        int res = INT_MIN;
        
        vector<vector<int>> s(m + 1, vector<int>(n + 1));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                s[i][j] = s[i-1][j] + s[i][j-1] - s[i-1][j-1] + matrix[i-1][j-1];
            }
        }
        bool check = n > m;
        for (int i = 1; i <= (check ? m : n); ++i) {
            for (int j = i; j <= (check ? m : n); ++j) {
                set<int> bst;
                bst.insert(0);
                for (int t = 1; t <= (check ? n : m); ++t) {//t: fixed
                    int a = check ? (s[j][t] - s[i-1][t]) : (s[t][j] - s[t][i-1]);
                    auto it = bst.lower_bound(a - k);
                    if (it != bst.end()) {
                        int areaSum = a - *it;
                        res = max(res, areaSum);
                    }
                    bst.insert(a);
                }
            }
        }
        return res;
    }
};