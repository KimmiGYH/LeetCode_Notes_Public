#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> hash;
        vector<int> res;

        for (auto& c : p)  hash[c]++;
        int tot = hash.size();
        for (int i = 0, j = 0, satisfy = 0; j < s.size(); j++) {
            if (--hash[s[j]] == 0)  satisfy++;//每出现一个目标串中的字符就抵消1次，如果该字符被抵消为0，说明某个字符与目标串中的字符出现次数相同，匹配字符数加1
            while (j - i + 1 > p.size()) { //区间大于目标串长度时，要删字符
                if (hash[s[i]] == 0)  satisfy--; //如果删之前s[i]这个字符已被抵消为0了，删完就被恢复了一次，所以satisfy--，匹配字符数减1
                hash[s[i++]]++; //删之前是被抵消为0了，由于共用一个哈希表，所以删之后hash[s[i]]++表示该字母s[i]已被恢复，还需要匹配一次来抵消
            }
            if (satisfy == tot)  res.push_back(i);
        }
        return res;
    }
};
