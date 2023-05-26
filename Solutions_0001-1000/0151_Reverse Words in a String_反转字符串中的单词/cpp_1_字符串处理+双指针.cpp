class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        int k = 0; //有效字符
        for (int i = 0; i < n; i++) {
            if (s[i] == ' ') continue;
            int j = i, t = k;
            while (j < n && s[j] != ' ')
                s[t ++] = s[j ++];
            reverse(s.begin() + k, s.begin() + t);
            s[t ++] = ' ';
            k = t, i = j;
        }
        if (k > 0) k--;
        s.erase(s.begin() + k, s.end());
        reverse(s.begin(), s.end());
        return s;
    }
};