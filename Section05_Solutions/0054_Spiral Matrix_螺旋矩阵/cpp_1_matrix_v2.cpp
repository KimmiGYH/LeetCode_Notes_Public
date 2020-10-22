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
        vector<vector<bool>> check(m, vector<bool>(n));

        for (int k = 0; k < m * n; ++k) {
            res.push_back(matrix[x][y]);
            check[x][y] = true;
            int a = x + dx[d], b = y + dy[d];
            if (a < 0 || a >= m || b < 0 || b >= n || check[a][b] == true) {
                d = (d + 1) % 4;
                a = x + dx[d], b = y + dy[d];
            }
            x = a, y = b;
        }
        return res;
    }
};