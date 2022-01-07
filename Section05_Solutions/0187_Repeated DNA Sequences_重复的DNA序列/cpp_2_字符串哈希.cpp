class Solution {
    using ULL = unsigned long long;
    ULL P = 13331;
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.length(), L = 10;
        vector<string> res;
        vector<ULL> h(n + 1);
        vector<ULL> p(n + 1);
        
        p[0] = 1;
        for (int i = 1; i <= n; i++) {
            p[i] = p[i-1] * P;
            h[i] = h[i-1] * P + (s[i-1] - 'a');
        }
        
        unordered_map<ULL, int> map;
        for (int i = 1; i + L - 1 <= n; i++) {
            int j = i + L - 1;
            //O(1)得到子串哈希
            ULL hash = h[j] - h[i - 1] * p[j - i + 1];
            map[hash]++;
            if (map[hash] == 2) res.push_back(s.substr(i-1, L));
        }
        return res;
    }
};

// ----------------------------------------------------------
// 最后一部分也可以写成

        unordered_map<ULL, int> map;
        for (int i = 1; i + L - 1 <= n; i++) {
            int j = i + L - 1;
            ULL hash = h[j] - h[i - 1] * p[j - i + 1];
            
            if (++map[hash] == 2) res.push_back(s.substr(i-1, L)); //直接在前面写上++，即++map[hash]
        }
        return res;