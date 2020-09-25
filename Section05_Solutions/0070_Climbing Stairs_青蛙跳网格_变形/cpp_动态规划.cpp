#include <iostream>
#include <vector>

using namespace std;

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


    int climbStairs(int N)
    {
        vector<int>dp(N+1, 0);
        dp[1]=1;
        dp[2]=2;
        for(int i = 3; i <= N; ++i)
        {
            int sum_of_before=0;
            for(int j = 1; j < i; ++j)
            sum_of_before = sum_of_before + dp[j];
            dp[i] = sum_of_before;
        }
        return dp[N];
    }


    int climbStairs(int N)
    {
        vector<int>dp(N+1,0);
        dp[1]=1;
        dp[2]=2;
        int sum=3;
        for(int i = 3;i <= N;++i)
        {
            dp[i] = sum + 1;
            //sum = sum + dp[i];即是说sum=sum+sum+1=2sum+1
            sum = 2 * sum + 1;
        }
        return dp[N];
    }
};


int main() {
    Solution solution = Solution();
    cout << solution.climbStairs(42) << endl;
    return 0;
}