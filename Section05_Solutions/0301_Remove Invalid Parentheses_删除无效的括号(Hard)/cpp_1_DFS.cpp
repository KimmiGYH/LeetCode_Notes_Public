#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> ans;

    vector<string> removeInvalidParentheses(string s) {
        // l 删除多少个左括号（即左括号数量减去右括号数量）， r 删除多少个右括号
        int l = 0, r = 0;
        for (auto c : s)
            if (c == '(')  l++;
            else if (c == ')') {
                if (l == 0)  r++;
                else l--;
            }
        
        dfs(s, 0, "", 0, l, r);
        return ans;
    }

    // s - 字符串, u - 枚举到哪个字符, path - 当前删完之后剩余的字符串,
    // cnt - 当前左括号减去右括号的数量
    // l - 当前可以删掉多少左括号, r - 当前可以删掉多少右括号
    void dfs(string& s, int u, string path, int cnt, int l, int r) {
        if (u == s.size()) { // 搜到字符串的结尾
            if (!cnt)  ans.push_back(path);
            return;
        }

        // 如果当前字符既不是左括号，又不是右括号
        if (s[u] != '(' && s[u] != ')')
            dfs(s, u + 1, path + s[u], cnt, l, r);
        
        else if (s[u] == '(') {
            int k = u;
            // 看当前有多少个连续的左括号
            while (k < s.size() && s[k] == '(')  k++;
            l -= k - u;  // 把 k-u 个左括号都删掉
            //  枚举一下当前到底要删掉多少个左括号，从 k-u 开始枚举
            for (int i = k - u; i >= 0; i--) {
                if (l >= 0)  dfs(s, k, path, cnt, l, r);
                path += '(';
                cnt++, l++;
            }
        } else if (s[u] == ')') {
            int k = u;
            while (k < s.size() && s[k] == ')')  k++;
            r -= k - u;
            for (int i = k - u; i >= 0; i--) {
                if (cnt >= 0 && r >= 0)  dfs(s, k, path, cnt, l, r);
                path += ')';
                cnt--; r++;
            }
        }
    }
};

int main() {
    string s = ")())(";
    vector<string> res = Solution().removeInvalidParentheses(s);
    for (auto iter = res.begin(); iter != res.end(); iter++) {
        cout << *iter << " " ;
    }
    cout <<  endl;
    return 0;
}

// Output: () 