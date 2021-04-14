#include <iostream>
#include <cstdio>

using namespace std;

const int N = 10;

int n;
char g[N][N];
bool col[N], dg[N * 2], udg[N * 2];

void dfs(int u)
{
    if (u == n)
    {
        for (int i = 0; i < n; i ++)  puts(g[i]);
        puts("");
        return;
    }

    for (int i = 0; i < n; i ++)
        if (!col[i] && !dg[u + i] && !udg[u - i + n])
        {
            col[i] = dg[u + i] = udg[u - i + n] = true;
            g[u][i] = 'Q';
            dfs(u + 1);
            g[u][i] = '.';
            col[i] = dg[u + i] = udg[u - i + n] = false;
        }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i ++)
        for (int j = 0; j < n; j ++)
            g[i][j] = '.';

    dfs(0);

    return 0;
}

/*
输入：4
输出：
.Q..
...Q
Q...
..Q.

..Q.
Q...
...Q
.Q..
*/