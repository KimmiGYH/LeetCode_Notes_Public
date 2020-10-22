#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> hash;
        for (auto c: p)  hash[c]++;
        vector<int> res;
        int total = hash.size();
        for (int i = 0, j = 0, satisfied = 0; i < s.size(); i++) {
            if (--hash[s[i]] == 0)  satisfied++;

        }

    }
};