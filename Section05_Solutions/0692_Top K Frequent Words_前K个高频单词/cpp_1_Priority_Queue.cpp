#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> freq;
        for (const string& word : words)
            freq[word]++;

        struct CompareString {
            bool operator()(pair<string,int>& a, pair<string,int>& b) {
                // a,b频数大的，优先级大；频数相等，字典序小的优先级大
                return (a.second > b.second || (a.second == b.second && a.first < b.first));
            }
        };

        priority_queue< pair<string, int>, vector<pair<string, int>>, CompareString> heap;

        // O(n*logk)
        for (const auto& kv : freq) {
            heap.push(kv);
            if (heap.size() > k) heap.pop();
        }

        vector<string> res;

        while (!heap.empty()) {
            res.push_back(heap.top().first);
            heap.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};