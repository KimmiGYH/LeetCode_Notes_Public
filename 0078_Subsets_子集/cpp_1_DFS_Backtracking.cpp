#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> path;

        for (int k = 0; k <= nums.size(); ++k)
            dfs(nums, k, 0, path, ans);
        return ans;
    }

private:
    void dfs(const vector<int>& nums, int n, int u, vector<int>& path, vector<vector<int>>& ans) {
        if (n == path.size()) {
            ans.push_back(path);
            return;
        }
        for (int i = u; i < nums.size(); ++i) {
            path.push_back(nums[i]);
            dfs(nums, n, i + 1, path, ans);
            path.pop_back();
        }
    }
};