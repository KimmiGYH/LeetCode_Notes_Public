class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> res;
        unordered_map<char, int> hash;
        
        string lines[3] = {
            "qwertyuiop",
            "asdfghjkl",
            "zxcvbnm"
        };
        for (int i = 0; i < 3; i++) {
            for (char& c : lines[i])
                hash[c] = i;
        }
        for (string& word : words) {
            set<int> S;
            for (char& c : word)
                S.insert(hash[tolower(c)]);//既有大写也有小写
            if (S.size() == 1)
                res.push_back(word);
        }
        return res;
    }
};
