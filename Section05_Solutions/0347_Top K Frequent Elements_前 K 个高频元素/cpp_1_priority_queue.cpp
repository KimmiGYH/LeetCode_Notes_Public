#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // 统计每个元素出现的频率
        unordered_map<int, int> freq;
        for (int i = 0; i < nums.size(); i++)
            freq[nums[i]]++;
        
        // 扫描 freq，维护当前出现频率最高的 k 个元素
        // 底层应该是个最小堆，以便 pop 掉频率最低的元素
        // 比较的应该是元素出现的频率，存入 pair<元素频率，元素>
        priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > heap;

        // iter 访问频率表 [元素，元素频率]
        for(unordered_map<int,int>::iterator iter = freq.begin(); iter != freq.end(); iter++) {
            if (heap.size() == k) {
                if (iter->second > heap.top().first) { // 如果大于优先队列中队首所对应的频率
                    heap.pop();
                    heap.push(make_pair(iter->second, iter->first));
                }
            } else // 如果没满
                heap.push(make_pair(iter->second, iter->first));
        }
        // 把优先队列中频率最高的 k 个元素放进 vector
        vector<int> res;
        while (!heap.empty()) {
            res.push_back(heap.top().second);
            heap.pop();
        }
        return res;
    }
};