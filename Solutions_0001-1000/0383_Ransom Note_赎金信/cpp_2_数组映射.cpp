class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> cnt(26, 0);
        for (int i = 0; i < magazine.length(); ++i)
            cnt[magazine[i] - 'a'] ++;
        for (int i = 0; i < ransomNote.length(); ++i) {
            if (cnt[ransomNote[i] - 'a'] == 0) return false;
            cnt[ransomNote[i] - 'a'] --;
        }
        return true;
    }
};
// ----------------

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int hash[26] = {0};
        for (char& c : magazine) hash[c-'a']++;
        for (char& c : ransomNote) hash[c-'a']--;
        for (char& c : ransomNote)
            if (hash[c-'a'] < 0)
                return false;
        return true;
    }
};