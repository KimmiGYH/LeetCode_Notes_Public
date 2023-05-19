class Solution {
    using ULL = unsigned long long;
    ULL P = 13331;
public:
    ULL get(vector<ULL> h, vector<ULL> p, string& s, int i, int j) {
        /* h[R]: 0 ~ R-1
           h[L]: 0 ~ L-1
           h[R] = h[L] * p[R-L]
        */
        if (i == 0) return h[j - 1];
        else return h[j - 1] - h[i - 1] * p[j - i];
    }
    
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if (words.empty()) return res;
        int n = s.length(), m = words.size(), w = words[0].size();
        vector<ULL> sh(n), wh(m);
        vector<ULL> p(n);
        unordered_map<ULL, int> tot;
        
        p[0] = 1, sh[0] = s[0] - 'a';
        for (int i = 1; i < n; i++) {
            p[i] = p[i-1] * P;
            sh[i] = sh[i-1] * P + (s[i] - 'a');
        }
        for (int i = 0; i < m; i++) {
            vector<ULL> tmp(w);
            tmp[0] = words[i][0] - 'a';
            for (int j = 1; j < w; j++)
                tmp[j] = tmp[j - 1] * P + (words[i][j] - 'a');
            wh.push_back(tmp.back());
        }
        
        for (ULL& word : wh) tot[word]++;
        
        for (int i = 0; i < w; i++) {
            unordered_map<ULL, int> window;
            int satisfy = 0;
            for (int j = i; j + w <= n; j += w) {
                if (j >= i + m * w) {
                    ULL word = get(sh, p, s, j - m*w, j - m*w + w);
                    window[word]--;
                    if (window[word] < tot[word]) satisfy--;
                }
                ULL word = get(sh, p, s, j, j + w);
                window[word]++;
                if (window[word] <= tot[word]) satisfy++;
                if (satisfy == m) res.push_back(j - m*w + w);
            }
        }
        return res;        
    }
};