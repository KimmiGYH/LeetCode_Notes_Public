#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        days.insert(days.begin(), 0);

        for (int i = 1; i <= n; ++i) {
            for (int j = i; j >= 1; --j) {
                if (days[i] - days[j] < 1)
                    dp[i] = min(dp[i], dp[j-1] + costs[0]);
                if (days[i] - days[j] < 7)
                    dp[i] = min(dp[i], dp[j-1] + costs[1]);
                if (days[i] - days[j] < 30)
                    dp[i] = min(dp[i], dp[j-1] + costs[2]);
                if (days[i] - days[j] >= 30)
                    break;
            }
        }
        return dp[n];
    }
};