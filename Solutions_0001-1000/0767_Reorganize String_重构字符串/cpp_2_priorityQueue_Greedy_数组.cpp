#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string reorganizeString(string S) {
        string res;
        vector<int> cnt(26);
        
        for (char& c : S) ++cnt[c - 'a'];

        auto cmp = [&](char& letter1, char& letter2) { return cnt[letter1 - 'a'] < cnt[letter2 - 'a']; };
        priority_queue<char, vector<char>, decltype(cmp)> heap{ cmp };
        
        for (int i = 0; i < 26; ++i) {
            if (cnt[i] > (S.size() + 1) / 2) return "";
            if (cnt[i]) {
                char ch = i + 'a';
                heap.push(ch);
            }
        }
        
        while (heap.size() >= 2) {
            auto ch1 = heap.top(); heap.pop();
            auto ch2 = heap.top(); heap.pop();
            res += ch1;
            res += ch2;
            int idx1 = ch1 - 'a';
            int idx2 = ch2 - 'a';
            if (--cnt[idx1] > 0) heap.push(ch1);
            if (--cnt[idx2] > 0) heap.push(ch2);
        }
        if (!heap.empty()) res.push_back(heap.top());
        return res;        
    }
};
        /*
        // 用 lambda 比较元素。
        auto cmp = [](int left, int right) { return (left ^ 1) < (right ^ 1); };
        std::priority_queue<int, std::vector<int>, decltype(cmp)> q3(cmp); 
        */