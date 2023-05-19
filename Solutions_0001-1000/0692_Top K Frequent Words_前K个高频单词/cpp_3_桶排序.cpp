#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <set>

using namespace std;

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> res;
        unordered_map<string, int> freq;
        vector<set<string>> buckets(words.size() + 1, set<string>());
        for (string word : words)  freq[word]++;
        for (auto f : freq) {
            buckets[f.second].insert(f.first);
        }
        for (int i = buckets.size() - 1; i >= 0; i--) {
            if (buckets[i].size() == 0) continue;
            if (k <= 0)  break;
            vector<string> v(buckets[i].begin(), buckets[i].end());
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