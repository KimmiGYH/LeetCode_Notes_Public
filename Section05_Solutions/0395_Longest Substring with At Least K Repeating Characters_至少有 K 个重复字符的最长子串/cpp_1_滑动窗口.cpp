class Solution {
public:
    int k;
    unordered_map<char, int> cnt;
    
    void add (char c, int& tot, int& sum) {
        if (!cnt[c]) tot++;
        cnt[c]++;
        if (cnt[c] == k) sum++;
    }
    
    void del(char c, int& tot, int& sum) {
        if (cnt[c] == k) sum--;
        cnt[c]--;
        if (!cnt[c]) tot--;
    }
    
    int longestSubstring(string s, int _k) {
        k = _k;
        int res = 0;
        for (int p = 1; p <= 26; p++) {
            cnt.clear();
            for (int i = 0, j = 0, tot = 0, sum = 0; j < s.size(); j++) {
                add(s[j], tot, sum);
                while (tot > p)
                    del(s[i++], tot, sum);
                if (tot == sum)
                    res = max(res, j - i + 1);
            }
        }
        return res;
    }
};
/*
Input: "bbaaacbd" 3
Output:3

tot = 1, sum = 1
p=1, i=2, j=4 时满足
*/