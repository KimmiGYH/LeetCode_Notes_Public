class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;

    void backtracking(vector<int>& candidates, int& target, int sum, int startIndex) {
        if (sum == target) {
            res.push_back(path);
            return;
        }
        // 如果 sum + candidates[i] > target 就终止遍历
        for (int i = startIndex; i < candidates.size() && sum + candidates[i] <= target; i++) {
            path.push_back(candidates[i]);
            sum += candidates[i];
            backtracking(candidates, target, sum, i);
            sum -= candidates[i];
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end()); //需要排序！
        backtracking(candidates, target, 0, 0);
        return res;
    }
};