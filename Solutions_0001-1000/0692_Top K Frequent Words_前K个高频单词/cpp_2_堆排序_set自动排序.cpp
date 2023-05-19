#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <map>
#include <set>

using namespace std;

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> res;
        unordered_map<string, int> freq;
        map<int, set<string>> m;
        for (string word : words)  ++freq[word];
        for (auto a : freq) {
            m[a.second].insert(a.first); // 将freq里的string加到map的set中
        }
        for (auto it = m.rbegin(); it != m.rend(); ++it) {
            if (k <= 0)  break;
            auto t = it->second; // 从后面取pair里的string，即取次数最大的单词
            vector<string> v(t.begin(), t.end());
            if (k >= v.size()) {
                res.insert(res.end(), v.begin(), v.end());
            } else {
                res.insert(res.end(), v.begin(), v.begin() + k);
            }
            k -= v.size();
        }
        return res;
    }
};