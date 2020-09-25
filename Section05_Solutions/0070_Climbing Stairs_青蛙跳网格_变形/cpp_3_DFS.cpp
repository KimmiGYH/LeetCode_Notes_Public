#include <iostream>
#include <string>
using namespace std;

int n, m;
long long cnt = 0;

void dfs(int step_climb, string ans, int left)
{
    if (m < step_climb  || left < 0)
    {
        return ;
    }
    if (m == step_climb && left == 0)
    {
        ans.erase(ans.begin());
        cout << ans << endl;
        cnt ++;
        return;
    }
    dfs(step_climb + 1, ans + "-1", left - 1);
    dfs(step_climb + 1, ans + "-2", left - 2);
    dfs(step_climb + 1, ans + "-3", left - 3);
}

int main()
{
    cin >> n >> m;
    dfs(0, "", n);
    cout << "In total there are " << cnt << " situations." << endl;
}