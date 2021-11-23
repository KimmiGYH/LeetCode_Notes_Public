class Solution {
public:
    string customSortString(string order, string s) {
        string res = "";
        unordered_map<char, int> hash;
        for (char& c : s) ++hash[c];
        for (char& c : order) {
            res += string(hash[c], c);
            hash[c] = 0;
        }
        for (auto h : hash)
            res += string(h.second, h.first);
        return res;
    }
};