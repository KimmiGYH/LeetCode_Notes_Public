#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty())  return "";
        int n = s.length(), left = 0, len = 1;
        vector<vector<int>> valid(n, vector<int>(n, 1));
        for (int l = 2; l <= n; ++l)
            for (int i = 0, j = i + l - 1; j < n; ++i, ++j) {
                valid[i][j] = s[i] == s[j] && valid[i + 1][j - 1];
                if (valid[i][j] && len < j - i + 1) {
                    len = j - i + 1;
                    left = i;
                }
            }
        return s.substr(left, len);        
    }
};