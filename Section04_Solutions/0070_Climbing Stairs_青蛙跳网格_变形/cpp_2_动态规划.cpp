#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int climbStairs(int n, int m) {
        if (n == 1 || n == 2)
            return n;

        vector<int> dp(n+1, 0);

        dp[0] = 1;
        dp[1] = 1;

        //分2种情况讨论
        //1.n<m,f(n,m)=f(n-1)+f(n-2)+..+f(1)
        //2.n>=m.f(n,m)=f(n-1)+f(n-2)+..+f(n-m)
        for (int i = 2; i < n; ++i) {
            int max = (i < m) ? i : m;
            for (int j = 1; j < m; ++j) {
                dp[i] += dp[i-j];
            }
        }
        return dp[n];
    }
};

int main() {
    Solution solution = Solution();
    cout << solution.climbStairs(5, 3) << endl;
    return 0;
}