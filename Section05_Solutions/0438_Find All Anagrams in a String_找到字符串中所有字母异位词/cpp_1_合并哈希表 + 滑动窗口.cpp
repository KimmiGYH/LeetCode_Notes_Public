#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> cnt;
        for (auto c : p)  cnt[c]++;
        vector<int> res;
        int tot = cnt.size();
        for (int i = 0, j = 0, satisfy = 0; i < s.size(); i++) {
            // 左边每出现一个字符时 ++，右边每出现一个字符时 --
            cnt[s[i]]--;
            if (--cnt[s[i]] == 0)  satisfy++;
            // 因为是 -- 等于0，所以减之前必然大于0，大于0则表示当前字符在目标串里出现过
            while (i - j + 1 > p.size()) { // 区间大于目标串长度时 要删字符
                if (cnt[s[j]] == 0)  satisfy--;
                cnt[s[j++]]++;
            }
            if (satisfy == tot)  res.push_back(j);
        }
        return res;
    }
};  