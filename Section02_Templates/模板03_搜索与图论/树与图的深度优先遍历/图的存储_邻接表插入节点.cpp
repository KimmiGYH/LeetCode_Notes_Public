#include <iostream>

using namespace std;

const int N = 100010;

// head 表示头节点的下标
// e[i] 表示节点 i 的值
// ne[i] 表示节点 i 的 next 指针是多少
// idx 存储当前已经用到了哪个点
int head, e[N], ne[N], idx;

// 初始化
void init()
{
    head = -1;
    idx = 0;
}

// 将 x 插到头节点
void add_to_head(int x)
{
    e[idx] = x;
    ne[idx] = head; //插入到之前头节点的前面 / 让 head 的地址值存入指针域
    head = idx;
    idx ++;
}

// 将 x 插到下标是 k 的点的后面
void add(int k, int x)
{
    e[idx] = x;
    ne[idx] = ne[k];
    ne[k] = idx;
    idx ++;
}

// 将下标是 k 的点后面的点删掉
void remove(int k)
{
    ne[k] = ne[ne[k]];
}

int main()
{
    
}
