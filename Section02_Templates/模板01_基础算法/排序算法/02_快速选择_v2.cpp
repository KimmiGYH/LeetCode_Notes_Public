// LeetCode 215. 数组中的第K个最大元素 【数组中的第k个最小元素】

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
        do i++; while (q[i] < x);
        do j--; while (q[j] > x);
        if (i < j) swap(q[i], q[j]);
    }

    if (k <= j) return quick_sort(l, j, k);
    else return quick_sort(j + 1, r, k - j - 1);

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
5 3
2 4 1 5 3

Output: 3
*/