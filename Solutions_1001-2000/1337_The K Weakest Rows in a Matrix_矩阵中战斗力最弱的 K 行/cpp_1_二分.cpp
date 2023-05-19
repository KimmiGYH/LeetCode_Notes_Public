class Solution {
    using PII = pair<int, int>;
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();
        vector<int> res;
        priority_queue<PII, vector<PII>, greater<PII> > pq;
        
        for (int i = 0; i < m; ++i) {
            int l = 0, r = n - 1;
            while (l < r) {
                int mid = l + r + 1 >> 1;
                if (mat[i][mid] == 1) l = mid;
                else r = mid - 1;
            }
            if (mat[i][0] == 0) pq.push({0, i});
            else pq.push({l + 1, i});
        }
        
        while (k--) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};