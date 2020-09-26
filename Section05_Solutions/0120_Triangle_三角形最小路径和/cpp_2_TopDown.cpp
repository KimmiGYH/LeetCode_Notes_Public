#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        if (!n) return 0;
        vector<int> dp(n, 0);
        dp[0] = triangle[0][0];
        for (int i = 1; i < n; ++i) {
            for (int j = triangle[i].size() - 1; j >= 0; --j) {
                if (j == 0)
                    dp[j] = dp[j] + triangle[i][j];
                else if (j = triangle[i].size() - 1)
                    dp[j] = dp[j - 1] + triangle[i][j];
                else
                    dp[j] = min(dp[j - 1], dp[j]) + triangle[i][j];
            }
        }
        return *min_element(dp.begin(), dp.end()); // 注意返回的是一个迭代器，*取值
    }
};

/*
max_element()与min_element()都定义于头文件 <algorithm>，
分别实现了返回区间 [first,last)中第一个最大值和第一个最小值对应的迭代器。
注意返回的是一个迭代器，*取值
*/