class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;

    void backtracking(vector<int>& candidates, int& target, int startIndex, int sum) {
        if (sum == target) {
            res.push_back(path);
            return;
        }
        for (int i = startIndex; i < candidates.size() && candidates[i] + sum <= target; i++) {
            // 要对同一树层使用过的元素进行跳过
            if (i > startIndex && candidates[i] == candidates[i-1]) //用 i > startIndex 来判断
                continue;
            sum += candidates[i];
            path.push_back(candidates[i]);
            backtracking(candidates, target, i + 1, sum);
            path.pop_back();
            sum -= candidates[i];
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, target, 0, 0);
        return res;
    }
};
/**
[1,1,2,5,6,7,10]
*/