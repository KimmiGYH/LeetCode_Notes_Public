#include <iostream>
#include <vector>
using namespace std;

//需要：表示每个位置数组int[]、下标 u、记录用过的数的布尔数组used[]
class Solution {
public:

    vector<int> path;
    vector<bool> used;
    vector<vector<int>> res;

    vector<vector<int>> permute(vector<int>& nums) {
        int len = nums.size();
        path = vector<int>(len);
        used = vector<bool>(len, false);

        dfs(nums, 0);
        
        return res;
    }

    void dfs(vector<int>& nums, int u) {
        if (u == nums.size()) {
            res.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (used[i] == false) {
                path[u] = nums[i];
                used[i] = true;
                dfs(nums, u + 1); //递归下一层
                used[i] = false;
            }
        }
    }
};