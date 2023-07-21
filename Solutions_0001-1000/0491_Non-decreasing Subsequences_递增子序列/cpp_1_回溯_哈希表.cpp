class Solution {
public:
    vector<int> path;
    vector<vector<int>> res;

    void backtracking(vector<int>& nums, int startIndex) {
        if (path.size() >= 2) {
            res.push_back(path);
        }
        unordered_set<int> S;
        for (int i = startIndex; i < nums.size(); i++) {
            if (S.count(nums[i]))
                continue;
            S.insert(nums[i]);
            if (path.empty() || nums[i] >= path.back()) {
                path.push_back(nums[i]);
                backtracking(nums, i + 1);
                path.pop_back();
            }
        }
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        backtracking(nums, 0);
        return res;
    }
};