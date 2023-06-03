class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        priority_queue<pair<int, int>> pq;
        unordered_map<int, int> hash;
        for (int& x : nums)
            hash[x] ++;
        for (auto& item : hash) {
            pq.push({ item.second, item.first });
        }
        while (k--) {
            int t = pq.top().second;
            pq.pop();
            res.push_back(t);
        }
        return res;
    }
};

/*
for (auto iter = hash.begin(); iter != hash.end(); ++iter) {
            pq.push(make_pair(iter->second, iter->first));
        }
*/