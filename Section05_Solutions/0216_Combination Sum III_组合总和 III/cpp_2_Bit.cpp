#include <iostream>
#include <vector>

using namespace std;

// dfs(start, k搜索多少个数, n总和是多少)
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;

        // 2^9, generate all combinations of [1...9]
        for (int i = 0; i < (1 << 9); ++i) {
            vector<int> path;
            int sum = 0;
            for (int j = 1; j <= 9; ++j)
                // & 一下，以确定第 j-1 位是不是 1
                if (i & (1 << (j - 1))) {
                    sum += j;
                    path.push_back(j);
                }
            if (sum == n && path.size() == k)
                ans.push_back(path);
        }
        return ans;
    }
};