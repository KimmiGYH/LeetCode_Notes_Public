#include <string>
using namespace std;

class Solution {
public:
    int longestBeautifulSubstring(string word) {
        string vowels = "aeiou";
        int res = 0, idx = vowels.size() - 1;
        for (int i = 0; i < word.size(); i ++) {
            if (word[i] != 'a') continue;
            int j = i, k = 0;
            while (j < word.size()) {
                if (word[j] == vowels[k]) j ++;
                else {
                    if (k == idx) break;
                    if (word[j] == vowels[k + 1]) j ++, k ++;
                    else break;
                }
                if (k == idx) res = max(res, j - i);
            }
            i = j - 1;
        }
        return res;
    }
};