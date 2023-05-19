class Solution {
    using ULL = unsigned long long;
    const ULL P = 131;
public:
    ULL get(vector<ULL>& h, vector<ULL>& p, int i, int j) {
        return h[j] - h[i-1] * p[j - i + 1];
    }
    
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if (words.empty()) return res;
        int n = s.length(), m = words.size(), w = words[0].size();
        s= ' ' + s;
        vector<ULL> h(n + 1);
        vector<ULL> p(n + 1);
        // 1. 字符串哈希 -> s
        p[0] = 1;
        for (int i = 1; i <= n; i++) {
            p[i] = p[i-1] * P;
            h[i] = h[i-1] * P + (s[i] - 'a');
        }
        // 2. 字符串哈希 -> words
        unordered_map<ULL, int> tot;
        for(string& word : words) {
            ULL hash = 0;
            for (char& c : word)
                hash = hash * P + (c - 'a');
            tot[hash] ++;
        }
        
        for (int i = 1; i <= w; i++) {
            unordered_map<ULL, int> window;
            int satisfy = 0;
            for (int j = i; j + w <= n + 1; j += w) {
                if (j >= i + m * w) {
                    ULL cur = get(h, p, j - m * w, j - (m - 1) * w - 1);
                    window[cur]--;
                    if (window[cur] < tot[cur]) satisfy--;
                }
                ULL cur = get(h, p, j, j + w - 1);
                window[cur]++;
                if (window[cur] <= tot[cur]) satisfy++;
                if (satisfy == m)
                    res.push_back(j - (m - 1) * w - 1);
            }
        }
        return res;
        
    }
};