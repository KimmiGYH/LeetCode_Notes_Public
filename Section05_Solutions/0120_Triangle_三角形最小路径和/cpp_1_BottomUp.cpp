#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
Input:
   2
  3 4
 6 5 7
4 1 8 3
Output: 2 + 3 + 5 + 1 = 11
*/

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        for (int i = triangle.size() - 2; i >= 0; i--)
            for (int j = 0; j <= i; j++)
                triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1]);
        return triangle[0][0];
    }
};