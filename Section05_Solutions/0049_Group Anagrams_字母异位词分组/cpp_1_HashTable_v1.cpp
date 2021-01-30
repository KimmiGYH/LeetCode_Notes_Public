#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hash;
        for (auto& str : strs) {
            string temp = str;
            sort(temp.begin(), temp.end());
            hash[temp].push_back(str);
        }
        
        vector<vector<string>> res;
        for (auto& item : hash) res.push_back(item.second);
        
        return res;
    }
};