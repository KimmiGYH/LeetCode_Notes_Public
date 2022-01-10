class Solution {
    using PII = pair<int, int>;
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        
        auto cmp = [&](const PII& x, const PII& y) {
            return arr[x.first] * arr[y.second] > arr[x.second] * arr[y.first];
        };
        
        priority_queue<PII, vector<PII>, decltype(cmp)> q(cmp);
        
        for (int j = 1; j < n; ++j)
            q.emplace(0, j);
        for (int _ = 1; _ < k; ++_) {
            auto [i, j] = q.top(); q.pop();
            if (i + 1 < j)
                q.emplace(i + 1, j);
        }
        return {arr[q.top().first], arr[q.top().second]};
    }
};