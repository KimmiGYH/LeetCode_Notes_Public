#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string reorganizeString(string S) {
        string res;
        unordered_map<char, int> hash;
        priority_queue<pair<int, char>> heap;
        for (char c : S) ++hash[c];
        for (auto item : hash) {
            if (item.second > (S.size() + 1) / 2) return "";
            heap.push({item.second, item.first});
        }
        while (heap.size() >= 2) {
            auto t1 = heap.top(); heap.pop();
            auto t2 = heap.top(); heap.pop();
            res.push_back(t1.second);
            res.push_back(t2.second);
            if (--t1.first > 0) heap.push(t1);
            if (--t2.first > 0) heap.push(t2);
        }
        if (!heap.empty()) res.push_back(heap.top().second);
        return res;        
    }
};