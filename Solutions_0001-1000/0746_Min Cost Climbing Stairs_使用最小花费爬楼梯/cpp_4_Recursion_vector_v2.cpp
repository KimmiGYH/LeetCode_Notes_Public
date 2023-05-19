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
        return min(helper(cost, memo, n - 1), helper(cost, memo, n - 2));        
    }
    
    int helper(vector<int>& cost, vector<int>& memo, int i) {
        if (i < 0) return 0;
        if (memo[i] > 0) return memo[i];
        return memo[i] = min(helper(cost, memo, i - 1), helper(cost, memo, i - 2)) + cost[i];
    }
};