#include <vector>

using namespace std;

class Solution {
public:    
    int minSideJumps(vector<int>& obstacles) {
        const int N = 5 * 10e5 + 10, INF = 1e8;
        int f[N][3];
        f[0][1] = 0, f[0][0] = f[0][2] = 1;
        
        const int n = obstacles.size() - 1;
        // dp[i][j]: minimum number of side jumps to arrive at position i and track j
        for (int i = 1; i <= n; i++)
            for (int j = 0; j < 3; j++) {
                f[i][j] = INF; // 先初始化为最大值，之后再去更新它
                if (obstacles[i] == j + 1) continue;
                
                // 枚举当前点的最短距离由哪个点来更新
                for (int k = 0; k < 3; k++) {
                    if (obstacles[i] == k + 1) continue;
                    int sidejump = 0;
                    if (k != j)  sidejump = 1; //如果不在同一条水平线上
                    f[i][j] = min(f[i][j], f[i - 1][k] + sidejump);
                }
            }
        return min(f[n][1], min(f[n][0], f[n][2]));
    }
};