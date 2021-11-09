class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<int> mask;
        for (auto word : words) {
            int s = 0;
            for (auto c : word)
                s |= 1 << (c - 'a');
            mask.push_back(s);
        }
        
        int res = 0;
        for (int i = 0; i < words.size(); i ++)
            // for (int j = i + 1; j < words.size(); j ++) //两种循环方式
            for (int j = 0; j < i; j ++)
                if ((mask[i] & mask[j]) == 0)
                    res = max(res, int(words[i].size() * words[j].size()));    
        return res;
    }    
};