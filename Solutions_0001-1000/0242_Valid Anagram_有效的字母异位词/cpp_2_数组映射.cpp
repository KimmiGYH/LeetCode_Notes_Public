class Solution {
public:
    bool isAnagram(string s, string t) {
        int hash[26] = {0}; //初始化数组
        for (char& c : s) hash[c-'a']++;
        for (char& c : t) hash[c-'a']--;
        for (int i = 0; i < 25; i++)
            if (hash[i] != 0)
                return false;
        return true;
    }
};