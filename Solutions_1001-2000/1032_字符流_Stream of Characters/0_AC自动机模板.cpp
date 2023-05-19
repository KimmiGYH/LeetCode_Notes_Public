//求next的过程，S,P的下标均从1开始
next[0] = next[1] = 0;
for (int i = 2; i <= m; i++)
{
    int j = next[i-1];
    while (j && p[i] != p[j+1])  j = next[j];
    if (p[i] == p[j+1])  j++;
    next[i] = j;
}

*********************************************

while(hh <= tt)
{
    t = q[hh++]; //i-1对应t
    for (i = 0; i < 26; i++)//p[i]对应i
        c = tr[t, i]; //c是t节点的第i个儿子, c是t字母的下一个字母，t是i-1，则c为i
        j = next[t]; //t为i-1
        while (j && !tr[j, i])  j = next[j]; //判断j字母的下一个位置是否存在p[i]这个字母
        if (tr[j, i])  j = tr[j, i]; 
        next[c] = j;
}

*********************************************

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 10010, S = 55, M = 1000010;

int n, m;
int tr[N * S][26], cnt[N * S], idx;
char str[M];
int q[N * S], ne[N * S];


void insert() //和Trie的插入完全一样
{
    int p = 0; //从根节点开始
    for (int i = 0; str[i]; i++)
    {
        int t = str[i] - 'a'; //当前字母
        if (!tr[p][t])  tr[p][t] = ++ idx; //如果不存在，创建新的节点
        p = tr[p][t]; //这条路有了就直接走过去
    }
    cnt[p] ++; //以p结尾的单词数量加1
}


void build() //其实是个宽搜
{
    int hh = 0, tt = -1;
    for (int i = 0; i < 26; i++)
        if (tr[0][i]) //如果存在，加入队列
            q[ ++ tt] = tr[0][i];

    while (hh <= tt)
    {
        int t = q[hh ++ ];
        for (int i = 0; i < 26; i++)
        {
            // int c = tr[t][i]; //c对应i
            // if (!c) continue;
            // 【虽然是线性，但仍有空间继续优化常数】
            // int j = ne[t];
            // while (j && !tr[j][i]) j = ne[j]; //如果不存在，创建节点
            // if (tr[j][i])  j = tr[j][i];
            // ne[c] = j;
            // q[ ++ tt] = c;

            //【Trie图优化，跳过一次之后，就让节点一步到位指向根节点】
            int p = tr[t][i];
            //如果不存在，让它指向父节点的next指针对应儿子第i个位置
            if (!p)  tr[t][i] = tr[ne[t]][i];
            else //如果儿子存在，直接指向这个儿子
            {
                ne[p] = tr[ne[t]][i];
                q[ ++ tt] = p;
            }
        }
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T --)
    {
        memset(tr, 0, sizeof tr);
        memset(cnt, 0, sizeof cnt);
        memset(ne, 0, sizeof ne);
        idx = 0;

        scanf("%d", &n); //n表示所有单词数量
        for (int i = 0; i < n; i++)
        {
            scanf("%s", str);
            insert();
        }
        build();

        scanf("%s", str);

        int res = 0;
        for (int i = 0, j = 0; str[i]; i++) //j也从根节点传进来
        {
            int t = str[i] - 'a';
            // while (j && !tr[j][t])  j = ne[j]; //如果不存在，j往回走
            // if (tr[j][t])  j = tr[j][t]; //如果存在儿子，j就走过去
            // 以上这样就能找到 str[i]最靠下的节点

            j = tr[j][t];

            int p = j; //不仅遍历自己同时也要把j能够走到的节点全部遍历一遍
            while (p)
            {
                res += cnt[p];
                cnt[p] = 0;
                p = ne[p];
            }
        }

        printf("%d\n", res);
    }
    return 0;
}
// https://www.acwing.com/activity/content/code/content/1151665/
