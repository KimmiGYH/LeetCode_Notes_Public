class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        string res;
        unordered_set<string> hash;
        for (vector<string>& path : paths) {
            hash.insert(path[0]);
        }
        for (vector<string>& path : paths) {
            if (!hash.count(path[1]))
                return path[1];
        }
        return "";
    }
};
