class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> cnt;
        for (char& c : magazine)
            cnt[c] ++;
        for (char& c : ransomNote) {
            if (!cnt[c]) return false;
            cnt[c]--;
        }
        return true;
    }
};

//------------自己写的---------------

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> hr, hm;
        for(char& c : ransomNote) hr[c]++;
        for(char& c : magazine) hm[c]++;
        for (char& c : ransomNote) {
            if (hr[c] > hm[c])
                return false;
        }
        return true;
    }
};