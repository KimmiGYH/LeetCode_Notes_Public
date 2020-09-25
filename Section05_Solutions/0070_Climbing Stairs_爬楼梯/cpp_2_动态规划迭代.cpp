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
};


int main() {
    Solution solution = Solution();
    cout << solution.climbStairs(42) << endl;
    return 0;
}
// Output: 433494437
