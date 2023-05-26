class Solution {
public:
    string reverseLeftWords(string s, int k) {
        int n = s.length();
        s.resize(n + k);
        for(int i = 0, j = n; i < k;)
            s[j ++] = s[i ++];
        for (int i = 0, j = k; j < s.length();)
            s[i ++] = s[j ++];
        s.erase(s.begin() + n, s.end());
        return s;
    }
};