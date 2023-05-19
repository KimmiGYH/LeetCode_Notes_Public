#include <iostream>
#include <vector>

using namespace std;

class NumMatrix {
public:
    vector<vector<int>> s;
    
    NumMatrix(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty())  return;
        int m = matrix.size(), n = matrix[0].size();
        s = vector<vector<int>>(m + 1, vector<int>(n + 1));
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
                // matrix从0开始，而i,j从1开始，所以要减去偏移量
                s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + matrix[i - 1][j - 1];
    }
    
    int sumRegion(int x1, int y1, int x2, int y2) {
        ++x1, ++y1, ++x2, ++y2;
        return s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1];        
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */