class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;

    void backtracking(vector<int>& candidates, int& target, int startIndex, int sum, vector<bool> used) {
        if (sum == target) {
            res.push_back(path);
            return;
        }
        for (int i = startIndex; i < candidates.size() && candidates[i] + sum <= target; i++) {
            // used[i - 1] == true，说明同一树枝candidates[i - 1]使用过
            // used[i - 1] == false，说明同一树层candidates[i - 1]使用过。因为同一树层，used[i - 1] == false 才能表示，当前取的 candidates[i] 从 candidates[i - 1] 回溯而来的
            // 要对同一树层使用过的元素进行跳过
            if (i && candidates[i] == candidates[i-1] && used[i-1] == false)
                continue;
            sum += candidates[i];
            path.push_back(candidates[i]);
            used[i] = true;
            backtracking(candidates, target, i + 1, sum, used);
            used[i] = false;
            path.pop_back();
            sum -= candidates[i];
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<bool> used(candidates.size(), false);
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, target, 0, 0, used);
        return res;
    }
};
/**
[1,1,2,5,6,7,10]
[1,2,2,2,5]
*/