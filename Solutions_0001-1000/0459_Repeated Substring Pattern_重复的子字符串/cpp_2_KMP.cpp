class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.length();
        s = ' ' + s;
        vector<int> nxt(n + 1);
        for (int i = 2, j = 0; i <= n; i++) {
            while (j && s[i] != s[j + 1])
                j = nxt[j];
            if (s[i] == s[j + 1])
                j ++;
            nxt[i] = j;
        }
        int t = n - nxt[n];
        return t != n && n % t == 0;
    }
};