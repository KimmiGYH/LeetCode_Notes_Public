#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        typedef unsigned long long ULL;
        const int P = 131;
        unordered_set<ULL> hash;
        // 将所有单词变成数字放进哈希表
        for (auto& word : wordDict) {
            ULL h = 0;
            for (auto c : word) h = h * P + c;
            hash.insert(h);
        }
        
        int n = s.size();
        vector<bool> f(n + 1);
        f[0] = true;
        
        s = ' ' + s;
        for (int i = 0; i < n; i++) {
            if (f[i]) {
                    ULL h = 0;
                for (int j = i + 1; j <= n; j++) {
                    h = h * P + s[j];
                    if (hash.count(h)) f[j] = true;
                }
            }
        }
        return f[n];
    }
};