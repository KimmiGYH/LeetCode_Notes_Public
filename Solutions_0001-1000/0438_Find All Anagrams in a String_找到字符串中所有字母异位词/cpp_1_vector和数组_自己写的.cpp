#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// vector
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size(), m = p.size();
        vector<int> res, vs(26), vp(26);
        for (char& c : p) ++vp[c - 'a'];
        for (int i = 0; i < n; ++i) {
            ++vs[s[i] - 'a'];
            if (i >= m) --vs[s[i-m] - 'a'];
            if (vs == vp) res.push_back(i - m + 1);
        }
        return res;
    }
};

// ------------------------------------------
// 数组映射
class Solution {
public:
    unordered_map<char, int> hs, hp;
    bool check (int hs[], int hp[]) {
        for (int i = 0; i < 26; i++)
            if (hs[i] != hp[i])
                return false;
        return true;
    }

    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        int hs[26] = {0}, hp[26] = {0};
        for (char& c : p) hp[c - 'a']++;
        for (int i = 0, j = 0; i < s.length(); i++) {
            hs[s[i] - 'a']++;
            while (i - j + 1 > p.length()) {
                hs[s[j] - 'a']--;
                j++;
            }
            if (check(hs, hp)) res.push_back(j);
        }
        return res;
    }
};
