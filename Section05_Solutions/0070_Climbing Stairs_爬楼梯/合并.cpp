/*一只青蛙一次可以跳上1级台阶，也可以跳上2级台阶。
求该青蛙跳上一个 n 级的台阶总共有多少种跳法。*/
#include <iostream>
#include <vector>
using namespace std;


// 方法一：记忆化递归
class Solution {
private:
    vector<int> memo;
    int calc(int n) {
        if (n == 0 || n == 1)
            return 1;
        if (memo[n] == -1)
            memo[n] = calc(n-1) + calc(n-2);
        return memo[n];
    }
public:
    int climbStairs(int n) {
        memo = vector<int>(n+1, -1);
        return calc(n);
    }
};

// 方法二：动态规划迭代
class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; i++)
            dp[i] = dp[i-1] + dp[i-2];
        return dp[n];
    }
};

// 方法三：Fibonacci数列
class Solution {
public:
    int climbStairs(int n) {
        int a = 1, b = 1, c = 2;
        for (int i = 3; i <= n; ++i) {
            a = b;
            b = c;
            c = a + b;
        }
        return c;
    }
};


