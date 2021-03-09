#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> stk;
        
        for (auto& c : s) {
            if (stk.empty() || c != stk.top().first)
                stk.push({c, 1});
            else
                stk.push({c, stk.top().second + 1});
            
            if (stk.top().second == k)
                for (int i = 0; i < k; i++) stk.pop();
        }     
        
        string res;
        while (!stk.empty()) {
            res.push_back(stk.top().first);
            stk.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};