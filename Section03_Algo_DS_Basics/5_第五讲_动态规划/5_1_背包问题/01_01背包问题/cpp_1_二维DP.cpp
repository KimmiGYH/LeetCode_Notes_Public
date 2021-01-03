#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010;

int n, m; // n 物品个数、m 背包容量
int v[N], w[N]; // v 体积、w 价值
int f[N][N]; // f[i][j] 所有的状态，f[0][0] 默认为 0

int main()
{
    cin >> n >> m;

    for (int i = 1; i <= n; i++)  cin >> v[i] >> w[i];

    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= m; j++)
        {
            f[i][j] = f[i - 1][j]; // 左边
            if (j >= v[i])  f[i][j] = max(f[i][j], f[i - 1][j - v[i]] + w[i]);
        }
    
    cout << f[n][m] << endl;

    return 0;
}