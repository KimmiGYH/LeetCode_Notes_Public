# 01背包

![solve_01背包.png](https://cdn.acwing.com/media/article/image/2021/01/11/41956_643212d453-solve_01背包.png) 

```
【分析】

f[i][j] 表示只看前 i 个物品，总体积是 j 的情况下，总价值最大是多少。

result = max(f[n][0~V])

f[i][j];

1. 不选第 i 个物品，f[i][j] = f[i - 1][j];
2. 选第 i 个物品，  f[i][j] = f[i - 1][j - v[i]];

f[i][j] = max{1, 2};

f[0][0] = 0;

```

## 写法一：01背包 二维DP (朴素写法)

```cpp
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

```

## 写法二：01背包 一维DP (优化写法)

```cpp
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

```
