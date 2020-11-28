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

    void dfs(int u, vector<int>& path, vector<vector<int>>& res, const vector<int>& nums) {
        res.push_back(path);

        for (int i = u; i < nums.size(); ++i) {
            // skip the same number at a certain depth
            if (i > u && nums[i] == nums[i - 1])
                continue;

            path.push_back(nums[i]);
            dfs(i + 1, path, res, nums);
            path.pop_back();
        }
    }
};