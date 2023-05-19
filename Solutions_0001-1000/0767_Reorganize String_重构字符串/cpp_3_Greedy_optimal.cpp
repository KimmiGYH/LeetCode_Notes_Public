#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    string reorganizeString(string S) {
        int n = S.size(), idx = 1;
        vector<int> cnt(26);
        
        for (char& c : S) cnt[c - 'a'] += 100;
        for (int i = 0; i < 26; ++i) cnt[i] += i;
        sort(cnt.begin(), cnt.end());
        
        for (int num : cnt) {
            int t = num / 100;
            char ch = 'a' + (num % 100);
            
            if (t > (n + 1) / 2)  return "";
            for (int i = 0; i < t; ++i) {                
                if (idx >= n) idx = 0;
                S[idx] = ch;
                idx += 2;
            }
        }
        return S;
    }
};