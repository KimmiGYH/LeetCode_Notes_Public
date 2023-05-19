#include <vector>

using namespace std;

class Solution {
public:    
    int minSideJumps(vector<int>& obstacles) {
        const int N = 5 * 10e5 + 10, INF = 1e8;
        int f[N][4]; // 为了让 i, j 统一，准备4个赛道，空出第0赛道
        f[0][2] = 0, f[0][1] = f[0][3] = 1;
        
        const int n = obstacles.size() - 1;
        // dp[i][j]: minimum number of side jumps to arrive at position i and track j
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= 3; j++) {
                f[i][j] = INF; // 先初始化为最大值，之后再去更新它
                if (obstacles[i] == j) continue;
                
                // 枚举当前点的最短距离由哪个点来更新
                for (int k = 1; k <= 3; k++) {
                    if (obstacles[i] == k) continue;
                    int sidejump = 0;
                    if (k != j)  sidejump = 1; //如果不在同一条水平线上
                    f[i][j] = min(f[i][j], f[i - 1][k] + sidejump);
                }
            }
        // return min(f[n][1], min(f[n][2], f[n][3]));
        int res = INF;
        for (int j = 1; j <= 3; j ++)
            res = min(res, f[n][j]);
        return res;
    }
};