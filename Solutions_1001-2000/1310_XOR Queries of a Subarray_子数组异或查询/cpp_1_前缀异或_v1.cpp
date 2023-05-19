class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> prexor(n);
        prexor[0] = arr[0];
        for (int i = 1; i < n; i++)
            prexor[i] = prexor[i-1] ^ arr[i];
        
        vector<int> res;
        for (int i = 0; i < queries.size(); i++) {
            int L = queries[i][0];
            int R = queries[i][1];
            if (L == 0)
                res.push_back(prexor[R]);
            else
                res.push_back(prexor[L-1] ^ prexor[R]);
        }
        return res;
    }
};
