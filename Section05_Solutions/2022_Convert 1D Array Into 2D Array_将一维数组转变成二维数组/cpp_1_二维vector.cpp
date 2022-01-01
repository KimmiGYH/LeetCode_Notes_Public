class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> res(m, vector<int>(n));
        if (m * n != original.size()) return {};
        for (int i = 0, idx = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                res[i][j] = original[idx++];
            }
        }
        return res;
    }
};