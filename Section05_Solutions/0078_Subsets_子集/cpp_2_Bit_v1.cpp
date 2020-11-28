#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        for (int i = 0; i < 1 << n; ++i) {
            vector<int> path;
            for (int j = 0; j < n; ++j)
                // & 一下，以确定第 j 位是不是 1
                if (i & (1 << j))
                    path.push_back(nums[j]);
            res.push_back(path);
        }
        return res;
    }
};