#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        if (m == 0 || n == 0)  return false;
        
        int row = 0, col = n - 1;
        while (row < m && col >= 0) {
            int t = matrix[row][col];
            if (t == target)  return true;
            if (target < t) col--;
            else row++;
        }
        return false;
    }
};