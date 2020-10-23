#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size();
        int l = p.size();
        vector<int> res;
        vector<int> vp(26, 0);
        vector<int> vs(26, 0);
        for (char ch : p) ++vp[ch - 'a'];
        for (int i = 0; i < n; ++i) {
            ++vs[s[i] - 'a'];
            if (i >= l)  --vs[s[i-l] - 'a'];
            if (vs == vp)  res.push_back(i + 1 - l);
        }
        return res;
    }
};