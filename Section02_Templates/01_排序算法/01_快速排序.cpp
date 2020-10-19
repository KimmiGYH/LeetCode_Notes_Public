#include <algorithm>
using namespace std;

void quick_sort(int q[], int l, int r)
{
    if (l >= r) return; // 如果没有数或者只有一个数的时候，就return

    int i = l - 1, j = r + 1, x = q[l + r >> 1];
    while (i < j)
    {
        do i ++ ; while (q[i] < x);
        do j -- ; while (q[j] > x);
        if (i < j) swap(q[i], q[j]);
        /* 手写swap函数：
        int t = q[i];
        q[i] = q[j];
        q[j] = t; */
    }
    quick_sort(q, l, j);
    quick_sort(q, j + 1, r);
}