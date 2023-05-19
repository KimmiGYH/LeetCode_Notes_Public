/*升级版1）一次最多跳m格，一共有n格，问方法数*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int climbStairs(int n, int m) {
        vector<int> f(n+1, 0);
        f[0] = 1;
        for (int i = 1; i <= n; ++i) {
            int cur = 0;
            for (int j = 1; j <= m; ++j) {
                if (j > i) break;
                cur += f[i-j];
            }
            f[i] = cur;
        }
        return f[n];    
    }
};


int main() {
    Solution solution = Solution();
    cout << solution.climbStairs(5, 3) << endl;
    return 0;
}

// Output: 13
/*
1 1 1 1 1
1 1 1 2
1 1 2 1
1 2 1 1
2 1 1 1
1 2 2
2 1 2
2 2 1
1 1 3
1 3 1
3 1 1
1 4 ->排除
4 1 ->排除
2 3
3 2
5   ->排除
*/