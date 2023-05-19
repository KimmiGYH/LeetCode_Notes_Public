#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> memo(n + 1);
        return helper(cost, memo, n);        
    }
    
    int helper(vector<int>& cost, vector<int>& memo, int i) {
        if (i <= 1) return 0;
        if (memo[i] > 0) return memo[i];
        return memo[i] = min(helper(cost, memo, i - 1) + cost[i - 1], helper(cost, memo, i - 2) + cost[i - 2]);
    }
};