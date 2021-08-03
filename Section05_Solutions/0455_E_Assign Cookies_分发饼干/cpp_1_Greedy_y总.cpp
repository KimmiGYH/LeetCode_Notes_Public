#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int res = 0;
        
        for (int i = 0, j = 0; i < g.size(); i ++) {
            while (j < s.size() && s[j] < g[i]) j ++;
            // if (j < s.size() && s[j] >= g[i]) { //可以直接省略写s[j] >= g[i]
            if (j < s.size()) {
                res ++;
                j ++;
            }
            else break;
        }        
        return res;
    }
};