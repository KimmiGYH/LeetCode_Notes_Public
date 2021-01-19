#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        for (int i = 1; i < m; ++i)
            for (int j = 0; j < n; ++ j)
                if (matrix[i][j])
                    matrix[i][j] += matrix[i-1][j];
        
        int res = 0;
        vector<int> heights(n);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j)
                heights[j] = matrix[i][j];
            sort(heights.begin(), heights.end(), greater<int>());
            for (int j = 0; j < n; ++j)
                res = max(res, heights[j] * (j + 1));
        }
        return res;
    }
};