#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        unordered_map<int, int> memo;
        return helper(cost, cost.size(), memo);
    }
    
    int helper(vector<int>& cost, int i, unordered_map<int, int>& memo) {
        if (memo.count(i)) return memo[i];
        if (i <= 1) return memo[i] = cost[i];
        return memo[i] = (i == cost.size() ? 0 : cost[i]) + min(helper(cost, i - 1, memo), helper(cost, i - 2, memo));
    }
};