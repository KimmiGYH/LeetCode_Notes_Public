class Solution {
public:
    unordered_map<char, int> hashP, hashS;
    
    bool check(char c) {
        if (hashP.count(c) && hashP[c] == hashS[c])
            return true;
        return false;
    }
    
    bool findAnagrams(string p, string s) {
        for (char& c : p) hashP[c] ++;
        int tot = hashP.size();
        for (int i = 0, j = 0, satisfy = 0; j < s.size(); j++) {
            if (check(s[j])) satisfy--;
            hashS[s[j]]++;
            if (check(s[j])) satisfy++;
            
            if (j - i + 1 > p.size()) {
                if (check(s[i])) satisfy--;
                hashS[s[i]]--;
                if (check(s[i])) satisfy++;
                i++;
            }
            if (tot == satisfy) return true;
        }
        return false;
    }
};