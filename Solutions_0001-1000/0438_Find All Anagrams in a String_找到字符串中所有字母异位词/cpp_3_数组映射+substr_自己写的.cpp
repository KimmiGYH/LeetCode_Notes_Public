class Solution {
public:
    bool check(string& s, string& p) {
        int hash[26] = {0};
        for (char& c : s) hash[c-'a']++;
        for (char& c : p) hash[c-'a']--;
        for (int i = 0; i < 26; i++) {
            if (hash[i] != 0)
                return false;
        }
        return true;
    }

    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        int k = p.length();
        for (int i = 0; i < s.length(); i++) {
            string ss = s.substr(i, k);
            if (check(ss, p))
                res.push_back(i);
        }
        return res;
    }
};