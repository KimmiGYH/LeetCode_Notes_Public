class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        string res;
        unordered_map<string, string> hash;
        for (vector<string>& path : paths) {
            hash[path[0]] = path[1];
        }
        for (auto& [k, v] : hash) {
            if (hash.find(v) == hash.end())
                res = v;
        }
        return res;
    }
};
