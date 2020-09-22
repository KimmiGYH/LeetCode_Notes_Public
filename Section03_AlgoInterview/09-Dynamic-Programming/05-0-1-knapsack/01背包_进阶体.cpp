#include <iostream>
#include <algorithm>
using namespace std;

int dp[35][205];
int w[35], c[35];

int main() {
    int m, n;
    cin >> m >> n;

    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> c[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (j < w[i])
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i]] + c[i]);
        }
    }

    // 输出 dp 表看变化
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

/* Input:
10 4
2 1
3 3
4 5
7 9

Output:
0 0 0 0 0 0 0 0 0 0 0
0 0 1 1 1 1 1 1 1 1 1
0 0 1 3 3 4 4 4 4 4 4
0 0 1 3 5 5 6 8 8 9 9
0 0 1 3 5 5 6 9 9 10 12
*/