#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        for (int i = triangle.size() - 2; i >= 0; --i) // 最后一行不要算
            for (int j = 0; j <= i; ++j)
                triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1]);
        return triangle[0][0];
    }
};

// 另一种写法
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> mini = triangle[triangle.size() - 1];
        for (int i = triangle.size() - 2; i >= 0; --i) // 最后一行不要算
            for (int j = 0; j <= i; ++j)
                mini[j] = triangle[i][j] + min(triangle[i + 1][j], triangle[i + 1][j + 1]);
        return mini[0];
    }
};
