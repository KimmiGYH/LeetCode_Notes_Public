# 完全背包问题



### 写法一：二维DP完全背包

```cpp
/*
1. 【01背包】：  f[i][j] = max(f[i - 1][j], f[i - 1][j - v] + w);
2. 【完全背包】：f[i][j] = max(f[i - 1][j], f[i][j - v] + w);
*/

#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010;

int n, m;
int v[N], w[N];
int f[N][N];

int main()
{
    cin >> n >> m;
    
    for (int i = 1; i <= n; i++) cin >> v[i] >> w[i];
    
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            f[i][j] = f[i - 1][j];
            if (j >= v[i])  f[i][j] = max(f[i][j], f[i][j - v[i]] + w[i]);
        }
    cout << f[n][m] << endl;
    
    return 0;
}
```



### 写法二：一维DP完全背包

```cpp
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010;

int n, m;
int v[N], w[N];
int f[N];

int main()
{
    cin >> n >> m;
    
    for (int i = 1; i <= n; i++) cin >> v[i] >> w[i];
    
    for (int i = 1; i <= n; i++)
        for (int j = v[i]; j <= m; j++)
            f[j] = max(f[j], f[j - v[i]] + w[i]);
    cout << f[m] << endl;
    
    return 0;
}
```



