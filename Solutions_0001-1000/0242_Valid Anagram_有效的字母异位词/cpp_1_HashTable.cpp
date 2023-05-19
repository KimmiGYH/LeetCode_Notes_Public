#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> hs, ht;
        for (auto c : s)  hs[c]++;
        for (auto c : t)  ht[c]++;
        return hs == ht;
    }
};

