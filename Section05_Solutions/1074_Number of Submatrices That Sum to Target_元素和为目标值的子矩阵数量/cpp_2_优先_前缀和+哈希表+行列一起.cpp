class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size(), res = 0;
        vector<vector<int>> s(m + 1, vector<int>(n + 1));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                s[i][j] = s[i-1][j] + s[i][j-1] - s[i-1][j-1] + matrix[i-1][j-1];
            }
        }
        
        for (int x1 = 1; x1 <= m; ++x1) {
            for (int x2 = x1; x2 <= m; ++x2) {
                unordered_map<int, int> hash;
                hash[0] = 1; //这是当prefix==target时，也即x2==x1时，计入的子矩阵数
                for (int y = 1; y <= n; ++y) {
                    int prefix = s[x2][y] - s[x1 - 1][y];
                    res += hash[prefix - target];
                    hash[prefix]++;
                }
            }
        }
        return res;
    }
};

// ----------------------------------------------------------------

class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size(), res = 0;
        vector<vector<int>> s(m + 1, vector<int>(n + 1));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                s[i][j] = s[i-1][j] + s[i][j-1] - s[i-1][j-1] + matrix[i-1][j-1];
            }
        }
        
        for (int x1 = 1; x1 <= m; ++x1) {
            for (int x2 = x1; x2 <= m; ++x2) {
                unordered_map<int, int> hash;
                for (int y = 1, prefix = 0; y <= n; ++y) {
                    prefix = s[x2][y] - s[x1 - 1][y];
                    if (prefix == target) res++;
                    res += hash[prefix - target];
                    hash[prefix]++;
                }
            }
        }
        return res;
    }
};