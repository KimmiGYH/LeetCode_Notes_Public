#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int res = 0, partlen = n + 1;
        unordered_map<char, int> hash;
        priority_queue<int> heap;
        for (char& c : tasks) ++hash[c];
        for (auto& item : hash)  heap.push(item.second); // heap:{4,3,2,2,2}
        while (!heap.empty()) {
            int cnt = 0;
            vector<int> vec;
            for (int i = 0; i < partlen; ++i) {
                if (!heap.empty()) {
                    vec.push_back(heap.top()); heap.pop();
                    ++cnt;
                }
            }
            for (int d : vec)
                if(--d > 0) heap.push(d);
            
            res += heap.empty() ? cnt : partlen;
        }
        return res;
    }
};