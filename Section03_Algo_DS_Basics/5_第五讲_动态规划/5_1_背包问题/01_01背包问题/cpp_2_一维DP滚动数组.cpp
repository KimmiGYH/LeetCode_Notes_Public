#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010;

int n, m; // n 物品个数、m 背包容量
int v[N], w[N]; // v 体积、w 价值
int f[N];

int main()
{
    cin >> n >> m;

    for (int i = 1; i <= n; i++)  cin >> v[i] >> w[i];

    for (int i = 1; i <= n; i++)
        for (int j = m; j >= v[i]; j--)
            f[j] = max(f[j], f[j - v[i]] + w[i]);
    
    cout << f[m] << endl;

    return 0;
}