#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<bool>> f;
    vector<vector<string>> ans;
    vector<string> path;

    vector<vector<string>> partition(string s) {
        int n = s.size();
        // f[i,j] 表示从 i~j 这段是不是回文串
        f = vector<vector<bool>>(n, vector<bool>(n, 1));
        
        for (int l = 2; l <= n; ++l)
            for (int i = 0, j = i + l - 1; j < n; ++i, ++j)
                f[i][j] = s[i] == s[j] && f[i + 1][j - 1];
        dfs(s, 0);
        return ans;
    }

    void dfs(string& s, int u) {
        if (u == s.size())  ans.push_back(path);
        for (int j = u; j < s.size(); ++j)
            if (f[u][j]) {
                path.push_back(s.substr(u, j - u + 1));
                dfs(s, j + 1);
                path.pop_back();
            }
    }
};