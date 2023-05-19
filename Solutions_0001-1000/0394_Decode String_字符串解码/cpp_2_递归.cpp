class Solution {
public:
    string dfs(string& s, int& u) {
        string res;
        while (u < s.length() && s[u] != ']') {
            if (s[u] >= 'a' && s[u] <= 'z' || s[u] >= 'A' && s[u] <= 'Z')
                res += s[u++];
            else if (isdigit(s[u])) {
                int k = u;
                while (s[k] >= '0' && s[k] <= '9') k++;
                int times = stoi(s.substr(u, k - u));
                u = k + 1; //过滤左括号
                string str = dfs(s, u);
                u ++; //过滤右括号
                while (times--) res += str;
            }
        }
        return res;
    }
    
    string decodeString(string s) {
        int u = 0;
        return dfs(s, u);
    }
};