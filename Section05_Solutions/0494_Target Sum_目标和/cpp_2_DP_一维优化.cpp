#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        unordered_map<int, int> dp;
        dp[0] = 1;
        for (int num : nums) {
            unordered_map<int, int> hash;
            for (auto a : dp) {
                int sum = a.first, cnt = a.second;
                hash[sum + num] += cnt;
                hash[sum - num] +=cnt;
            }
            dp = hash;
        }
        return dp[S];
    }
};