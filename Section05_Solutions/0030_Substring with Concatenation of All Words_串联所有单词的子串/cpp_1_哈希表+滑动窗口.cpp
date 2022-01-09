class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if (words.empty()) return res;
        int n = s.size(), m = words.size(), w = words[0].size();
        unordered_map<string, int> tot; //给定的哈希表
        for (auto& word : words) tot[word]++;
        
        //做每组
        for (int i = 0; i < w; i++) {
            unordered_map<string, int> hash;//当前的哈希表，维护的是个窗口
            int satisfy = 0;
            for (int j = i; j + w <= n; j +=w) {
                if (j >= i + m * w) { //j是窗口右端点，当j超出窗口时删去左端点
                    string word = s.substr(j - m * w, w);
                    hash[word]--;
                    if (hash[word] < tot[word]) satisfy--; //hash中减掉的是有效单词
                }
                string word = s.substr(j, w);
                hash[word]++;
                if (hash[word] <= tot[word]) satisfy++;
                if (satisfy == m) res.push_back(j - (m - 1) * w);
            }
        }
        return res;
    }
};