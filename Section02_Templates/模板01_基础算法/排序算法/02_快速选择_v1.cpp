// 时间复杂度: 2n
#include <iostream>

using namespace std;

const int N = 10010;

int n, k;
int q[N];

int quick_sort(int l, int r, int k)
{
    if (l == r) return q[l];

    int i = l - 1, j = r + 1, x = q[l + r >> 1];
    while (i < j)
    {
        while (q[++i] < x);
        while (q[--j] > x);
        if (i < j) swap(q[i], q[j]);
    }

    int sl = j - l + 1;
    if (k <= sl) return quick_sort(l, j, k);
    return quick_sort(j + 1, r, k - sl);
}


int main()
{
    cin >> n >> k;

    for (int i = 0; i < n; i++)
        cin >> q[i];
    
    cout << quick_sort(0, n-1, k) << endl;

    return 0;
}

/*Output:
Input:
n=5 k=3
2 4 1 5 3

Output: 3
*/

/* 相关例题：
0215_Kth Largest Element in an Array_数组中的第K个最大元素
*/