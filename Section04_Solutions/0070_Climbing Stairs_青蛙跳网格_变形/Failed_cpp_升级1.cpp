/*升级版1）一次最多跳m格，一共有n格，问方法数*/

/* 思路：
f(n) = f(n-1) + f(n-2) + f(n-3) + ... + f(n-m)
f(n-1) = f(n-2) + f(n-3) + ... + f(n-m)
f(n) = 2*f(n-1)
*/
#include <iostream>
using namespace std;

class Solution {
public:
    int climbStairs(int num) {
        int ret = 1;
        for (int i = 2; i < num+1; i++)
            ret = 2 * ret;
        return ret;
    }
};

int main() {
    Solution solution = Solution();
    cout << solution.climbStairs(3) << endl;
    return 0;
}