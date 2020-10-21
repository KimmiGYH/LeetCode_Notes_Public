#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // When do you change direction?
    // 1. out of boundary
    // 2. encounter a number we've encountered before: use '0' as a marker
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty())
            return {};

        vector<int> res, dx{0, 1, 0, -1}, dy{1, 0, -1, 0};
        int m = matrix.size(), n = matrix[0].size(), d = 0, x = 0, y = 0;
        for (int k = 0; k < m * n; ++k) {
            res.push_back(matrix[x][y]);
            matrix[x][y] = 0;
            int i = x + dx[d], j = y + dy[d];
            if (i < 0 || i >= m || j < 0 || j >= n || matrix[i][j] == 0) {
                d = (d + 1) % 4;
                i = x + dx[d], j = y + dy[d];
            }
            x = i, y = j;
        }
        return res;
    }
};