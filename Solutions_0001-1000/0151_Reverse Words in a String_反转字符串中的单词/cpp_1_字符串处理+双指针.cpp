class Solution {
public:
    string reverseWords(string s) {
        int k = 0, n = s.length();
        for (int i = 0; i < n; i++) {
            if (s[i] == ' ') continue;
            int j = i, t = k;
            //s = "  hello world  "
            //s = "hellolo world  "
            //s = "hello o world  "
            //s = "olleh o world  "
            //s = "olleh worldld  "
            //s = "olleh world"
            while (j < n && s[j] != ' ')
                s[t ++] = s[j ++];
            reverse(s.begin() + k, s.begin() + t);
            s[t ++] = ' ';
            i = j, k = t;
        }
        if (k) s.erase(s.begin() + k - 1, s.end());
        reverse(s.begin(), s.end());
        return s;
    }
};