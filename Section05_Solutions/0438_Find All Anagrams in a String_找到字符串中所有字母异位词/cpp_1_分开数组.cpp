#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

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