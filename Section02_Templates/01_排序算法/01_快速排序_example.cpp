#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e6 + 10;

int n;
int q[N];

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

int main()
{
    // int l, r;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &q[i]);
    
    quick_sort(q, 0, n-1);

    for (int i = 0; i < n; i++) printf("%d ", q[i]);

    return 0;
}
/* Output:
Ex1:
6
3 2 1 5 6 4
1 2 3 4 5 6 

Ex2:
10
49 59 88 37 98 97 68 54 31 3
3 31 37 49 54 59 68 88 97 98 
*/