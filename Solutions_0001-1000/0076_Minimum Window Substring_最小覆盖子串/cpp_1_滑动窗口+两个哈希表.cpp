class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> hashS, hashT;
        for (char& c : t)
            hashT[c] ++;
        string res;
        int cnt = 0; //有效字符的数量
        for (int i = 0, j = 0; i < s.length(); i++) {
            hashS[s[i]] ++; //这步没写
            if (hashS[s[i]] <= hashT[s[i]])
                cnt ++;
            while (hashS[s[j]] > hashT[s[j]])
                hashS[s[j ++]] --;
            if (cnt == t.size()) {
                if (res.empty() || res.size() > i - j + 1)
                    res = s.substr(j, i - j + 1);
            }
        }
        return res;
    }
};

// ----------------------------------------------------
// 以前的
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> hs, ht;
        for (auto c : t)  ht[c]++;

        string res = "";
        int cnt = 0; // 统计有效字符的数量
        for (int i = 0, j = 0; i < s.size(); i++) {
            hs[s[i]]++;
            if (ht[s[i]] >= hs[s[i]])  cnt++;

            // ht[s[j]] < hs[s[j]]; 说明这个s[j]是多余的
            while (ht[s[j]] < hs[s[j]])  hs[s[j++]]--;

            if (cnt == t.size()) {
                if (res.empty() || res.size() > i - j + 1)
                    res = s.substr(j, i - j + 1);
            }
        }
        return res;
    }
};