#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int max_freq = 1;
        for (const int num : nums)
            max_freq = max(max_freq, ++freq[num]);
        unordered_map<int, vector<int>> buckets; // buckets[次数，{对应的元素}]
        for (const auto& kv : freq) // kv [元素，元素频率]
            buckets[kv.second].push_back(kv.first);
        vector<int> res;
        for (int i = max_freq; i >= 1; i--) {
            auto iter = buckets.find(i); // find 返回指向首个满足条件的迭代器
            if (iter == buckets.end())  continue;
            res.insert(res.end(), iter->second.begin(), iter->second.end());
            if (res.size() == k)  return res;
        }
        return res;
    }
};