class Solution {
public:
    vector<int> path;
    vector<vector<int>> res;

    void backtracking(vector<int>& nums, vector<bool> used, int startIndex) {
        if (path.size() == nums.size()) {
            res.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (used[i] == true)
                continue;
            // if (i > startIndex && nums[i] == nums[i-1]) //错误写法
            //     continue;
            if (i && nums[i] == nums[i-1] && used[i-1] == false)
                continue;
            path.push_back(nums[i]);
            used[i] =  true;
            backtracking(nums, used, i + 1);
            used[i] = false;
            path.pop_back();
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<bool> used(nums.size(), false);
        backtracking(nums, used, 0);
        return res;
    }
};