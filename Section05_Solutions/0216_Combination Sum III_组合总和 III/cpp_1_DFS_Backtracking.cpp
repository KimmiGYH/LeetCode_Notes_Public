#include <iostream>
#include <vector>

using namespace std;

// dfs(start, n总和是多少, k搜索多少个数)
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;

    vector<vector<int>> combinationSum3(int k, int n) {
        dfs(1, n, k);
        return res;
    }

    void dfs(int start, int n, int k) {
        // 1) n = 0, k = 0
        if (!n) {
            if (!k) res.push_back(path);
            return;
        }
        // 2) n 不为 0，个数k 不为 0
        for (int i = start; i <= 9; i++) {
            if (n >= i) {
                path.push_back(i);
                dfs(i + 1, n - i, k - 1);
                path.pop_back();
            }
        }
        // 3) n 不为 0，个数k 为 0，当前已经没有数可选了
    }
};
// 时间复杂度：C(9, k) * k