#include <iostream>
#include <cstdio>

using namespace std;

const int N = 10;

int n;
int path[N];
bool st[N]; // true表示这个点已被用过

void dfs(int u)
{
    if (u == n) //说明所有位置都填满了
    {
        for (int i = 0; i < n; i++) printf("%d ", path[i]);
        puts("");
        return;
    }
    
    for (int i = 1; i <= n; i++)
        if (!st[i])
        {
            path[u] = i;
            st[i] = true;
            dfs(u + 1);
            st[i] = false;
        }
}

int main()
{
    cin >> n;
    dfs(0);
    
    return 0;
}

/*
输入：3‘
输出：
1 2 3
1 3 2
2 1 3
2 3 1
3 1 2
3 2 1
*/