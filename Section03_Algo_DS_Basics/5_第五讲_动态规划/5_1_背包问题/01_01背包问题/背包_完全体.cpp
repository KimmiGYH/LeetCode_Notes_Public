#include <iostream>
#include <algorithm>
using namespace std;

int w[35], c[35], dp[205];
int main() {
    int m, n;
    cin >> m >> n;
    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> c[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = m; j >= 1; j--) { // 递推的时候要从后往前推
            if (j >= w[i]) // 滚动数组
                dp[j] = max(dp[j], dp[j-w[i]]+c[i]);
        }
        for (int k = 0; k <= m; k++) {
            cout << dp[k] << " ";
        }
        cout << endl;
    }
    cout << dp[m];
    return 0;
}

/* Input:
10 4
2 1
3 3
4 5
7 9

Output:
0 0 1 1 1 1 1 1 1 1 1
0 0 1 3 3 4 4 4 4 4 4
0 0 1 3 5 5 6 8 8 9 9
0 0 1 3 5 5 6 9 9 10 12
*/