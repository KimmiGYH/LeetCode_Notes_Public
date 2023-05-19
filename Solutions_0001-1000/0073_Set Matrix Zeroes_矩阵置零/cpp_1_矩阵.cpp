#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty())  return;
        int m = matrix.size(), n = matrix[0].size();

        int r0 = 1, c0 = 1;
        for (int i = 0; i < m; i++) if (!matrix[i][0]) c0 = 0;
        for (int j = 0; j < n; j++) if (!matrix[0][j]) r0 = 0;
        
        // 判断第一列有没有0
        for (int i = 0; i < m; i++)
            for (int j = 1; j < n; j++)
                if (!matrix[i][j]) matrix[0][j] = 0;

        // 判断第一行有没有0
        for (int i = 1; i < m; i++)
            for (int j = 0; j < n; j++)
                if (!matrix[i][j]) matrix[i][0] = 0;

        // 枚举除了第一列之外的每列
        for (int j = 1; j < n; j++)
            if (!matrix[0][j])
                for (int i = 0; i < m; i++)
                    matrix[i][j] = 0;

        // 枚举除了第一行之外的每行
        for (int i = 1; i < m; i++)
            if (!matrix[i][0])
                for (int j = 0; j < n; j++)
                    matrix[i][j] = 0;

        if (!r0) for (int j = 0; j < n; j++)  matrix[0][j] = 0;
        if (!c0) for (int i = 0; i < m; i++)  matrix[i][0] = 0;        
    }
};