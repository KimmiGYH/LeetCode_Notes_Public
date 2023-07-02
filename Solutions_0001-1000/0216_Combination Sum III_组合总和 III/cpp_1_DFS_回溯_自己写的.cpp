class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;

    void backtracking(int& k, int& n, int startIndex) {
        if (path.size() == k) {
            if (accumulate(path.begin(), path.end(), 0) == n) {
                res.push_back(path);
                return;
            }
            return;
        }
        for (int i = startIndex; i <= 9 + 1 - (k - path.size()); i++) {
            path.push_back(i);
            backtracking(k, n, i + 1);
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        backtracking(k, n, 1);
        return res;
    }
};