class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hash;
        vector<vector<string>> res;
        for (string& str : strs) {
            string nstr = str;
            sort(nstr.begin(), nstr.end());
            hash[nstr].push_back(str);
        }
        for (auto& [k, v] : hash)   //for (auto& item : hash)
            res.push_back(v);       //  res.push_back(item.second);
        return res;
    }
};

// ---------------------------------------------------------------
// 另外的写法

        for (auto it = hash.begin(); it != hash.end(); ++it) {
                    ans.emplace_back(it->second);
                }
