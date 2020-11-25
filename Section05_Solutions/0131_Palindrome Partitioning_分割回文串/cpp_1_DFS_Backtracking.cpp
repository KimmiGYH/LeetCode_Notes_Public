#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<string>> res;
    vector<string> path;
    
    bool isPalindrome(const string& s, int i, int j) {
        while (i < j)
            if (s[i++] != s[j--])  return false;
        return true;
    }

    vector<vector<string>> partition(string s) {
        if (!s.size())  return res;
        dfs(s, 0);
        return res;
    }

    void dfs(string& s, int u) {
        if (u == s.size())  res.push_back(path);
        for (int i = u; i < s.size(); i++)
            if (isPalindrome(s, u, i)) {
                path.push_back(s.substr(u, i - u + 1));
                dfs(s, i + 1);
                path.pop_back();
            }
    }
};
// Output:[["a","a","b"],["aa","b"]]

int main() {
    vector<vector<string>> res = Solution().partition("aab");
    for (int i = 0; i < res.size(); i++)
        for (int j = 0; j < res[i].size(); j++)
            cout << res[i][j] << endl;
    return 0;
}