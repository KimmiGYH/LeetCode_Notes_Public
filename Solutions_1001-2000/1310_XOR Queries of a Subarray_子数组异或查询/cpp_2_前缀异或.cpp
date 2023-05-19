class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> prexor (n + 1);
        for (int i = 1; i <= n; i++)
            prexor[i] = prexor[i-1] ^ arr[i-1];
        
        vector<int> res;
        for (auto& query : queries) {
            int L = query[0], R = query[1];
            res.push_back(prexor[L] ^ prexor[R+1]);
        }
        return res;
    }
};
//这样写避免了下标 L-1 时 prexor 越界问题