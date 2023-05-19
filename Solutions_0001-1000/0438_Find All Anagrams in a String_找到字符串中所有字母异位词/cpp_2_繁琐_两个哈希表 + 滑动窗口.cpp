class Solution {
public:
    unordered_map<char, int> hs, hp;

    bool check(char& c) {
        if (hp.count(c) && hs[c] == hp[c])//判断字符是否在子串哈希表中出现且数量一样
            return true;
        return false;
    }

    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        for (char& c : p) hp[c]++;
        int tot = hp.size();
        for (int i = 0, j = 0, cnt = 0; i < s.length(); i++) {
            if (check(s[i])) cnt--; //若字符本来满足要求，再加入后，则不满足要求了
            hs[s[i]]++;
            if (check(s[i])) cnt++;

            while (i - j + 1 > p.length()) {
                if (check(s[j])) cnt--;
                hs[s[j]]--; //这里不能写j++ 因为下一行的j变了
                if (check(s[j])) cnt++;
                j++;
            }
            if (tot == cnt) res.push_back(j);
        }
        return res;
    }
};