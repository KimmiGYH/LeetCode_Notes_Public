#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>

using namespace std;

class Knapsack01 {

private:
    vector<vector<int>> memo;
    // 用 [0...index] 的物品，填充容积为 c 的背包的最大价值
    int bestValue(const vector<int> &w, const vector<int> v, int index, int c) {
        if (index < 0 || c <= 0)
            return 0;
        
        if (memo[index][c] != -1)
            return memo[index][c];
        
        int res = bestValue(w, v, index - 1, c);
        if ( c >= w[index] )
            res = max(res, v[index] + bestValue(w, v, index - 1, c - w[index]));
        
        memo[index][c] = res;
        return res;
    }

public:
    int knapsack01(const vector<int> &w, const vector<int> &v, int C) {
        int n = w.size();
        return bestValue(w, v, n-1, C);
    }
}