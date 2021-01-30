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
        unordered_map<string, int> hash;
        for (string str : strs) {
            string temp = str;
            sort(temp.begin(), temp.end());
            if (!hash.count(temp)) {
                hash[temp] = res.size();
                res.push_back({});
            }
            res[hash[temp]].push_back(str);
        }
        return res;
    }
};