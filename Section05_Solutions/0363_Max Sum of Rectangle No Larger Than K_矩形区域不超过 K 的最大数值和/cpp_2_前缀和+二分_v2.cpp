class Solution {
public:
    vector<vector<int>> s;

    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n = matrix[0].size();
        int res = INT_MIN;
        s = vector<vector<int>>(m + 1, vector<int>(n + 1));
        for (int i = 1; i <= m; ++i){
            for (int j = 1; j <= n; ++j) {
                s[i][j] = s[i-1][j] + s[i][j-1] - s[i-1][j-1] + matrix[i-1][j-1];
            }
        }
        
        for (int x1 = 1; x1 <= m; ++ x1) {
            for (int x2 = x1; x2 <= m; ++ x2) {
                set<int> bst;
                bst.insert(0);
                for (int y2 = 1; y2 <= n; ++ y2) {
                    int sy2 = s[x2][y2] - s[x1 - 1][y2];//蓝色区域面积
                    auto it = bst.lower_bound(sy2 - k);
                    if (it != bst.end())
                        res = max(res, sy2 - *it);//sy2 - *it 是areaSum
                    bst.insert(sy2);
                }
            }
        }
        return res;
    }
};