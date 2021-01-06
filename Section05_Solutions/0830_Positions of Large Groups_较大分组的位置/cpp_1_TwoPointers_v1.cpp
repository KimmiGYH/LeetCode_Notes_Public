#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        int n = s.size(), i = 0, j = 0;
        vector<vector<int>> res;
        while (i < n) {
            while (i < n && s[j] == s[i]) ++i;
            if (i - j >= 3) res.push_back({j, i - 1});
            j = i;
        }
        return res;
    }
};