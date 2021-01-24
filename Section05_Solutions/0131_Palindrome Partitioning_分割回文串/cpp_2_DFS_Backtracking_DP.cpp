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
        f = vector<vector<bool>>(n, vector<bool>(n));
        // f[i,j] 表示从 i 到 j 这段是不是回文串
        for (int j = 0; j < n; j++) // 要保证算f[i,j]前 f[i+1, j-1]已经被算出来
            for (int i = 0; i <= j; i++)
                if (i == j) f[i][j] = true;
                else if (s[i] == s[j]) {
                    if (i + 1 > j - 1 || f[i + 1][j - 1]) //只有两个字符 or f[i+1][j-1]是回文串
                        f[i][j] = true;
                }
        dfs(s, 0);
        return ans;
    }

    void dfs(string& s, int u) { // u 表示当前搜到第几位
        if (u == s.size())  ans.push_back(path);
        for (int i = u; i < s.size(); i++)
            if (f[u][i]) { // 如果从 u 到 i 是回文串的话，那么下段可以成立
                path.push_back(s.substr(u, i - u + 1));
                dfs(s, i + 1); // 递归到下一层
                path.pop_back();
            }
    }
};
// Output:[["a","a","b"],["aa","b"]]