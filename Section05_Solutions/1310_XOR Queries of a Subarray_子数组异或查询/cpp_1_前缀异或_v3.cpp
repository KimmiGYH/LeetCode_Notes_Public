class Solution {
    vector<int> prexor;
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        prexor = arr;
        for (int i = 1; i < arr.size(); i++)
            prexor[i] ^= prexor[i-1];
        
        vector<int> res;
        for (auto& query : queries) {
            int L = query[0], R = query[1];
            if (!L) res.push_back(prexor[R]);
            else    res.push_back(prexor[L-1] ^ prexor[R]);
        }
        return res;
    }
};
