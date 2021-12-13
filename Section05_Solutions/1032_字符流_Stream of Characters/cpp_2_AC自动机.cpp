const int N = 1e5;
int tr[N][26], cnt[N], idx;
int q[N], ne[N];

class StreamChecker {
public:
    void insert(string& word) {
        int p = 0;
        for (auto c : word) {
            int t = c - 'a';
            if (!tr[p][t])  tr[p][t] = ++ idx;
            p = tr[p][t];
        }
        cnt[p] ++;
    }
    
    void build() {
        int hh = 0, tt = -1;
        for (int i = 0; i < 26; i++)
            if (tr[0][i])
                q[ ++ tt] = tr[0][i];
        
        while (hh <= tt) {
            int t = q[hh ++];
            for (int i = 0; i < 26; i++) {
                int p = tr[t][i];
                if (!p) tr[t][i] = tr[ne[t]][i];
                else {
                    ne[p] = tr[ne[t]][i];
                    cnt[p] = cnt[p] | cnt[ne[p]]; //不太懂呢
                    q[ ++ tt] = p;
                }
            }
        }
    }
    
    StreamChecker(vector<string>& words) {
        memset(tr, 0, sizeof tr);
        memset(cnt, 0, sizeof cnt);
        memset(ne, 0, sizeof ne);
        idx = 0;
        
        for (auto& word : words) insert(word);
        
        build();
    }
    
    int cur = 0;
    bool query(char letter) {
        cur = tr[cur][letter - 'a'];
        return cnt[cur];
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */