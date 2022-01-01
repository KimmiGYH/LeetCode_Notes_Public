class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> res;
        if (m * n != original.size())
            return {};
        for (auto it = original.begin(); it != original.end(); it += n)
            res.emplace_back(it, it + n);
        return res;
    }
};