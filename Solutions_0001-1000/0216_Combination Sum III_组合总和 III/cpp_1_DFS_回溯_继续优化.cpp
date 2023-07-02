class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;

    void backtracking(int& k, int& n, int startIndex, int sum) {
        if (sum > n) return; //剪枝优化2
        if (path.size() == k) {
            if (sum == n) {
                res.push_back(path);
                return;
            }
            return;
        }
        for (int i = startIndex; i <= 9 + 1 - (k - path.size()); i++) { //剪枝优化1
            sum += i;
            path.push_back(i);
            backtracking(k, n, i + 1, sum);
            path.pop_back();
            sum -= i;
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        backtracking(k, n, 1, 0);
        return res;
    }
};