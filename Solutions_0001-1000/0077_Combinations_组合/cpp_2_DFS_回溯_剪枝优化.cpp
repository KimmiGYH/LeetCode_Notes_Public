class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;

    void backtracking(int& n, int& k, int startIndex) {
        if (path.size() == k) {
            res.push_back(path);
            return;
        }
        for (int i = startIndex; i <= n + 1 - (k - path.size()); i++) { //优化
            path.push_back(i);
            backtracking(n, k, i + 1);
            path.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        backtracking(n, k, 1);
        return res;
    }
};