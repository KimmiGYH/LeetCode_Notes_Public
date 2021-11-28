class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> res;
        int n = arr.size();
        vector<int> prexor(n);
        prexor[0] = arr[0];
        for (int i = 1; i < n; i++)
            prexor[i] = prexor[i-1] ^ arr[i];
        
        for (auto& query : queries) {
            int L = query[0], R = query[1];
            if (!L) res.push_back(prexor[R]);
            else    res.push_back(prexor[L-1] ^ prexor[R]);
        }
        return res;
    }
};
