#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> hash;
        for (string& str : strs) {
            vector<int> cnt(26);
            string temp;
            for (char c : str) ++cnt[c - 'a'];
            for (int i = 0; i < 26; ++i) {
                if (cnt[i] == 0) continue;
                // temp += string(1, i + 'a'); //反例 ["ddddddddddg","dgggggggggg"], temp得到的都是 dg，不能区分
                temp += string(1, i + 'a') + to_string(cnt[i]);
                cout << temp << " ";
            }
            hash[temp].push_back(str);
        }
        for (auto& item : hash) {
            res.push_back(item.second);
        }
        return res;
    }
};