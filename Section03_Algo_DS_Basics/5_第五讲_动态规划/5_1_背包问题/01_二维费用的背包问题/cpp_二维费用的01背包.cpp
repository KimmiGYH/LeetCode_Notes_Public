#include <iostream>
#include <algorithm>

using namespace std;

const int N = 110;

int n, V, M;
int f[N][N];

int main()
{
    cin >> n >> V >> M;
    
    for (int i = 0; i < n; i++)
    {
        int v, m, w;
        cin >> v >> m >> w;
        for (int j = V; j >= v; j--) // 体积
            for (int k = M; k >= m; k--) // 重量
                f[j][k] = max(f[j][k], f[j - v][k - m] + w);
    }
    cout << f[V][M] << endl;
    
    return 0;
}