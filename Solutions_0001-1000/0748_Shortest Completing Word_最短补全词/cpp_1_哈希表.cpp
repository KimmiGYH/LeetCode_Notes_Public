class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        unordered_map<char, int> cntlp;
        string res = "";

        for (char& c : licensePlate) {
            if (isalpha(c)) //或写成 if (c != ' ' && !isdigit(c))
                cntlp[tolower(c)] ++;
        }
        for (string& word : words) {
            unordered_map<char, int> cntword;
            for (char& w : word) cntword[w] ++;
            if (check(cntword, cntlp)) {
                if (res.empty() || res.size() > word.size())
                    res = word;
            }
        }
        return res;
    }

    bool check(unordered_map<char,int>& cntword, unordered_map<char,int>& cntlp) {
        // 要求cntlp里的元素全都要用上，枚举cntlp，避免cntword里的元素都不是cntlp里的
        for (auto& [key, val] : cntlp)
            if (cntword[key] < val)
                return false;
        return true;
    }
};
