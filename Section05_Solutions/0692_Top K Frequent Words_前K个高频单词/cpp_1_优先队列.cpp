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
                // 【minHeap】让频率小的词在前面 || 频率相同时，让字母顺序大的排在前面
                return (a.second > b.second || (a.second == b.second && a.first < b.first));
            }
        };

        priority_queue< pair<string, int>, vector<pair<string, int>>, CompareString> heap;

        // O(n*logk)
        for (const auto& f : freq) {
            heap.push(f);
            if (heap.size() > k) heap.pop(); // 把小的全都 pop 掉
        }

        /* 写法一：reverse
        vector<string> res;
        while (!heap.empty()) {
            res.push_back(heap.top().first);
            heap.pop();            
        }
        reverse(res.begin(), res.end());
        */
        /* 写法二：insert 
        vector<string> res;
        while (!heap.empty()) {
            auto it = res.begin();
            it = res.insert(it, heap.top().first);
            heap.pop();
        }
        */
        /* 写法三：递减循环*/
        vector<string> res(k);
        for (int i = res.size() - 1; i >= 0; --i) {
            res[i] = heap.top().first;
            heap.pop();
        }
        return res;
    }
};