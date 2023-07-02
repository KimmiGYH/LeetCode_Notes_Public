#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;

    void dfs(int n, int k, int start) {
        if (!k) {
            res.push_back(path);
            return;
        }
        for (int i = start; i <= n; i++) {
            path.push_back(i);
            dfs(n, k - 1, i + 1);
            path.pop_back();
        }
    }

        vector<vector<int>> combine(int n, int k) {
        // k 当前还可以选几个数
        dfs(n, k, 1);
        return res;
    }
};

// --------- 2023年7月1日 另种写法----------

class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;

    void backtracking(int& n, int& k, int startIndex) {
        if (path.size() == k) {
            res.push_back(path);
            return;
        }
        for (int i = startIndex; i <= n; i++) {
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