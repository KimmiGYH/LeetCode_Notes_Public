// Enumerate numbers for positions

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Time: O(2^n)
    // Space: O(n)
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> path;
        dfs(0, path, res, nums);
        return res;
    }

    void dfs(int i, vector<int>& path, vector<vector<int>>& res, const vector<int>& nums) {
        if (i == nums.size()) {
            res.push_back(path);
            return;
        }
        
        // choose nums[i]
        path.push_back(nums[i]);
        dfs(i + 1, path, res, nums);
        path.pop_back(); // restore

        if (path.size() > 0 && path.back() == nums[i])
            return;
        
        // not choose nums[i], no need to restore
        dfs(i + 1, path, res, nums);
    }
};