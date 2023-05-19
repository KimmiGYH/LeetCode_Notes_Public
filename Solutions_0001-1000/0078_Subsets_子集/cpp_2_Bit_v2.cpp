#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        for (int i = 0; i < 1 << n; i++) {
            vector<int> path;
            for (int j = 0; j < n; j++)
                // 先把第 j 位移到最后一位，再 & 1，看 i 的第 j 位 是 1 还是 0?
                if (i >> j & 1)
                    path.push_back(nums[j]);
            res.push_back(path);
        }
        return res;
    }
};