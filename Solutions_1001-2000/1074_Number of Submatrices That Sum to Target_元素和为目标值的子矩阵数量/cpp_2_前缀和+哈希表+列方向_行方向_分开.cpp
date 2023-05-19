class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size(), res = 0;
        vector<vector<int>> s(m + 1, vector<int>(n + 1));
        //预处理列方向的前缀和
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                s[i][j] = s[i-1][j] + matrix[i-1][j-1];//列没放进去
            }
        }
        //x1 上边界，x2 下边界
        for (int x1 = 1; x1 <= m; ++x1) {
            for (int x2 = x1; x2 <= m; ++x2) {
                unordered_map<int, int> hash;
                hash[0] = 1;
                for (int y = 1, sum = 0; y <= n; ++y) {
                    sum += s[x2][y] - s[x1 - 1][y]; //注意这里前缀和是累加列
                    res += hash[sum - target];
                    hash[sum]++;
                }
            }
        }
        return res;
    }
};

// ------------------------------------------------------------------------

class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size(), res = 0;
        vector<vector<int>> s(m + 1, vector<int>(n + 1));
        //预处理行方向的前缀和
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                s[i][j] = s[i][j-1] + matrix[i-1][j-1];
            }
        }
        //y1 左边界，y2 右边界
        for (int y1 = 1; y1 <= n; ++y1) {
            for (int y2 = y1; y2 <= n; ++y2) {
                unordered_map<int, int> hash;
                hash[0] = 1;
                for (int x = 1, sum = 0; x <= m; ++x) {
                    sum += s[x][y2] - s[x][y1 - 1]; //注意这里前缀和是累加行
                    res += hash[sum - target];
                    hash[sum]++;
                }
            }
        }
        return res;
    }
};