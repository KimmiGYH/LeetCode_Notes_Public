#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int numSquares(int n) {
        static vector<int> dp(1, 0);
        for (int i = dp.size(); i <= n; i++) {
            dp.push_back(INT_MAX);
            for (int j = 1; j * j <= i; j++)
                dp[i] = min(dp[i], dp[i - j*j] + 1);
        }
        return dp[n];
    }
};
// Q: 那个 Static DP是什么方法哦？速度快这么多？
// wzc: 没什么方法，就是用一个塞一个，没啥区别
// yxc: static相当于全局变量，多组数据的时候不会每次重新定义变量，可能是这个原因
