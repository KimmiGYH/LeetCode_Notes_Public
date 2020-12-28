#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int i = 0; i < nums.size(); i++)
            freq[nums[i]]++;
        
        // 比较的应该是元素出现的频率，存入 pair<元素频率，元素>
        priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > heap;

        // iter 访问频率表（元素，元素频率）
        for(unordered_map<int,int>::iterator iter = freq.begin(); iter != freq.end(); iter++) {
            if (heap.size() == k) {
                if (iter->second > heap.top().first) {
                    heap.pop();
                    heap.push(make_pair(iter->second, iter->first));
                }
            } else
                heap.push(make_pair(iter->second, iter->first));
        }

        vector<int> res;
        while (!heap.empty()) {
            res.push_back(heap.top().second);
            heap.pop();
        }
        return res;
    }
};
