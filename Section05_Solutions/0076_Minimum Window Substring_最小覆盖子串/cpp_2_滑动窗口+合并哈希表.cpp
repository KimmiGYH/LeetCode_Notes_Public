#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> hash;
        int cnt = 0;
        for (auto c : t)
        {
            if (!hash[c]) cnt ++ ;
            hash[c]++ ;
        }

        string res = "";
        for (int i = 0, j = 0, c = 0; i < s.size(); i ++ )
        {
            if (hash[s[i]] == 1)  c++;
            // 窗口中的所有字符，每出现一次，就在哈希表中减 1 
            hash[s[i]]--;
            // 当从窗口中删除一个字符的时候，就加1。
            // j++表示将 j 从窗口中删除。
            while (c == cnt && hash[s[j]] < 0)
                hash[s[j++]]++;
            if (c == cnt)
            {
                if (res.empty() || res.size() > i - j + 1)
                    res = s.substr(j, i - j + 1);
            }
        }
        return res;
    }
};
