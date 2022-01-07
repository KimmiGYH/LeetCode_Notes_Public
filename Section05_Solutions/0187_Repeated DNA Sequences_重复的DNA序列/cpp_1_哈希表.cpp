class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> cnt;
        for (int i = 0; i + 10 <= s.size(); i++)
            cnt[s.substr(i, 10)]++;
        vector<string> res;
        for (auto [str, val] : cnt)
            if (val > 1)
                res.push_back(str);
        return res;
    }
};
// ----------------------------------------

class Solution {
    const int L = 10;
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans;
        unordered_map<string, int> cnt;
        int n = s.length();
        for (int i = 0; i <= n - L; ++i) {
            string sub = s.substr(i, L);
            if (++cnt[sub] == 2) {
                ans.push_back(sub);
            }
        }
        return ans;
    }
};
