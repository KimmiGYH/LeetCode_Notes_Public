#include <iostream>
#include <stack>
#include <vector>
using namespace std;


class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        vector<int> stk;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            while(!stk.empty() && nums[i] < stk.back() && (n - i) + stk.size() > k)
                stk.pop_back();
            if (stk.size() < k) 
                stk.push_back(nums[i]);
        }
        return stk;
    }
};