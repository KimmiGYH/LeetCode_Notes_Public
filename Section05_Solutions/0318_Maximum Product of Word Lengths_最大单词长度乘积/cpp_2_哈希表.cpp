class Solution {
public:
    int maxProduct(vector<string>& words) {
        unordered_map<int, int> hash;
        int res = 0;
        for (const string& word : words) {
            int mask = 0, size = word.size();
            for (const char& c : word)
                mask |= 1 << (c - 'a'); //按位或并将赋值相加
            hash[mask] = max(hash[mask], size);
            
            for (const auto& [h_mask, h_len] : hash)
                if (!(mask & h_mask))
                    res = max(res, size * h_len);
        }
        return res;
    }
};