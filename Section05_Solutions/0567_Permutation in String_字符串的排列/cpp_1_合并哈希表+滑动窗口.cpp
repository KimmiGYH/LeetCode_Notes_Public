class Solution {
public:
    bool checkInclusion(string p, string s) {
        unordered_map<char, int> hash;
        for (auto& c : p)  hash[c]++;
        int tot = hash.size();
        for (int i = 0, j = 0, satisfy = 0; j < s.size(); j++) {
            if (--hash[s[j]] == 0)  satisfy++;
            while (j - i + 1 > p.size()) {
                if (hash[s[i]] == 0)  satisfy--;
                hash[s[i++]]++;
            }
            if (satisfy == tot)  return true;
        }
        return false;
    }
};