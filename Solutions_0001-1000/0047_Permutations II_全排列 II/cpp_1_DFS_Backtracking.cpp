#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:

    vector<vector<int>> res;
    vector<int> path;
    vector<bool> used;

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // 排序
        int len = nums.size();
        path = vector<int>(len);
        used = vector<bool>(len);
        
        dfs(nums, 0);
        return res;
    }

    void dfs(vector<int>&nums, int u) {
        if (u == nums.size()) {
            res.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (!used[i]) {
                // 如果不是第一个没有被用过的数的话 就continue
                // 注意:首先 i 要大于 0，因为如果 i = 0 的话，前面肯定没有数了
                if (i && nums[i - 1] == nums[i] && !used[i - 1])  continue;
                // 否则就可以用这个数
                used[i] = true;
                path[u] = nums[i];
                dfs(nums, u + 1);
                used[i] = false;
            }
        }
    }
};