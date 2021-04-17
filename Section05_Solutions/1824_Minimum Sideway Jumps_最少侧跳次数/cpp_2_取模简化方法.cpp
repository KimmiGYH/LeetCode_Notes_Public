#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minSideJumps(vector<int>& obstacles) {
        int dp[3] = {1, 0, 1};
        
        for (auto& obs : obstacles) {
            if (obs != 0) //有障碍
                dp[obs - 1] = INT_MAX - 1;
            for (int i = 0; i < 3; i ++) {
                if (obs == i + 1) continue;
                dp[i] = min(dp[(i)], min(dp[(i + 1) % 3], dp[(i + 2) % 3]) + 1);
            }
        }
        
        int res = INT_MAX - 1;
        for (int i = 0; i < 3; i ++)
            res = min(res, dp[i]);
        return res;
    }
};